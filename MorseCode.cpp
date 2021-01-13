//
// Created by Abdusalam Yabrak on 2020-12-31.
//

#include <iostream>
#include <sstream>
#include "MorseCode.h"
#include "fstream"

MorseCode::MorseCode(const std::string &fileName) {
    std::ifstream file{fileName};
    std::string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            char letter = line.at(0);
            std::string code = line.substr(2);
//            std::cout << "letter: " << letter << ", code: " << code << "\n";

            encodeMap.insert(std::make_pair(toupper(letter), code));
            decodeMap.insert(std::make_pair(code, toupper(letter)));
        }
    }
}

std::string MorseCode::encode(const std::string &s) {
    std::string result;

    for (char i : s) {
        auto cit = encodeMap.find(toupper(i));
        if (cit != encodeMap.end()) {
            result += cit->second + " ";
        }
    }
    return result;
}

std::string MorseCode::decode(const std::string &s) {

    std::string result;
    std::stringstream stream{s};
    std::string ts;
    while (stream >> ts) {
        auto cit = decodeMap.find(ts);
        if (cit != decodeMap.end()) {
            result += cit->second;
        } else {
            result += "?";
        }
    }
    return result;
}

