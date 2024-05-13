#pragma once

/// <summary>
/// Calculate the sum of the matrix elements.
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="A"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns></returns>
template <typename T>
T sumElems(T** A, const int rows, const int cols) {
    T s = T();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            s += A[i][j];
        }
    }
    return s;
}

/// <summary>
/// Sum of matrices where
/// A + B = C 
/// [m x n] + [m x n] = [m x n]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="W"></param>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
template <typename T>
void addMatMat(T** W, T** A, T** B, const int rows, const int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            W[i][j] = A[i][j] + B[i][j];
        }
    }
}

/// <summary>
/// Right handed multiplication of matrix by vector where
/// A * u = w
/// [m x n] * [n x 1] = [m x 1]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="w"></param>
/// <param name="A"></param>
/// <param name="u"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
template <typename T>
void mulMatVec(T* w, T** A, T* u, const int rows, const int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            w[i] += A[i][j] * u[j];
        }
    }
}

/// <summary>
/// Multiplication of matrices where
/// A * B = W
/// [m x n] * [n x o] = [m x o]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="W"></param>
/// <param name="A"></param>
/// <param name="B"></param>
/// <param name="aRows"></param>
/// <param name="common"></param>
/// <param name="bCols"></param>
template <typename T>
void mulMatMat(T** W, T** A, T** B, const int aRows, const int common, const int bCols) {
    for (int i = 0; i < aRows; ++i) {
        for (int j = 0; j < bCols; ++j) {
            for (int k = 0; k < common; ++k) {
                W[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

/// <summary>
/// Transpozes matrix where
/// A^T = W
/// [m x n] -> [n x m]
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="W"></param>
/// <param name="A"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
template <typename T>
void transpoze(T** W, T** A, const int rows, const int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            W[j][i] = A[i][j];
        }
    }
}

/// <summary>
/// Perform floating point numbers safe comparison using default 6 digit precission (1e-4).
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <param name="eps"></param>
/// <returns></returns>
template <typename T>
bool almostEqual(const T a, const T b, const double eps = 1e-2) {
    return std::fabs(a - b) < eps;
}

/// <summary>
/// Checks whether all elements in the two vectors have the same values in corresponding positions
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="w"></param>
/// <param name="u"></param>
/// <param name="size"></param>
/// <returns>False if there is an element which satisfies the condition w[i] != u[i]. True otherwise.</returns>
template <typename T>
bool assertEquals(T* w, T* u, const int size) {
    for (int i = 0; i < size; ++i) {
        if (!almostEqual(w[i], u[i])) {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Checks whether all elements in the two matrices have the same values in corresponding positions
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="W"></param>
/// <param name="A"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns>False if there is an element which satisfies the condition W[i][j] != U[i][j]. True otherwise.</returns>
template <typename T>
bool assertEquals(T** W, T** A, const int rows, const int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!almostEqual(W[i][j], A[i][j])) {
                return false;
            }
        }
    }
    return true;
}