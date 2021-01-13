//
// Created by Abdusalam Yabrak on 2021-01-01.
//

#include "string_view.h"

string_view::string_view() : str{nullptr}, sz{0} {

}

string_view::string_view(std::string &s) : str{s.c_str()}, sz{s.size()} {

}

string_view::string_view(const std::string &s,
                         string_view::size_type pos,
                         string_view::size_type len) {

    if (pos + len > s.size()) throw std::out_of_range("string view");
    str = s.data() + pos;
    sz = len;
}

string_view::string_view(const char *c, string_view::size_type len)
        : str{c}, sz{len} {

}

string_view::string_view(const char *c) : str{c}, sz{std::strlen(c)} {

}

bool string_view::empty() const {
    return sz == 0;
}

string_view::size_type string_view::size() const {
    return sz;
}

string_view::const_iterator string_view::begin() const {
    return str;
}

string_view::const_iterator string_view::end() const {
    return str + sz;
}

const char &string_view::operator[](string_view::size_type index) const {
    return str[index];
}

const char &string_view::at(string_view::size_type pos) const {
    if (pos >= sz) throw std::out_of_range("string view::at");
    return (*this)[pos];
}

string_view string_view::substr(string_view::size_type pos) const {
    return substr(pos, sz);
}

string_view string_view::substr(string_view::size_type pos, string_view::size_type len) const {
    if (pos >= sz) throw std::out_of_range("size view::substr");
    const auto end = std::min(pos + len, sz);
    return string_view(str + pos, end - pos);
}

string_view::size_type string_view::find(char ch, string_view::size_type pos) const {
    if (pos >= sz) throw std::out_of_range("pos > size");
    auto res = std::find(begin() + pos, end(), ch);
    return res != end() ? res - begin() : npos;

    /*
    for (size_type i = pos; i < sz; i++) {
        if (str[i] == ch) {
            return i;
        }
    }
    return npos;
*/
}

string_view::size_type string_view::find(string_view s, string_view::size_type pos) const {
    if (pos >= sz) throw std::out_of_range("pos > size");
    auto res = std::search(begin() + pos, end(), s.begin(), s.end());
    return res != end() ? res - begin() : npos;
    int firstIndex = find(s[0]);
    if (firstIndex == npos) return npos;
    for (size_type i = firstIndex; i < s.sz; i++) {
        if (str[i] != s[i]) {
            return npos;
        }
    }
    return firstIndex;
}

/*
bool string_view::operator==(const string_view &s1, const string_view &s2) {
    if (s1.size() != s2.size()) return false;
    return std::equal(s1.begin(), s1.end(), s2.begin());
}

std::ostream &string_view::operator<<(std::ostream &os, const string_view &sv) {
//    for (const auto &x : sv) os << x;
    std::copy(sv.begin(), sv.end(), std::ostream_iterator<char>(os));
    return os;
}
*/










