//
// Created by Abdusalam Yabrak on 2021-01-05.
//

#ifndef EXTENTOR_NAMELIST_H
#define EXTENTOR_NAMELIST_H


#include <string>
#include <set>
#include <iostream>

struct StringPtrLess {
    bool operator()(const std::string *ps1, const std::string *ps2) {
        return *ps1 < *ps2;
    }
};

class NameList {
public:
    NameList() {}

    ~NameList() {}

    void insert(const std::string &name) {
        names.insert(new std::string(name));
    }

    void printSorted() const {
        for (list_type::const_iterator it = names.begin(); it != names.end(); ++it) {
            std::cout << **it << std::endl;
        }
    }

private:
    typedef std::set<std::string *, StringPtrLess> list_type;
    list_type names;
};

#endif //EXTENTOR_NAMELIST_H
