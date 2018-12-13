//
// Created by brettmcrae on 12/13/2018.
//

#ifndef SOUNDEXALGORITHMKATA_SOUNDEX_H
#define SOUNDEXALGORITHMKATA_SOUNDEX_H

#include <iostream>
#include <string>
using namespace std;
static const size_t MaxCodeLength{4};

class Soundex
{
    string zeroPad(const string& word) const;
    string head(const string& word) const;
    string encodeDigits(const string& word) const;
    char encodeDigit(char letter) const;
public:
    string encode(const string& word) const;
};

#endif //SOUNDEXALGORITHMKATA_SOUNDEX_H
