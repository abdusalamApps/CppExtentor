//
// Created by Abdusalam Yabrak on 2021-01-09.
//

#ifndef EXTENTOR_POLYNOMIAL_H
#define EXTENTOR_POLYNOMIAL_H

#include "list"
#include <iostream>

#include <cmath>

class Polynomial {
public:
    Polynomial() {

    }

    void add_term(double a, size_t b) {
        auto it = terms.begin();
        while (it != terms.end() && b > it->second) {
            it++;
        }
        terms.insert(it, std::make_pair(a, b));
    };

    friend std::ostream &operator<<(std::ostream &ostream, Polynomial &polynomial) {
        for (auto pair : polynomial.terms) {
            ostream << pair.first << "x^" << pair.second << "\n";
        }
        return ostream;
    }

    double operator()(int xvalue) {
        double calculated = 0.0;
        for (auto pair : terms) {
            calculated += pair.first * std::pow(xvalue, pair.second);
        }
        return calculated;
    }

    Polynomial &operator+=(Polynomial &p) {
        auto index1 = terms.begin();
        auto index2 = p.terms.begin();

        while (index1 != terms.end() && index2 != p.terms.end()) {
            if (index1->second < index2->second) {
                index1++;
            } else if (index2->second < index1->second) {
                terms.insert(index1, *index2);
            } else {
                double kof = index2->first + index1->first;
                if (kof == 0) {
                    terms.erase(index1);
                } else {
                    index1->first = kof;
                    index1++;
                }
                index2++;
            }
        }
        while (index2 != p.terms.end()) {
            terms.insert(index1, *index2);
            index1++;
            index2++;
        }
        return *this;
    }

    friend Polynomial operator+(Polynomial &lhs, Polynomial &rhs) {
        Polynomial result = lhs;
        return result += rhs;
    }

private:
    typedef std::pair<double, size_t> term;
    std::list<term> terms;
};


#endif //EXTENTOR_POLYNOMIAL_H
