#include "DateUtils.h"
#include <iostream>

using namespace std;

bool isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

bool checkDate(Date d) {
    if (d.month < 1 || d.month > 12) return false;
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (isLeap(d.year)) days[1] = 29;
    return d.day >= 1 && d.day <= days[d.month - 1];
}

// Алгоритм розрахунку (0 - Нд, 1 - Пн...)
int calculate(Date d) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    int y = d.year - (d.month < 3);
    return (y + y/4 - y/100 + y/400 + t[d.month-1] + d.day) % 7;
}

int getDay_v1(Date d) {
    if (!checkDate(d)) throw "Error: Wrong Date";
    return calculate(d);
}

int getDay_v2(Date d) noexcept(false) {
    if (!checkDate(d)) throw 404;
    return calculate(d);
}

int getDay_v3(Date d) {
    if (!checkDate(d)) throw invalid_argument("Standard Exception: Invalid Date");
    return calculate(d);
}

int getDay_v4(Date d) {
    if (!checkDate(d)) throw EmptyException();
    return calculate(d);
}

int getDay_v5(Date d) {
    if (!checkDate(d)) throw DateParamException(d.year, d.month, d.day);
    return calculate(d);
}

int getDay_v6(Date d) {
    if (!checkDate(d)) throw DateDerivedException(d.year, d.month, d.day);
    return calculate(d);
}

void my_terminate() {
    cout << "--- CUSTOM TERMINATE: No handler for this exception! ---" << endl;
    exit(-1);
}

void my_unexpected() {
    cout << "--- CUSTOM UNEXPECTED: Exception specification violated! ---" << endl;
    terminate();
}