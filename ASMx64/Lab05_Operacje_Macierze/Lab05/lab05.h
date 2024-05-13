#pragma once

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;


template <typename R, typename T> R cpp01_01(T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y += static_cast<R>(A[i][j]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_02(T** A, const uint rows, const uint cols) {
    R y = 1;
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y *= static_cast<R>(A[i][j]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_03(const T** A, const uint rows, const uint cols) {
    R y = static_cast<R>(A[0][0]);
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (static_cast<R>(A[i][j]) < y) {
                y = static_cast<R>(A[i][j]);
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_04(T** A, const uint rows, const uint cols) {
    R y = static_cast<R>(A[0][0]);
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (static_cast<R>(A[i][j]) > y) {
                y = static_cast<R>(A[i][j]);
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_05(const T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y += static_cast<R>(A[i][j]);
        }
    }
    return y / (rows * cols);
}

template <typename R, typename T> R cpp01_06(T** A, T** B, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y += static_cast<R>(A[i][j] * B[i][j]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_07(T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        y += static_cast<R>(A[i][i]);
    }
    return y;
}

template <typename R, typename T> R cpp01_08(T** A, const uint rows, const uint cols) {
    R y = 1;
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        y *= static_cast<R>(A[i][i]);
    }
    return y;
}

template <typename R, typename T> R cpp01_09(T** A, const uint rows, const uint cols) {
    R y = static_cast<R>(A[0][0]);
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (static_cast<R>(A[i][i]) < y) {
            y = static_cast<R>(A[i][i]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_10(const T** A, const uint rows, const uint cols) {
    R y = static_cast<R>(A[0][0]);
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (static_cast<R>(A[i][i]) > y) {
            y = static_cast<R>(A[i][i]);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_11(const T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        y += static_cast<R>(A[i][i]);
    }
    return y / d;
}

template <typename R, typename T> R cpp01_12(const T** A, const T** B, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        y += static_cast<R>(A[i][i] * B[i][i]);
    }
    return y;
}

template <typename R, typename T> R cpp01_13(const T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y += static_cast<R>(5 * A[i][j] - 3);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_14(T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y += static_cast<R>(16 * A[i][j] + 6);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_15(const T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y += static_cast<R>((A[i][j] + 6) / 4);
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_16(const T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (A[i][j] % 2 == 0) {
                y++;
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_17(T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (A[i][j] % 2 != 0) {
                y++;
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_18(T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (A[i][j] % 4 == 0) {
                y++;
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_19(const T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (A[i][j] > 0) {
                y++;
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_20(T** A, const uint rows, const uint cols) {
    R y = R();
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (A[i][j] > -10 && A[i][j] < 10) {
                y++;
            }
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_21(const T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (A[i][i] % 2 == 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_22( T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (A[i][i] % 2 != 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_23(const T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (A[i][i] % 4 == 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_24(const T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (A[i][i] > 0) {
            y++;
        }
    }
    return y;
}

template <typename R, typename T> R cpp01_25(const T** A, const uint rows, const uint cols) {
    R y = R();
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        if (A[i][i] >= 20 && A[i][i] <= 30) {
            y++;
        }
    }
    return y;
}

template <typename T> void cpp02_01(const T** A, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            A[i][j] = 16 * A[i][j] + 5;
        }
    }
}

template <typename T> void cpp02_02(T** A, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            A[i][j] *= A[i][j];
        }
    }
}

template <typename T> void cpp02_03(const T** A, const T** B, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            A[i][j] += B[i][j];
        }
    }
}

template <typename T> void cpp02_04(T** A, T** B, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            A[i][j] = (5 * A[i][j] + 4 * B[i][j]) / 3;
        }
    }
}

template <typename T> void cpp02_05(const T** A, const T** B, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            A[i][j] = A[i][j] / B[i][j];
        }
    }
}

template <typename T> void cpp02_06(const T** A, const T** B, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            A[i][j] = A[i][j] % B[i][j];
        }
    }
}

template <typename T> void cpp02_07(const T** A, const T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            Y[j][i] = A[i][j];
        }
    }
}

template <typename T> void cpp02_08(T** A, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; i += 2) {
        for (uint j = 0; j < cols; j += 2) {
            A[i][j] = 0;
        }
    }
}

template <typename T> void cpp02_09(T** A, const uint rows, const uint cols) {
    for (uint i = 1; i < rows; i += 2) {
        for (uint j = 1; j < cols; j += 2) {
            A[i][j] = 0;
        }
    }
}

template <typename T> void cpp02_10(T** A, const uint rows, const uint cols) {
    uint d = min(rows, cols);
    for (uint i = 0; i < d; ++i) {
        A[i][i] = 0;
    }
}

template <typename T> void cpp02_11(T** A, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (i > j) {
                A[i][j] = 0;
            }
        }
    }
}

template <typename T> void cpp02_12(const T** A, const uint rows, const uint cols) {
    for (uint i = 1; i < rows; ++i) {
        for (uint j = 1; j < cols; ++j) {
            if (i < j) {
                A[i][j] = 0;
            }
        }
    }
}

template <typename T> void cpp02_13(const T** A, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = i % 2 == 0 ? 0 : 1; j < cols; j += 2) {
            A[i][j] = 0;
        }
    }
}

template <typename T> void cpp02_14(const T** A, const T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                Y[i][j] = 0;
            }
            else {
                Y[i][j] = A[i][j];
            }
        }
    }
}

template <typename T> void cpp02_15(const T** A, const T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (i % 2 != 0 && j % 2 != 0) {
                Y[i][j] = 0;
            }
            else {
                Y[i][j] = A[i][j];
            }
        }
    }
}

template <typename T> void cpp02_16(const T** A, const T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (i == j) {
                Y[i][j] = 0;
            }
            else {
                Y[i][j] = A[i][j];
            }
        }
    }
}

template <typename T> void cpp02_17(const T** A, const T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (i > j) {
                Y[i][j] = 0;
            }
            else {
                Y[i][j] = A[i][j];
            }
        }
    }
}

template <typename T> void cpp02_18(T** A, T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            if (i < j) {
                Y[i][j] = 0;
            }
            else {
                Y[i][j] = A[i][j];
            }
        }
    }
}

template <typename T> void cpp02_19(const T** A, const T** Y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (int j = i % 2 == 0 ? 0 : 1; j < cols; j += 2) {
            Y[i][j] = 0;
        }
        for (int j = i % 2 == 0 ? 1 : 0; j < cols; j += 2) {
            Y[i][j] = A[i][j];
        }
    }
}

template <typename T> void cpp02_20(const T** A, const T* h, const T* y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y[j] += A[i][j] * h[j];
        }
    }
}

template <typename T> void cpp02_21(const T** A, const T** h, const T** y, const uint rows, const uint cols) {
    for (uint i = 0; i < rows; ++i) {
        for (uint j = 0; j < cols; ++j) {
            y[0][j] += h[0][i] * A[i][j];
        }
    }
}

template <typename T> void cpp02_22(const T** A, const T** B, const T** Y, const uint rowsA, const uint colsA, const uint colsB) {
    for (uint i = 0; i < rowsA; ++i) {
        for (uint j = 0; j < colsB; ++j) {
            for (uint k = 0; k < colsA; ++k) {
                Y[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
