#ifndef MD5_H
#define MD5_H
#include <string>
#include <list>
#include <array>
#include <vector>


class MD5
{
public:
    MD5(std::string input);
    MD5();
public:
    std::string toHash;
    std::string hashValueOfInput = "";
    unsigned long long lengthOfInput;  // 0 to 18.446.744.073.709.551.615
    std::string binaryData;
    std::vector<std::array<unsigned long, 16>> blocks;

    std::string result;

    unsigned long OIV_A = 1732584193; // prime
    unsigned long OIV_B = 4023233417; // 7 * 47 * 193 * 63361
    unsigned long OIV_C = 2562383102; // 2 * 29 * 44179019
    unsigned long OIV_D = 271733878; // 2 * 13 * 881 * 11863

    unsigned long A = 1732584193; // prime
    unsigned long B = 4023233417; // 7 * 47 * 193 * 63361
    unsigned long C = 2562383102; // 2 * 29 * 44179019
    unsigned long D = 271733878; // 2 * 13 * 881 * 11863
    std::array<unsigned long, 64> K;

    std::array<int, 64> M = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
                             1,6,11,0,5,10,15,4,9,14,3,8,13,2,7,12,
                             5,8,11,14,1,4,7,10,13,0,3,6,9,12,15,2,
                             0,7,14,5,12,3,10,1,8,15,6,13,4,11,2,9};

    void encode(std::array<unsigned long, 16> state);
    void hexdigest(std::array<unsigned long, 16> lol);

    void setBitsOfTheInputString();
    void paddingInTheInputString();
    void setBlocksOfPaddedInput();
    void fillK();
    std::string findBitsOfAnUnsignedLongInteger(unsigned long X);
    unsigned long findTheUnsignedLongIntegerOfBits(std::string bits);
    unsigned long findBinaryCombination(std::string bits);
    unsigned long F(unsigned long A, unsigned long B, unsigned long C);
    unsigned long G(unsigned long A, unsigned long B, unsigned long C);
    unsigned long H(unsigned long A, unsigned long B, unsigned long C);
    unsigned long I(unsigned long A, unsigned long B, unsigned long C);
    unsigned long modularAddition(unsigned long &x, unsigned long &y);
    unsigned long convertFromBinaryToDecimal(std::string binary);
    int findTheBitValue(std::string i);
    unsigned long lefRotate(unsigned long X, int operation);

    int findTheRotationNumber(int round, int operation);

    void Hash();
};

#endif // MD5_H
