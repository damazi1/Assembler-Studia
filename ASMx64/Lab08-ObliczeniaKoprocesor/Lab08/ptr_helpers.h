#pragma once
#include <iomanip>

/// <summary>
/// Get a random number of type T from a given range.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns></returns>
template <typename T>
T rnd(const int min = -200, const int max = 200) {
    return (rand() % (max - min) + min) / 100.0f;
}

/// <summary>
/// Allocate array of size numbers of type T.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="size"></param>
/// <returns>Pointer to the newly allocated array.</returns>
template <typename T>
T* newPtr(const int size) {
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
T** newPtr(const int rows, const int cols) {
    T** ptr = newPtr<T*>(rows);
    for (int i = 0; i < rows; ++i) {
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
void freePtr(T** ptr, const int rows) {
    for (int i = 0; i < rows; ++i) {
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
void printPtr(const T* ptr, const int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setw(8) << std::setprecision(4) << ptr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

/// <summary>
/// Print matrix.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="ptr"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
template <typename T>
void printPtr(const T* const* ptr, const int rows, const int cols) {
    for (int i = 0; i < rows; ++i) {
        printPtr<T>(ptr[i], cols);
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
T* newFillPtr(const int size, const bool random = true, const T val = 0) {
    T* ptr = newPtr<T>(size);
    for (int i = 0; i < size; ++i) {
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
T** newFillPtr(const int rows, const int cols, const bool random = true, const T val = 0) {
    T** ptr = newPtr<T>(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
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
R* newCopyPtr(const T* origin, const int size) {
    R* ptr = newPtr<R>(size);
    for (int i = 0; i < size; ++i) {
        ptr[i] = (R)origin[i];
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
R** newCopyPtr(const T* const* origin, const int rows, const int cols) {
    R** ptr = newPtr<R>(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ptr[i][j] = (R)origin[i][j];
        }
    }
    return ptr;
}