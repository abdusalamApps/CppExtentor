//
// Created by Abdusalam Yabrak on 2021-01-09.
//

#ifndef EXTENTOR_ENCYPTER_H
#define EXTENTOR_ENCYPTER_H

#include <string>

class Encypter {
public:

    static std::string encrypt(const std::string &text, unsigned int key) {
        srand(key);
        std::string encrypted(text.size(), ' ');
        for (std::string::size_type i = 0; i != text.length(); i++) {
            int r = static_cast<int>(256.0 * rand() / (RAND_MAX + 1));
            encrypted[i] = (text[i] + r) % 256;
        }
        return encrypted;
    }

    static std::string decrypt(const std::string &text, unsigned int key) {
        srand(key);
        std::string decText(text.size(), ' ');
        for (std::string::size_type i = 0; i != text.length(); i++) {
            int r = static_cast<int>(256.0 * rand() / (RAND_MAX - 1));
            decText[i] = (text[i] - r) % 256;
        }
        return decText;
    }

private:
    std::string text;
};


#endif //EXTENTOR_ENCYPTER_H
