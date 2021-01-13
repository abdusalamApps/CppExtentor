//
// Created by Abdusalam Yabrak on 2021-01-09.
//

#ifndef EXTENTOR_ACCUMULATOR_H
#define EXTENTOR_ACCUMULATOR_H

#include "stack"
#include <iostream>

class Accumulator {
public:
    Accumulator() {

    }

    void undo() {
        if (!history.empty()) {
            sum -= history.top();
            history.pop();
        }
    }

    void commit() {
        while (!history.empty()) {
            history.pop();
        }
    }

    void rollback() {
        while (!history.empty()) {
            undo();
        }
    }

    friend std::ostream &operator<<(std::ostream &os, Accumulator &accumulator) {
        os << accumulator.sum << "\n";
        return os;
    }

    Accumulator& operator+=(int number) {
        history.push(number);
        sum += number;
        return *this;
    }

private:
    std::stack<int> history;
    int sum;

};


#endif //EXTENTOR_ACCUMULATOR_H
