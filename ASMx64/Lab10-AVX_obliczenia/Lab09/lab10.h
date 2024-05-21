#pragma once
#include "utils.h"

template <typename T> T cpp01_01(T a, T b) {
    return a + b;
}

template <typename T> T cpp01_02(T a, T b) {
    return a - b;
}

template <typename T> T cpp01_03(T a, T b) {
    return a * b;
}

template <typename T> T cpp01_04(T a, T b) {
    return a / b;
}

template <typename T> T cpp01_05(T a, T b) {
    return 10 * a + 6 * b;
}

template <typename T> T cpp01_06(T a, T b) {
    return std::sqrt(a + b);
}

template <typename T> T cpp01_07(T a) {
    return std::fabs(a);
}

template <typename T> T cpp01_08(T a, T b, T x) {
    return std::fabs(a * x * x * x + b);
}

template <typename T> T cpp01_09(T x) {
    return 15 * x * x * x + 5 * x * x - 6 * x + 2;
}

template <typename T> T cpp01_10(T a, T b, T c, T d, T x) {
    return a * x * x * x + b * x * x + c * x + d;
}

template <typename T> T cpp01_11(T a, T b, T c, T d) {
    return std::pow(a + b, 2) - std::sqrt(c * d + 1);
}

template <typename T> T cpp01_12(T a, T b, T c, T d, T e, T f) {
    return (a * b + c * d) / std::sqrt(e * f);
}

template <typename T> T cpp01_13(T a, T b, T x) {
    return std::fabs(a * x * x * x - b * x * x) + std::sqrt(a * x * x + b * x * x);
}

template <typename T> T cpp01_14(T a, T b, T x) {
    return std::sqrt(std::pow(x - a, 2) + std::pow(x - b, 2));
}

template <typename T> T cpp01_15(T r, T h) {
    return M_PI * r * r * h;
}

template <typename T> T cpp01_16(T r) {
    return (4 * M_PI * r * r * r) / 3;
}

template <typename T> T cpp02_01(T a, T b, T x) {
    return a * x + b;
}

template <typename T> T cpp02_02(T a, T b, T x) {
    return a * x - b;
}

template <typename T> T cpp02_03(T a, T b, T x) {
    return -a * x + b;
}

template <typename T> T cpp02_04(T a, T b, T x) {
    return -a * x - b;
}

template <typename T> T cpp02_05(T a, T x) {
    return x * x + a;
}

template <typename T> T cpp02_06(T a, T x) {
    return x * x - a;
}

template <typename T> T cpp02_07(T a, T b, T c, T d, T x) {
    return a * x * x * x + b * x * x + c * x + d;
}

template <typename T> T cpp02_08(T a, T b, T c, T d, T x) {
    return a * x * x * x - b * x * x - c * x - d;
}

template <typename T> T cpp02_09(T a, T b, T c, T d, T x) {
    return -a * x * x * x + b * x * x + c * x + d;
}

template <typename T> T cpp02_10(T a, T b, T c, T d, T x) {
    return -a * x * x * x + b * x * x + c * x - d;
}

template <typename T> T cpp02_11(T a, T b, T c, T x) {
    return a * x * x + b * c;
}

template <typename T> T cpp02_12(T a, T b, T x) {
    return a * x + std::pow(x + b, 2);
}
