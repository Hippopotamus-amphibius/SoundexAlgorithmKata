//
// Created by brettmcrae on 12/13/2018.
//

#include "Soundex.h"

/**
  * @brief pad word to 4 digits
  * @param word - input string
  * @return padded string
  */
string Soundex::zeroPad(const string& word) const
{
    auto zerosNeeded = 4 - word.length();
    return word + string(zerosNeeded, '0');
}

/**
  * @brief Encode string to Soundex Algorith
  * @param word - string to encode
  * @return encoded string
  */
string Soundex::encode(const string& word) const
{
    auto encoded = word.substr(0, 1);
    if (word.length() > 1)
    {
        encoded += "1";
    }
    return zeroPad(encoded);
}