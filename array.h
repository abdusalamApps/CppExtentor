//
// Created by Abdusalam Yabrak on 2021-01-01.
//

#ifndef EXTENTOR_ARRAY_H
#define EXTENTOR_ARRAY_H

#include <cstddef>

template<typename T, size_t N>
class array {
public:
    using size_type = size_t;

    using const_iterator = const T *;

    const_iterator begin() const { return arr; }
    const_iterator end() const { return arr + N; }

    T &operator[](size_type i) { return arr[i]; }

    const T &operator[](size_type i) const {
        const int n = arr[i];
        return n;
    }

    size_type size() const { return N; }


private:
    T arr[N];
};


#endif //EXTENTOR_ARRAY_H
