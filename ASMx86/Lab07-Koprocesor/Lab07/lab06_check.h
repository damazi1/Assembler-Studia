#pragma once

template <typename R, typename T>
R cpp01(T a, T b, T c) {
    return b * b - 4 * a * c;
}

template <typename R, typename T>
R cpp02(T a, T b, T c) {
    return c * (a + b) / 2.0f;
}

template <typename R, typename T>
R cpp03(T a, T b, T c) {
    T tmp1 = a + b;
    T tmp2 = a + c;
    return 4 * tmp1 * tmp1 * tmp1 - 2 * tmp2 * tmp2;
}

template <typename R, typename T>
R cpp04(T a, T b) {
    T tmp1 = 1.0f / a;
    T tmp2 = std::abs(1.0f / b);
    T tmp3 = 1.0f + tmp1 * tmp1 + std::sqrt(tmp2 * tmp2 * tmp2);
    return tmp3 * tmp3;
}

template <typename R, typename T>
R cpp05(T a, T b) {
    T tmp1 = (T)std::sin(a * M_PI / 180.0f);
    T tmp2 = (T)(b * M_PI / 180.0f);
    return 4 * tmp1 * tmp1 * tmp1 - 2 * std::cos(tmp2 * tmp2);
}

template <typename R, typename T>
R cpp06(T a, T b) {
    T tmp1 = 1.0f + a / (b + 1.0f);
    T tmp2 = 1.0f + b / (a + 1.0f);
    return std::log2(tmp1 * tmp1) + std::log2(tmp2 * tmp2);
}

template <typename R, typename T>
R cpp07(T* x, const int n) {
    R y = R();
    for (int i = 0; i < n; ++i) {
        y += x[i] * x[i];
    }
    return y;
}

template <typename T>
void cpp08(T* y, T* x, const int n) {
    for (int i = 0; i < n; ++i) {
        y[i] = 5 * x[i] * x[i] * x[i] - x[i];
    }
}