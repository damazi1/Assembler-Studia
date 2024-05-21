/* Copyright 2023 dr inż. Bartosz Kowalczyk. All rights reserved. */
#pragma once

#include <iostream>
#include <iomanip>
#include <chrono>
#include <Windows.h>

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

constexpr auto DEFAULT = (uchar)7;
constexpr auto GREEN = (uchar)10;
constexpr auto RED = (uchar)12;
constexpr auto GOLD = (uchar)14;
constexpr auto WHITE = (uchar)15;

constexpr uint dispLimitRows = 10u;
constexpr uint dispLimitCols = 10u;

/// <summary>
/// Get the current timestamp of a std::chrono::steady_clock.
/// </summary>
/// <returns>The current time point.</returns>
const std::chrono::steady_clock::time_point getTime() {
    return std::chrono::steady_clock::now();
}

/// <summary>
/// Calculate the time duration between two time points specified in nanoseconds.
/// </summary>
/// <param name="start"></param>
/// <param name="end"></param>
/// <returns>uint64 value of nanoseconds between two time points.</returns>
const uint64 getDurationNs(const std::chrono::steady_clock::time_point start, const std::chrono::steady_clock::time_point end) {
    return std::chrono::duration<uint64, std::nano>(end - start).count();
}

/// <summary>
/// Set text color in the attached console. Pass no arguments to bring back default text color.
/// </summary>
/// <param name="color"></param>
void setConsoleTextColor(const uchar color = DEFAULT) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

/// <summary>
/// Print text to the attached console with a given color.
/// </summary>
/// <param name="str"></param>
/// <param name="color"></param>
void print(const char* str, const uchar color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    std::cout << str << std::endl;
    SetConsoleTextAttribute(hConsole, DEFAULT);
}

/// <summary>
/// Print summary string with a suitable color.
/// </summary>
/// <param name="result"></param>
void printSummary(bool result) {
    std::cout << "Results are equal: ";
    if (result) {
        print("True", GREEN);
    }
    else {
        print("False", RED);
    }
}

/// <summary>
/// Perform floating point numbers safe comparison using default 4 digit precission (1e-4).
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="eps"></param>
/// <returns>False if arguments satisfies the condition a != b. True otherwise.</returns>
template <typename T>
bool almostEqual(const T expected, const T actual, const double eps = 1e-4) {
    return std::fabs(expected - actual) < eps;
}

/// <summary>
/// Checks whether all elements in the two vectors have the same values in corresponding positions.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="w"></param>
/// <param name="u"></param>
/// <param name="size"></param>
/// <returns>False if there is an element which satisfies the condition w[i] != u[i]. True otherwise.</returns>
template <typename T>
bool assertEquals(const T* expected, const T* actual, const uint size) {
    for (uint i = 0; i < size; ++i) {
        if (!almostEqual(expected[i], actual[i])) {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Checks whether all elements in the two matrices have the same values in corresponding positions.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="W"></param>
/// <param name="A"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns>False if there is an element which satisfies the condition W[i][j] != U[i][j]. True otherwise.</returns>
template <typename T>
bool assertEquals(const T* const* expected, const T* const* actual, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (!almostEqual(expected[i][j], actual[i][j])) {
                return false;
            }
        }
    }
    return true;
}

/// <summary>
/// Perform comparison of two numbers of type T.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="expected"></param>
/// <param name="actual"></param>
/// <returns>uint 1 for success, 0 otherwise.</returns>
template <typename T>
uint resultComparator(T expected, T actual) {
    std::cout << "Expected: " << expected << ". Actual: " << actual << std::endl;
    bool result = almostEqual(expected, actual);
    printSummary(result);
    return result ? 1 : 0;
}

/// <summary>
/// Perform element wise comparison of two vectors of type T and of a given size.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="expected"></param>
/// <param name="actual"></param>
/// <param name="size"></param>
/// <returns>uint 1 for success, 0 otherwise.</returns>
template <typename T>
uint resultComparator(const T* expected, const T* actual, const uint size) {
    bool result = assertEquals<T>(expected, actual, size);
    printSummary(result);
    return result ? 1 : 0;
}

/// <summary>
/// Perform element wise comparison of two matrices of type T and of a given size.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="expected"></param>
/// <param name="actual"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns>uint 1 for success, 0 otherwise.</returns>
template <typename T>
uint resultComparator(const T* const* expected, const T* const* actual, const uint rows, const uint cols) {
    bool result = assertEquals<T>(expected, actual, rows, cols);
    printSummary(result);
    return result ? 1 : 0;
}

/// <summary>
/// Get a random number of type T from a given range.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns>Random number of type T from a given range.</returns>
template <typename T>
T rnd(const int min = -100, const int max = 100) {
    // Note intentional warning C4244. For integer types loss of the fraction part is intentional.
    return static_cast<T>(rand() % (max - min) + min) / 100.0;
}

/// <summary>
/// Allocate array of size numbers of type T.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="size"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename T>
T* newPtr(const uint size) {
    return new T[size];
}

/// <summary>
/// Allocate matrix of rows x cols numbers of type T.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename T>
T** newPtr(const uint rows, const uint cols) {
    T** ptr = newPtr<T*>(rows);
    for (uint i = 0; i < rows; ++i) {
        ptr[i] = newPtr<T>(cols);
    }
    return ptr;
}

/// <summary>
/// Free memory from pointer.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ptr"></param>
template <typename T>
void freePtr(T* ptr) {
    delete[] ptr;
}

/// <summary>
/// Free memory from a 2D pointer.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ptr"></param>
/// <param name="rows"></param>
template <typename T>
void freePtr(T** ptr, const uint rows) {
    for (uint i = 0; i < rows; ++i) {
        freePtr<T>(ptr[i]);
    }
    delete[] ptr;
}

/// <summary>
/// Print array.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ptr"></param>
/// <param name="size"></param>
template <typename T>
void printPtr(const T* ptr, const uint size) {
    std::cout << "Vector [" << size << "]:" << std::endl;
    const bool trunc = size > dispLimitCols;
    uint limit = size;
    if (trunc) {
        limit = dispLimitCols;
        std::cout << "Warning. Long array (" << size << "). Display truncated to first " << limit << " elements." << std::endl;
    }
    std::cout << "[";
    for (uint i = 0; i < limit; ++i) {
        std::cout << std::fixed << std::setw(4) << std::setprecision(2) << ptr[i] << " ";
    }
    std::cout << (trunc ? " ... " : "]") << std::endl;
}

/// <summary>
/// Print matrix.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ptr"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
template <typename T>
void printPtr(const T* const* ptr, const uint rows, const uint cols) {
    std::cout << "Matrix [" << rows << "] x [" << cols << "]:" << std::endl;
    const bool truncRows = rows > dispLimitRows;
    const bool truncCols = cols > dispLimitCols;
    uint limitRows = rows;
    uint limitCols = cols;
    if (truncRows) {
        limitRows = dispLimitRows;
    }
    if (truncCols) {
        limitCols = dispLimitCols;
    }
    if (truncRows || truncCols) {
        std::cout << "Warning. Matrix too big. Display truncated to first " << limitRows << " x " << limitCols << " elements." << std::endl;
    }
    for (uint i = 0; i < limitRows; ++i) {
        std::cout << "[";
        for (uint j = 0; j < limitCols; ++j) {
            std::cout << std::fixed << std::setw(4) << std::setprecision(2) << ptr[i][j] << " ";
        }
        std::cout << (truncCols ? " ... " : "]") << std::endl;
    }
    if (truncRows) {
        std::cout << " ";
        for (uint i = 0; i < 10; ++i) {
            std::cout << " ... ";
        }
        std::cout << std::endl;
    }
}

/// <summary>
/// Allocate array of size numbers of type T and fill it with values.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="size"></param>
/// <param name="random">If true fill array with random numbers. With specified value otherwice.</param>
/// <param name="val"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename T>
T* newFillPtr(const uint size, const bool random = true, const T val = 0) {
    T* ptr = newPtr<T>(size);
    for (uint i = 0; i < size; ++i) {
        ptr[i] = random ? rnd<T>() : val;
    }
    return ptr;
}

/// <summary>
/// Allocate matrix of rows x cols numbers of type T and fill it with values. 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <param name="random"></param>
/// <param name="val"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename T>
T** newFillPtr(const uint rows, const uint cols, const bool random = true, const T val = 0) {
    T** ptr = newPtr<T>(rows, cols);
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            ptr[i][j] = random ? rnd<T>() : val;
        }
    }
    return ptr;
}

/// <summary>
/// Allocate array of size numbers of type T and copy values from original array converted to type R.
/// </summary>
/// <typeparam name="R"></typeparam>
/// <typeparam name="T"></typeparam>
/// <param name="origin"></param>
/// <param name="size"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename R, typename T>
R* newCopyPtr(const T* origin, const uint size) {
    R* ptr = newPtr<R>(size);
    for (uint i = 0; i < size; ++i) {
        ptr[i] = static_cast<R>(origin[i]);
    }
    return ptr;
}

/// <summary>
/// Allocate matrix of rows x cols numbers of type T and copy values from original matrix converted to type R.
/// </summary>
/// <typeparam name="R"></typeparam>
/// <typeparam name="T"></typeparam>
/// <param name="origin"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename R, typename T>
R** newCopyPtr(const T* const* origin, const uint rows, const uint cols) {
    R** ptr = newPtr<R>(rows, cols);
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            ptr[i][j] = static_cast<R>(origin[i][j]);
        }
    }
    return ptr;
}

/// <summary>
/// Get Assembly type literal based on the sizeof(T).
/// </summary>
/// <param name="size">sizeof(T)</param>
/// <returns>Assembly type literal:
/// 1 - B
/// 2 - W
/// 4 - D
/// 8 - Q
/// </returns>
const char* getTypeLiteral(const uint size) {
    switch (size) {
    case 1: return "B";
    case 2: return "W";
    case 4: return "D";
    case 8: return "Q";
    default: return "";
    }
}