//
// Created by Abdusalam Yabrak on 2020-12-31.
//

#ifndef EXTENTOR_MORSECODE_H
#define EXTENTOR_MORSECODE_H


#include <string>
#include <map>

class MorseCode {
public:
    MorseCode(const std::string &fileName);
    std::string encode(const std::string &s);
    std::string decode(const std::string &s);

private:
    std::map<char, std::string> encodeMap;
    std::map<std::string, char> decodeMap;
};


#endif //EXTENTOR_MORSECODE_H
