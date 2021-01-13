//
// Created by Abdusalam Yabrak on 2021-01-05.
//

#ifndef EXTENTOR_CHECKEDVALUE_H
#define EXTENTOR_CHECKEDVALUE_H

#include <stdexcept>

template<typename T, typename Check>
class CheckedValue {
public:
    CheckedValue(const T &v) noexcept(false) { set(v); }

    T get() const { return value; }

    void set(const T &v) noexcept(false) {
        if (!check(v)) {
            throw std::logic_error("Value error");
        }
        value = v;
    }

private:
    T value;
    Check check;
};

struct pos {
    bool operator()(int x) const {
        return x >= 0;
    }
};

template <int n>
struct long_string {
    bool operator()(const std::string &s) const {
//        return s.length() > n;
        return false;
    }
};
#endif //EXTENTOR_CHECKEDVALUE_H
