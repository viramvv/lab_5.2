#ifndef DATEUTILS_H
#define DATEUTILS_H

#include "Exceptions.h"
#include <stdexcept>

struct Date {
    int year, month, day;
};

int getDay_v1(Date d); // без специфікації
int getDay_v2(Date d) noexcept(false); // throw()
int getDay_v3(Date d); // специфікація std::invalid_argument
int getDay_v4(Date d); // специфікація EmptyException
int getDay_v5(Date d); // специфікація DateParamException
int getDay_v6(Date d); // специфікація DateDerivedException

// Функції для підміни
void my_terminate();
void my_unexpected();

#endif