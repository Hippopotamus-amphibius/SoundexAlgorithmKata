//
// Created by hugovalle1 on 12/13/2018.
//
#include <unordered_map>
#include "Soundex.h"
/**
 * @brief pad word to 4 digits
 * @param word - input string
 * @return - padded string
 */
string Soundex::zeroPad(const string& word)const
{
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + string(zerosNeeded, '0');
}

/**
 * @brief Encode string to Soundex Algorithm
 * @param word - string to code
 * @return - encoded string
 */
string Soundex::encode(const string& word) const
{
    auto encodedDigits = encodeDigits(tail(word));
    return zeroPad(head(word) + encodedDigits);
}

/**
 * @brief Extract the first char of the string
 * @param word - input string
 * @return - first letter of string "head"
 */
string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

/**
 * @brief Return all but the first character
 * @param word - input string
 * @return string from 1:END
 */
string Soundex::tail(const string &word) const {
    return word.substr(1);
}

/**
 * @brief Encode the string into digits using Soundex Algorithm
 * @param word - input string
 * @return - encoded string
 */
string Soundex::encodeDigits(const string &word) const
{
    string encoding = "";
    for (auto letter : word)
    {
        if (isComplete(encoding)) break;
        if (encodeDigit(letter) != lastDigit(encoding)) {
            encoding += encodeDigit(letter);
        }
    }
    return encoding;
}

/**
 * @brief Encode single digit
 * @return - encoded digit
 */
string Soundex::encodeDigit(char letter) const
{
    switch(letter)
    {
        case 'b':  case 'f':  case 'p':  case 'v':
            return "1";
        case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z':
            return "2";
        case 'd': case 't':
            return "3";
        case 'l':
            return "4";
        case 'm': case 'n':
            return "5";
        case 'r':
            return "6";
        default:
            return "";
    }
}

bool Soundex::isComplete(const string& encoding) const {
    return encoding.length() >= MaxCodeLength - 1;
}

string Soundex::lastDigit(const string& encoding) const {
    if (encoding.empty()) return "";
    return std::string(1, encoding.back());
}


