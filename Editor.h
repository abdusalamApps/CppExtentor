
//created by Abdusalam Yabrak on 2021-01-01.


#ifndef EXTENTOR_EDITOR_H
#define EXTENTOR_EDITOR_H

#include "string"

class Editor {
public:
    Editor(const std::string &s) : text{s} {}

    std::string::size_type find_left_par(std::string::size_type pos) const {
        char rightPar = text.at(pos);
        char leftPar;
        switch (rightPar) {
            case ')':
                leftPar = '(';
                break;
            case ']':
                leftPar = '[';
                break;
            case '}':
                leftPar = '{';
                break;
            default:
                leftPar = ' ';
        }
        int level = 0;
        std::string::size_type index = pos - 1;
        while (index > 0) {
            if (text.at(index) == rightPar) {
                level++;
            } else if (text.at(index) == leftPar && level == 0) {
                return index;
            } else if (text.at(index) == leftPar && level != 0) {
                level--;
            }
            index--;
        }
        return -1;
    }

private:
    std::string text;
};


#endif //EXTENTOR_EDITOR_H
