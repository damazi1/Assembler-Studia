#pragma once

template <typename T>
T cpp01(T a, T b, T c, T d, T x) {
    return std::pow(std::abs(a), x);
}

template <typename T>
T cpp02(T a, T x) {
    double ax = a * x;
    return static_cast<T>((ax <= -6.0) ? 0 : a * std::log(1.0f + std::pow(x, 4.0f)) + 8.0f * std::sqrt(ax + 6.0));
}

template <typename T>
T cpp03(T a, T b, T c, T x) {
    T y = T();
    if (x <= -5) {
        y = a * x * x + b * x + c;
    }
    else if (x <= 0) {
        y = static_cast<T>(std::pow(std::sin((M_PI * x) / 180.0f), 2) + std::cos(std::pow((M_PI * x) / 180.0f, 2)));
    }
    else if (x <= 5) {
        y = a * x * x * log2(1 + x);
    }
    else {
        y = static_cast<T>(std::sqrt(16.0 * x * M_PI) - std::sqrt(32.0 * x * x));
    }
    return y;
}

template <typename T>
void cpp04(T* x, T* y, const int size, T a, T b, T xMin, T xMax) {
    T step = (xMax - xMin) / size;
    for (int i = 0; i < size; ++i) {
        x[i] = xMin + i * step;
        y[i] = static_cast<T>(a * std::sin(std::pow((M_PI * x[i]) / 180.0, 2)) + b * std::cos((M_PI * x[i]) / 180.0));
    }
}
