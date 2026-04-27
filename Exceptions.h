#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <string>

// 4. Порожній клас
class EmptyException {};

// 5. Незалежний клас з полями-параметрами
class DateParamException {
public:
    int y, m, d;
    DateParamException(int year, int month, int day) : y(year), m(month), d(day) {}
};

// 6. Нащадок від std::exception (використовуємо runtime_error для зручності)
class DateDerivedException : public std::runtime_error {
    int y, m, d;
public:
    DateDerivedException(int year, int month, int day)
        : std::runtime_error("Invalid Date Exception"), y(year), m(month), d(day) {}

    void showData() const {
        std::cout << "[Error Data -> Year: " << y << ", Month: " << m << ", Day: " << d << "]";
    }
};

#endif