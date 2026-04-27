#include <iostream>
#include "DateUtils.h"

using namespace std;

int main() {
    set_terminate(my_terminate);
    set_unexpected(my_unexpected);

    Date bad = {2026, 13, 13}; // Некоректна дата
    string names[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    cout << "--- Testing Exception Handling ---" << endl;

    // Варіант 3: Стандартна ситуація
    try {
        cout << "Test 3: ";
        getDay_v3(bad);
    } catch (const invalid_argument& e) {
        cout << "Caught: " << e.what() << endl;
    }

    // Варіант 4: Порожній клас
    try {
        cout << "Test 4: ";
        getDay_v4(bad);
    } catch (EmptyException) {
        cout << "Caught: EmptyException object" << endl;
    }

    // Варіант 5: Незалежний клас
    try {
        cout << "Test 5: ";
        getDay_v5(bad);
    } catch (const DateParamException& e) {
        cout << "Caught: Error in " << e.d << "/" << e.m << "/" << e.y << endl;
    }

    // Варіант 6: Нащадок std::exception
    try {
        cout << "Test 6: ";
        getDay_v6(bad);
    } catch (const DateDerivedException& e) {
        cout << "Caught: " << e.what() << " ";
        e.showData();
        cout << endl;
    }

    // Коректний запуск
    Date good = {2026, 4, 27};
    cout << "\nValid Date (27.04.2026): " << names[getDay_v1(good)] << endl;

    return 0;
}