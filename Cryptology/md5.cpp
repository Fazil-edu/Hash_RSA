#include "md5.h"
#include <string>
#include <bitset>
#include <QtMath>
#include <sstream>
#include <iostream>
#include <string>
#include <cstdio>

MD5::MD5(std::string input)
{
    this->toHash = input;
    Hash();
}

void MD5::setBitsOfTheInputString(){
    this->lengthOfInput = toHash.length();
    for (auto letter : this->toHash) {
            binaryData.append(std::bitset<8>(letter).to_string());
        }
}

void MD5::paddingInTheInputString(){

    std::string lengthOfBinaryData = std::bitset<64>(binaryData.length()).to_string();
    int numberOfZeros =0;

    if(binaryData.length() - 512*(binaryData.length() / 512) <= 440){
        numberOfZeros = 447 - (binaryData.length() - 512*(binaryData.length() / 512));
    }
    else {
        numberOfZeros =511-( binaryData.length() - 512*(binaryData.length()/512)) + 448;
    }
    binaryData+="1";
    for(int i = 0; i < numberOfZeros; i++){
        binaryData+="0";
    }

    binaryData+=lengthOfBinaryData;
}



void MD5::setBlocksOfPaddedInput(){

    int numberOfBlocks = this->binaryData.length()/512;
    for(int i = 0; i < numberOfBlocks; i++){
        std::array<unsigned long, 16> currentArray;
        int cnt_currentElement = 0;
        for(int j = 0; j<512; j+=32){
            currentArray[cnt_currentElement] = findBinaryCombination(binaryData.substr(j, 32));
            cnt_currentElement++;
        }
        binaryData.erase(0,512);
        this->blocks.push_back(currentArray);
    }

    this->blocks[numberOfBlocks-1][15] = 0;
    this->blocks[numberOfBlocks-1][14] = this->lengthOfInput*8;
}

unsigned long MD5::findBinaryCombination(std::string bits){
    unsigned int firstPartOfBits = findTheUnsignedLongIntegerOfBits(bits.substr(0,8));
    unsigned int secondPartOfBits = findTheUnsignedLongIntegerOfBits(bits.substr(8,8));
    unsigned int thirdPartOfBits = findTheUnsignedLongIntegerOfBits(bits.substr(16,8));
    unsigned int fourthPartOfBits = findTheUnsignedLongIntegerOfBits(bits.substr(24,8));

    return (firstPartOfBits | secondPartOfBits << 8 | thirdPartOfBits << 16 | fourthPartOfBits << 24);
}

void MD5::fillK(){
    unsigned long long coefficient = qPow(2,32);
    for(int i = 0; i < 64; i++){
        K[i] = qFabs(qSin(i+1))* coefficient;
    }
}

unsigned long MD5:: lefRotate(unsigned long X, int operation){
    std::string rotated = findBitsOfAnUnsignedLongInteger(X);
    std::string str = std::bitset<8>(128).to_string();
    std::string tmp_1 = rotated.substr(0, operation);
    std::string tmp_2 = rotated.substr(operation, rotated.length());
    rotated = tmp_2 + tmp_1;
    return findTheUnsignedLongIntegerOfBits(rotated);
}

std::string MD5::findBitsOfAnUnsignedLongInteger(unsigned long X){
    std::string output;
    int quotient = 1;
    int rest;
    while (quotient != 0)
    {
        quotient = (X / 2);
        rest = X % 2;
        output += std::to_string(rest);
        X = (X - rest) / 2;
    }

    int missingZeros = 32-output.length();
    for(int i = 0; i < missingZeros; i++){
        output+= "0";
    }
    std::reverse(output.begin(), output.end());
    return output;
}

int MD5::findTheBitValue(std::string i){
    if(i == "1"){
        return 1;
    }
    else{
        return 0;
    }
}

unsigned long MD5:: findTheUnsignedLongIntegerOfBits(std::string bits){
    unsigned long number = 0;
    for(int i = bits.length() - 1; i > -1; i--){
        number+=qPow(2,i) *findTheBitValue(bits.substr(bits.length() - i -1,1)) ;
    }
    return number;
}


int MD5::findTheRotationNumber(int round, int operation){

    if(round == 0){
        if(operation == 1 | operation == 5 | operation == 9 | operation == 13){
            return 7;
        }
        if(operation == 2 | operation == 6 | operation == 10 | operation == 14){
            return 12;
        }

        if(operation == 3 | operation == 7 | operation == 11 | operation == 15){
            return 17;
        }

        if(operation == 4 | operation == 8 | operation == 12 | operation == 16){
            return 22;
        }
    }

    if(round == 1){
        if(operation == 17 | operation == 21 | operation == 25 | operation == 29){
            return 5;
        }
        if(operation == 18 | operation == 22 | operation == 26 | operation == 30){
            return 9;
        }

        if(operation == 19 | operation == 23 | operation == 27 | operation == 31){
            return 14;
        }

        if(operation == 20 | operation == 24 | operation == 28 | operation == 32){
            return 20;
        }
    }

    if(round == 2){
        if(operation == 33 | operation == 37 | operation == 41 | operation == 45){
            return 4;
        }
        if(operation == 34 | operation == 38 | operation == 42 | operation == 46){
            return 11;
        }

        if(operation == 35 | operation == 39 | operation == 43 | operation == 47){
            return 16;
        }

        if(operation == 36 | operation == 40 | operation == 44 | operation == 48){
            return 23;
        }
    }

    if(round == 3){
        if(operation == 49 | operation == 53 | operation == 57 | operation == 61){
            return 6;
        }
        if(operation == 50 | operation == 54 | operation == 58 | operation == 62){
            return 10;
        }

        if(operation == 51 | operation == 55 | operation == 59 | operation == 63){
            return 15;
        }

        if(operation == 52 | operation == 56 | operation == 60 | operation == 64){
            return 21;
        }
    }
    return 0;
}

unsigned long MD5::modularAddition(unsigned long &x, unsigned long &y){
    unsigned long long coefficient = qPow(2,32);
    return (x+y) % coefficient;
}

unsigned long MD5::F(unsigned long B, unsigned long C, unsigned long D){
    return (B & C) | (~B & D);
}

unsigned long MD5::G(unsigned long B, unsigned long C, unsigned long D){
    return (B & D) | (C & ~D);
}

unsigned long MD5::H(unsigned long B, unsigned long C, unsigned long D){
    return B ^ C ^ D;
}

unsigned long MD5::I(unsigned long B, unsigned long C, unsigned long D){
    return C ^ (B | ~D);
}



void MD5::Hash(){
    setBitsOfTheInputString();
    paddingInTheInputString();
    setBlocksOfPaddedInput();
    fillK();

    for(int block = 0; block < this->blocks.size(); block++){
        this->A = this->OIV_A;
        this->D = this->OIV_D;
        this->C = this->OIV_C;
        this->B = this->OIV_B;
        for(int round = 0; round < 4; round++){
            for(int element = 0; element < 16; element++){
                if(round == 0){
                    unsigned long f = F(this->B,this->C, this->D);
                    f = modularAddition(this->A, f);
                    f = modularAddition(blocks[block][this->M[round*16 + element]], f);
                    f = modularAddition(this->K[round*16 + element], f);
                    int rotationNumber = findTheRotationNumber(round,round*16 + element+1);
                    f = lefRotate(f,rotationNumber);
                    f = modularAddition(this->B, f);
                    this->A = this->D;
                    this->D = this->C;
                    this->C = this->B;
                    this->B = f;
                }
                else {
                    if(round == 1){
                        unsigned long g = G(this->B,this->C, this->D); // OK
                        g = modularAddition(this->A, g);
                        g = modularAddition(blocks[block][this->M[round*16 + element]], g);
                        g = modularAddition(this->K[round*16 + element], g);
                        int rotationNumber = findTheRotationNumber(round,round*16 + element+1);
                        g = lefRotate(g,rotationNumber);
                        g = modularAddition(this->B, g);
                        this->A = this->D;
                        this->D = this->C;
                        this->C = this->B;
                        this->B = g;
                    }
                    else{
                        if(round == 2){
                            unsigned long h = H(this->B,this->C, this->D);
                            h = modularAddition(this->A, h);
                            h = modularAddition(blocks[block][this->M[round*16 + element]], h);
                            h = modularAddition(this->K[round*16 + element], h);
                            int rotationNumber = findTheRotationNumber(round,round*16 + element+1);
                            h = lefRotate(h,rotationNumber);
                            h = modularAddition(this->B, h);
                            this->A = this->D;
                            this->D = this->C;
                            this->C = this->B;
                            this->B = h;
                        }
                        else{
                            if(round == 3){
                                unsigned long i = I(this->B,this->C, this->D);
                                i = modularAddition(this->A, i);
                                i = modularAddition(blocks[block][this->M[round*16 + element]], i);
                                i = modularAddition(this->K[round*16 + element], i);
                                int rotationNumber = findTheRotationNumber(round,round*16 + element+1);
                                i = lefRotate(i,rotationNumber);
                                i = modularAddition(this->B, i);
                                this->A = this->D;
                                this->D = this->C;
                                this->C = this->B;
                                this->B = i;
                            }
                        }
                    }
                }
            }
        }
        this->OIV_A = modularAddition(this->OIV_A, this->A);
        this->OIV_B = modularAddition(this->OIV_B, this->B);
        this->OIV_C = modularAddition(this->OIV_C, this->C);
        this->OIV_D = modularAddition(this->OIV_D, this->D);
    }



    std::array<unsigned long, 16> state;
    state[0] = this->OIV_A;
    state[1] = this->OIV_B;
    state[2] = this->OIV_C;
    state[3] = this->OIV_D;
    encode(state);
}

void MD5::encode(std::array<unsigned long, 16> state)
{
    std::array<unsigned long, 16> output;
    for (int i = 0, j = 0; j < 16; i++, j += 4) {
        output[j] = state[i] & 0xff;
        output[j + 1] = (state[i] >> 8) & 0xff;
        output[j + 2] = (state[i] >> 16) & 0xff;
        output[j + 3] = (state[i] >> 24) & 0xff;
    }

    hexdigest(output);
}

void MD5::hexdigest(std::array<unsigned long, 16> lol)
{
    char buf[33];
    for (int i = 0; i < 16; i++)
        sprintf(buf + i * 2, "%02x", lol[i]);
    buf[32] = 0;

    this->hashValueOfInput = std::string(buf);
}

