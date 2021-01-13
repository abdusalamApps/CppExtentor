//
// Created by Abdusalam Yabrak on 2021-01-01.
//

#ifndef EXTENTOR_STRING_VIEW_H
#define EXTENTOR_STRING_VIEW_H


#include <string>

class string_view {
public:
    using size_type = std::string::size_type;
    using const_iterator = const char *;
    using iterator = const_iterator;

    constexpr static size_type npos = std::string::npos;

    string_view();

    ~string_view() = default;

    string_view(const string_view &) = default;

    string_view(std::string &s);

    string_view(const std::string &s, size_type pos, size_type len);

    string_view(const char *c, size_type len);

    string_view(const char *);

    bool empty() const;

    size_type size() const;

    const_iterator begin() const;

    const_iterator end() const;

    const char &operator[](size_type index) const;

    const char &at(size_type pos) const;

    string_view substr(size_type pos) const;

    string_view substr(size_type pos, size_type len) const;

    size_type find(char ch, size_type pos = 0) const;

    size_type find(string_view s, size_type pos = 0) const;

/*
    bool operator==(const string_view &, const string_view &);

    std::ostream &operator<<(std::ostream &os, const string_view &sv);
*/

private:
    const char *str;
    size_type sz;

};


#endif //EXTENTOR_STRING_VIEW_H
