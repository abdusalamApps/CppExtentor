#include <iostream>
#include <vector>
#include <fstream>
#include "MorseCode.h"
#include "array.h"
#include "Editor.h"
#include "Encypter.h"
using std::cout;
using std::endl;

template<typename Cont>
void print1(const Cont &c) {
    for (typename Cont::size_type i = 0; i != c.size(); i++) {
        cout << c[i] << endl;
    }
}

template<typename Cont>
void print2(const Cont &c) {
    for (typename Cont::const_iterator it = c.begin(); it != c.end(); ++it) {
        cout << *it << endl;
    }
}

template<typename Iterator, typename UnaryPredicate>
// Move all elements in [first, last) to the front for which
// op(elem) yields true. Return the first position for which
// op yields false. The time complexity is linear.
Iterator partition(Iterator first, Iterator last, UnaryPredicate op) {
    first = std::find_if_not(first, last, op);
    if (first == last) return first;
    for (auto it = std::next(first); it != last; ++it) {
        if (op(*it)) {
            std::iter_swap(it, first);
            ++first;
        }
    }
    return first;
}
int predicate(int i) {
    return i % 2 == 0;
}
void test_partition(std::istream &is) {
    std::vector<int> v;
    int i;
    while (is >> i) {
        v.push_back(i);
    }
    auto pit = std::partition(v.begin(), v.end(), predicate);
    std::sort(v.begin(), pit, std::greater<int>{});
    std::sort(pit, v.end(), std::greater<int>{});
    std::cout << "result:\n";
    for (int n : v) {
        std::cout << n << " ";
    }
    cout << "\n";
}

bool insideLimits(double x) {
    return -0.5 <= x <= 0.5;
}
int main() {
    int x = 4;
    int y = 5;

    auto f = [&](){return x * y;};

    cout << f() << "\n";
    x = 5;
    cout << f() << "\n";
    return 0;
}
