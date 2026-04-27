#include <gtest/gtest.h>
#include "DateUtils.h"

// Тест 3: Перевірка стандартного винятку std::invalid_argument
TEST(DateExceptions, StandardException) {
    Date badDate = {2026, 13, 1}; // 13-й місяць
    EXPECT_THROW(getDay_v3(badDate), std::invalid_argument);
}

// Тест 4: Перевірка порожнього класу EmptyException
TEST(DateExceptions, EmptyExceptionTest) {
    Date badDate = {2026, 2, 30}; // 30 лютого
    EXPECT_THROW(getDay_v4(badDate), EmptyException);
}

// Тест 5: Перевірка незалежного класу з даними
TEST(DateExceptions, IndependentExceptionTest) {
    Date badDate = {2026, 4, 31}; // У квітні 30 днів
    try {
        getDay_v5(badDate);
        FAIL() << "Expected DateParamException";
    } catch (const DateParamException& e) {
        EXPECT_EQ(e.y, 2026);
        EXPECT_EQ(e.m, 4);
        EXPECT_EQ(e.d, 31);
    }
}

// Тест 6: Перевірка нащадка std::exception
TEST(DateExceptions, DerivedExceptionTest) {
    Date badDate = {2026, -1, 10};
    EXPECT_THROW(getDay_v6(badDate), DateDerivedException);
}

// Тест коректної логіки (27 квітня 2026 - понеділок, індекс 1)
TEST(DateLogic, CorrectDayCalculation) {
    Date goodDate = {2026, 4, 27};
    EXPECT_EQ(getDay_v1(goodDate), 1);
}