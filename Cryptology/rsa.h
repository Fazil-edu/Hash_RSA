#ifndef RSA_H
#define RSA_H
#include <array>
#include <vector>

class RSA
{
public:
    RSA(std::string input);
    RSA();
    void extendedEuclidianAlgorithm();
    unsigned long long euclidianAlgorithm(unsigned long long publicKeyCandidate);
    std::string encryptedValueOfTheMessage;
    std::string decryptedValueOfTheMessage;
    void decryptTheMessage(uint64_t privateKey, std::vector<uint64_t> encryptedValues);
private:
    unsigned long long p = 71;
    unsigned long long q = 47;
    unsigned long long phi_N = (p-1)*(q-1);

    std::string input;
    void generatePublicKey();
    void findPrivateKey();
    void encryptTheMessage();
    unsigned long long encryptThePartOfMessage(unsigned long long m);
    unsigned long long decryptThePartOfMessage(unsigned long long m,uint64_t privateKey);



public:
    unsigned long long e; // public key
    const unsigned long long N = p * q;
    unsigned long long d; // private key
    std::vector<uint64_t> encryptedValues;
};

#endif // RSA_H
