#pragma once
#include <iostream>
#include <Windows.h>

constexpr auto DEFAULT = 7;
constexpr auto GREEN = 10;
constexpr auto RED = 12;

void print(const char* str, int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, color);
    std::cout << str << std::endl;
    SetConsoleTextAttribute(hConsole, DEFAULT);
}