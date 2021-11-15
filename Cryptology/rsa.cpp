#include "rsa.h"
#include <QtMath>
#include <random>
#include <ctime>
#include <QString>


RSA::RSA(std::string input)
{
    this->input = input;
    this->encryptTheMessage();
}
RSA::RSA(){

}


void RSA::decryptTheMessage(uint64_t privateKey, std::vector<uint64_t> encryptedValues){
    this->decryptedValueOfTheMessage = "Decrypted values of the encrypted values:\n";
    std::string tmp;
    for(int i=0; i<encryptedValues.size(); i++){
        tmp+=decryptThePartOfMessage(encryptedValues[i],privateKey);
        this->decryptedValueOfTheMessage += std::to_string(decryptThePartOfMessage(encryptedValues[i],privateKey))  +" ";
    }

    this->decryptedValueOfTheMessage = this->decryptedValueOfTheMessage + "\nThe message in plaintext:\n" + tmp;
}

uint64_t RSA::decryptThePartOfMessage(unsigned long long m, uint64_t privateKey){
    uint64_t a = m;
    for(uint64_t i = 0; i < privateKey-1; i++){
        a *= m;
        a %= this->N;
    }
    return a%this->N ;
}

void RSA::generatePublicKey(){
    std::vector<unsigned long long> gcd_ones ;
    for(unsigned long long publicKeyCandidate = 3; publicKeyCandidate < this->phi_N; publicKeyCandidate+=2){
        if(euclidianAlgorithm(publicKeyCandidate) == 1){
            gcd_ones.push_back(publicKeyCandidate);
        }
    }
    srand(time(NULL)); // it is necessary for a random number
    this->e = gcd_ones[rand() % (gcd_ones.size() - 2) + 2]; // it gives a random number between 2 and gcd_ones.size()
}

void RSA::encryptTheMessage(){
    this->generatePublicKey();
    this->findPrivateKey();
    this->encryptedValueOfTheMessage ="ASCII values of the message:\n";
    for(auto letter:this->input){
        int tmp = letter;
        this->encryptedValues.push_back(this->encryptThePartOfMessage(letter));
        this->encryptedValueOfTheMessage+= std::to_string(tmp) + " ";
    }
    this->encryptedValueOfTheMessage += "\n";
    this->encryptedValueOfTheMessage =this->encryptedValueOfTheMessage + "Encrypted values of the ASCII values:\n";

    for(auto letter:this->input){
        this->encryptedValueOfTheMessage+= std::to_string((this->encryptThePartOfMessage(letter))) + " " ;
    }
}
uint64_t RSA::encryptThePartOfMessage(unsigned long long m){
    uint64_t a = m;
    for(uint64_t i = 0; i < this->e-1; i++){
        a *= m;
        a %= this->N;
    }
    return a%this->N ;
}



void RSA::findPrivateKey(){
    this->extendedEuclidianAlgorithm();
}

unsigned long long RSA::euclidianAlgorithm(unsigned long long publicKeyCandidate){
    unsigned long long an_1 = this->phi_N ;
    unsigned long long an_2 = publicKeyCandidate ;
    unsigned long long qn = an_1 / an_2;
    unsigned long long rn = an_1 % an_2; // it is an. The last an or rn which is not zero is gcd
    unsigned long long gcd  = an_2;

    if(rn == 0){
        return gcd; // here is gcd = publicKeyCandidate
    }
    else{
        while (rn != 0) {
            an_1 = rn; // here rn equals rn_1 because we haven't calculated the current rn yet
            qn = an_2 / rn; // here rn equals rn_1 because we haven't calculated the current rn yet. But qn is the current qn, see below rn
            gcd = rn; // here rn equals rn_1 because we haven't calculated the current rn yet
            rn = an_2 - qn*an_1;
            an_2 = an_1;
        }
    }
    return gcd;
}

void  RSA::extendedEuclidianAlgorithm(){
    unsigned long long an_1 = this->phi_N;
    unsigned long long an_2 = this->e;
    unsigned long long qn = an_1 / an_2;
    unsigned long long rn = an_1 % an_2; // it is an.
    unsigned long long dn=-qn; // e3

    unsigned long long dn_2 = 1; // e2
    unsigned long long dn_1 = -qn; // e3
    long long d = 0;

    while (rn != 0) {
        an_1 = rn;
        qn = an_2 / rn; // here rn equals rn_1 because we haven't calculated the current rn yet
        d = dn;
        dn = dn_2 - qn*dn_1;
        dn_2 = dn_1;
        dn_1 = dn;
        rn = an_2 - qn*an_1;
        an_2 = an_1;
    }

    if(d > 0){
        this->d = d;
    }
    else{
        this->d = this->phi_N + d;
    }
}



