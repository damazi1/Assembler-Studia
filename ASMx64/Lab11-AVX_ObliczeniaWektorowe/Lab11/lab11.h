#pragma once
#include "utils.h"

template <typename T> void cpp01_01(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a[i] + b[i];
    }
}

template <typename T> void cpp01_02(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a[i] - b[i];
    }
}

template <typename T> void cpp01_03(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a[i] * b[i];
    }
}

template <typename T> void cpp01_04(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a[i] / b[i];
    }
}

template <typename T> void cpp01_05(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = 10 * a[i] + 6 * b[i];
    }
}

template <typename T> void cpp01_06(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = std::sqrt(a[i] + b[i]);
    }
}

template <typename T> void cpp01_07(T* a, uint n) {
    for (uint i = 0; i < n; ++i) {
        a[i] = std::fabs(a[i]);
    }
}

template <typename T> void cpp01_08(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = std::fabs(a * x[i] * x[i] * x[i] + b);
    }
}

template <typename T> void cpp01_09(T* x, T* y, uint n, T a, T b, T c) {
    for (uint i = 0; i < n; ++i) {
        y[i] = 15 * x[i] * x[i] * x[i] + 5 * x[i] * x[i] - 6 * x[i] + 2;
    }
}

template <typename T> void cpp01_10(T* x, T* y, uint n, T a, T b, T c, T d) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] * x[i]* x[i] + b * x[i] * x[i] + c * x[i] + d;
    }
}

template <typename T> void cpp01_11(T* a, T* b, T* c, T* d, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = std::pow(a[i] + b[i], 2) - std::sqrt(c[i] * d[i] + 1);
    }
}

template <typename T> void cpp01_12(T* a, T* b, T* c, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = (a[i] + b[i]) / std::sqrt(c[i]);
    }
}

template <typename T> void cpp01_13(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = std::fabs(a * x[i] * x[i] * x[i] - b * x[i] * x[i]) + std::sqrt(a * x[i] * x[i] + b * x[i] * x[i]);
    }
}

template <typename T> void cpp01_14(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = std::sqrt(std::pow(x[i] - a, 2) + std::pow(x[i] - b, 2));
    }
}

template <typename T> void cpp01_15(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? (a[i] - b[i]) : (a[i] + b[i]);
    }
}

template <typename T> void cpp01_16(T* a, T* b, T* x, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? (a[i] - b[i]) * x[i] : (a[i] + b[i]) * x[i];
    }
}

template <typename T> void cpp02_01(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] + b;
    }
}

template <typename T> void cpp02_02(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] - b;
    }
}

template <typename T> void cpp02_03(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = -a * x[i] + b;
    }
}

template <typename T> void cpp02_04(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = -a * x[i] - b;
    }
}

template <typename T> void cpp02_05(T* x, T* y, uint n, T a) {
    for (uint i = 0; i < n; ++i) {
        y[i] = x[i] * x[i] + a;
    }
}

template <typename T> void cpp02_06(T* x, T* y, uint n, T a) {
    for (uint i = 0; i < n; ++i) {
        y[i] = x[i] * x[i] - a;
    }
}

template <typename T> void cpp02_07(T* x, T* y, uint n, T a, T b, T c, T d) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] * x[i] * x[i] + b * x[i] * x[i] + c * x[i] + d;
    }
}

template <typename T> void cpp02_08(T* x, T* y, uint n, T a, T b, T c, T d) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] * x[i] * x[i] - b * x[i] * x[i] - c * x[i] - d;
    }
}

template <typename T> void cpp02_09(T* x, T* y, uint n, T a, T b, T c, T d) {
    for (uint i = 0; i < n; ++i) {
        y[i] = -a * x[i] * x[i] * x[i] + b * x[i] * x[i] + c * x[i] + d;
    }
}

template <typename T> void cpp02_10(T* x, T* y, uint n, T a, T b, T c, T d) {
    for (uint i = 0; i < n; ++i) {
        y[i] = -a * x[i] * x[i] * x[i] + b * x[i] * x[i] + c * x[i] - d;
    }
}

template <typename T> void cpp02_11(T* x, T* y, uint n, T a, T b, T c) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] * x[i] + b * c;
    }
}

template <typename T> void cpp02_12(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = a * x[i] + std::pow(x[i] + b, 2);
    }
}

template <typename T> void cpp02_13(T* a, T* b, T* x, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? a[i] * x[i] - b[i] : a[i] * x[i] + b[i];
    }
}

template <typename T> void cpp02_14(T* a, T* b, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? a[i] * a[i] - b[i] : a[i] * a[i] + b[i];
    }
}

template <typename T> void cpp02_15(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? x[i] * a - b : x[i] * a + b;
    }
}

template <typename T> void cpp02_16(T* a, T* y, uint n, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? a[i] * a[i] - b : a[i] * a[i] + b;
    }
}

template <typename T> void cpp02_17(T* a, T* b, T* x, T* y, uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? (a[i] * a[i] - b[i]) / (a[i] * x[i] - b[i]) : (a[i] * a[i] + b[i]) / (a[i] * x[i] + b[i]);
    }
}

template <typename T> void cpp02_18(T* x, T* y, uint n, T a, T b) {
    for (uint i = 0; i < n; ++i) {
        y[i] = i % 2 == 0 ? (a * a - b) / (a * x[i] - b) : (a * a + b) / (a * x[i] + b);
    }
}

template <typename T> T cpp03_01(T* a, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += a[i];
    }
    return y;
}

template <typename T> T cpp03_02(T* a, uint n) {
    T y = 1;
    for (uint i = 0; i < n; ++i) {
        y *= a[i];
    }
    return y;
}

template <typename T> T cpp03_03(T* a, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += a[i];
    }
    return (y / n);
}

template <typename T> T cpp03_04(T* a, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += a[i] * a[i];
    }
    return std::sqrt(y);
}

template <typename T> T cpp03_05(T* a, T* b, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += a[i] * b[i];
    }
    return y;
}

template <typename T> T cpp03_06(T* a, T* b, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += std::abs(a[i] - b[i]);
    }
    return y;
}

template <typename T> T cpp03_07(T* a, T* b, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += 16 * a[i] + b[i];
    }
    return y;
}

template <typename T> T cpp03_08(T* a, T* b, T* x, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += a[i] * x[i] + b[i];
    }
    return y;
}

template <typename T> T cpp03_09(T* a, T* b, uint n, T c) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += (a[i] / c) + b[i];
    }
    return y;
}

template <typename T> T cpp03_10(T* a, T* b, T* c, uint n) {
    T y = T();
    for (uint i = 0; i < n; ++i) {
        y += (a[i] / c[i]) + b[i];
    }
    return y;
}
