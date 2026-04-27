cmake_minimum_required(VERSION 3.20)
project(Lab5)

# Встановлюємо C++11 для підтримки застарілих специфікацій винятків
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Основна програма
add_executable(Lab5_Run
        main.cpp
        DateUtils.cpp
        DateUtils.h
        Exceptions.h
)

# 2. Налаштування Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 3. Тестовий файл
add_executable(UnitTest
        UnitTest.cpp
        DateUtils.cpp   # Додаємо логіку функцій до тестів
        DateUtils.h
        Exceptions.h
)

# Лінковка з Google Test (використовуємо gtest_main, щоб не писати main у UnitTest.cpp)
target_link_libraries(UnitTest GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(UnitTest)