#pragma once

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

template <typename R, typename T> R cpp02_xx(const T a, const T b) {
    return static_cast<R>((7 * (a + b)) / 5);
}

template <typename R, typename T> R cpp03_01(const T a, const T b, const T c, const T d, const T e, const T f) {
    return static_cast<R>(a + b + c + d + e + f);
}

template <typename R, typename T> R cpp03_02(const T a, const T b, const T c, const T d, const T e, const T f) {
    return static_cast<R>(a - b - c - d - e - f);
}

template <typename R, typename T> R cpp03_03(const T a, const T b, const T c, const T d, const T e, const T f, const T g, const T h) {
    return static_cast<R>(a * b - c * d - e + f * g + h);
}

template <typename R, typename T> R cpp03_04(const T a, const T b, const T c, const T d, const T e, const T f, const T g, const T h) {
    return static_cast<R>(a - b * c - d + e * f - g * h);
}

template <typename R, typename T> R cpp03_05(const T a, const T b, const T c, const T d, const T e, const T f) {
    return static_cast<R>(128 * a + 64 * b + 32 * c + 16 * d + 8 * e + 4 * f);
}

template <typename R, typename T> R cpp03_06(const T a, const T b, const T c, const T d, const T e, const T f) {
    return static_cast<R>(a / 2 - b / 4 + c / 8 - d / 16 + e / 32 - f / 64);
}

template <typename R, typename T> R cpp03_07(const T a, const T b, const T c, const T d, const T e, const T f, const T g, const T h) {
    return static_cast<R>((10 * a - b + 40 * c - d + 11 * e - f) / (10 + 2 * g - 4 * h));
}

template <typename R, typename T> R cpp03_08(const T a, const T b, const T c, const T d, const T e, const T f) {
    return static_cast<R>(46 * a * b + 128 * c % (12 * d + 7 * e + f));
}

template <typename R, typename T> R cpp04_01(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        y += static_cast<R>(a[i]);
    }
    return y;
}

template <typename R, typename T> R cpp04_02(const T* a, const uint n) {
    R y = 1;
    for (uint i = 0; i < n; ++i) {
        y *= static_cast<R>(a[i]);
    }
    return y;
}

template <typename R, typename T> R cpp04_03(const T* a, const uint n) {
    R y = a[0];
    for (uint i = 1; i < n; ++i) {
        if (static_cast<R>(a[i]) < y) {
            y = static_cast<R>(a[i]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp04_04(const T* a, const uint n) {
    R y = a[0];
    for (uint i = 1; i < n; ++i) {
        if (static_cast<R>(a[i]) > y) {
            y = static_cast<R>(a[i]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp04_05(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        y += static_cast<R>(a[i]);
    }
    return (y / n);
}

template <typename R, typename T> R cpp04_06(const T* a, const T* b, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        y += static_cast<R>(a[i]) * static_cast<R>(b[i]);
    }
    return y;
}

template <typename R, typename T> R cpp04_07(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        y += 5 * static_cast<R>(a[i]) - 3;
    }
    return y;
}

template <typename R, typename T> R cpp04_08(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        y += 16 * static_cast<R>(a[i]) + 6;
    }
    return y;
}

template <typename R, typename T> R cpp04_09(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        y += (static_cast<R>(a[i]) + 6) / 4;
    }
    return y;
}

template <typename R, typename T> R cpp04_10(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp04_11(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        if (a[i] % 2 != 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp04_12(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        if (a[i] % 8 == 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp04_13(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        if (a[i] > 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp04_14(const T* a, const uint n) {
    R y = R();
    for (uint i = 0; i < n; ++i) {
        if (a[i] > 5 && a[i] <= 15) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> void cpp05_01(R* y, const T* a, const uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = 16 * static_cast<R>(a[i]) + 5;
    }
}

template <typename R, typename T> void cpp05_02(R* y, const T* a, const uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = static_cast<R>(a[i]) * static_cast<R>(a[i]);
    }
}

template <typename R, typename T> void cpp05_03(R* y, const T* a, const T* b, const uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = static_cast<R>(a[i]) + static_cast<R>(b[i]);
    }
}

template <typename R, typename T> void cpp05_04(R* y, const T* a, const T* b, const uint n) {
    for (uint i = 0; i < n; ++i) {
        y[i] = (5 * static_cast<R>(a[i]) + 4 * static_cast<R>(b[i])) / 3;
    }
}

template <typename R, typename T> void cpp05_05(R* y, const T* a, const T* b, const uint n) {
    for (uint i = 0; i < n; ++i) {
        if (b[i] != 0) {
            y[i] = static_cast<R>(a[i]) / static_cast<R>(b[i]);
        }
    }
}

template <typename R, typename T> void cpp05_06(R* y, const T* a, const T* b, const uint n) {
    for (uint i = 0; i < n; ++i) {
        if (b[i] != 0) {
            y[i] = static_cast<R>(a[i]) % static_cast<R>(b[i]);
        }
    }
}

template <typename T> void cpp05_07(T* a, const uint n) {
    for (uint i = 0; i < n; i += 2) {
        a[i] = T();
    }
}

template <typename T> void cpp05_08(T* a, const uint n) {
    for (uint i = 1; i < n; i += 2) {
        a[i] = T();
    }
}

template <typename R, typename T> void cpp05_09(R* y, const T* a, const uint n) {
    for (uint i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            y[i] = R();
        }
        else {
            y[i] = static_cast<R>(a[i]);
        }
    }
}

template <typename R, typename T> void cpp05_10(R* y, const T* a, const uint n) {
    for (uint i = 0; i < n; ++i) {
        if (i % 2 != 0) {
            y[i] = R();
        }
        else {
            y[i] = static_cast<R>(a[i]);
        }
    }
}
