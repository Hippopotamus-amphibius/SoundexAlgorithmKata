//
// Created by brettmcrae on 12/13/2018.
//

#ifndef SOUNDEXALGORITHMKATA_SOUNDEX_H
#define SOUNDEXALGORITHMKATA_SOUNDEX_H

#include <iostream>
#include <string>
using namespace std;

class Soundex
{
    string zeroPad(const string& word) const;
public:
    string encode(const string& word) const;
};

#endif //SOUNDEXALGORITHMKATA_SOUNDEX_H
