#pragma once

template <typename T> int64 cpp06_04_bool(const uint n, T* const a, const T val) {
    for (uint i = 0u; i < n; ++i) {
        if (a[i] == val) {
            return 1;
        }
    }
    return 0;
}

template <typename T> int64 cpp06_04_idx(const uint n, T* const a, const T val) {
    for (uint i = 0u; i < n; ++i) {
        if (a[i] == val) {
            return i;
        }
    }
    return 0;
}

template <typename T> int64 cpp06_04_cnt_eq(const uint n, T* const a, const T val) {
    int64 y = 0;
    for (uint i = 0u; i < n; ++i) {
        if (a[i] == val) {
            y++;
        }
    }
    return y;
}

template <typename T> int64 cpp06_04_cnt_neq(const uint n, T* const a, const T val) {
    int64 y = 0;
    for (uint i = 0u; i < n; ++i) {
        if (a[i] != val) {
            y++;
        }
    }
    return y;
}

template <typename T> int64 cpp06_05_cnt_even(const uint n, T* const a) {
    int64 y = 0;
    for (uint i = 0u; i < n; ++i) {
        if (a[i] % 2 == 0) {
            y++;
        }
    }
    return y;
}

template <typename T> int64 cpp06_05_cnt_odd(const uint n, T* const a) {
    int64 y = 0;
    for (uint i = 0u; i < n; ++i) {
        if (a[i] % 2 != 0) {
            y++;
        }
    }
    return y;
}

template <typename T> int64 cpp06_05_cnt_less(const uint n, T* const a, const T val) {
    int64 y = 0;
    for (uint i = 0u; i < n; ++i) {
        if (a[i] < val) {
            y++;
        }
    }
    return y;
}

template <typename T> int64 cpp06_05_cnt_greater(const uint n, T* const a, const T val) {
    int64 y = 0;
    for (uint i = 0u; i < n; ++i) {
        if (a[i] > val) {
            y++;
        }
    }
    return y;
}

template <typename T> void cpp06_05_fun(const uint n, T* const a, T* const b) {
    for (uint i = 0u; i < n; ++i) {
        b[i] = (4 * a[i] + 5) / 2;
    }
}

template <typename T> void cpp06_05_cpy(const uint n, T* const a, T* const b) {
    const uint limit = a == b ? n / 2u : n;
    for (uint i = 0u, j = n - 1u; i < limit; ++i, --j) {
        T tmp = a[i];
        a[i] = b[j];
        b[j] = tmp;
    }
}

template <typename T> void movsWrapper(const uint n, void(*asmFun)(uint, T*, T*), const char* title) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - MOVS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor();
    auto* a = newFillPtr<T>(n);
    auto* b = newPtr<T>(n);
    printPtr(a, n);
    auto startTime = getTime();
    asmFun(n, a, b);
    auto endTime = getTime();
    std::cout << "Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(a, b, n);
    freePtr(a);
    freePtr(b);
    std::cout << std::endl;
}

template <typename T> void stosWrapper(const uint n, void(*asmFun)(uint, T*, T), const char* title, const T v = 0x41) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - STOS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor();
    auto* a = newFillPtr<T>(n, false, v);
    auto* b = newPtr<T>(n);
    printPtr(a, n);
    auto startTime = getTime();
    asmFun(n, b, v);
    auto endTime = getTime();
    std::cout << "Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(a, b, n);
    freePtr(a);
    freePtr(b);
    std::cout << std::endl;
}

template <typename T> void cmpsBoolWrapper(const uint n, int64(*asmFun)(uint, T*, T*), const char* title, const bool positiveScenario = true) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - CMPS" << getTypeLiteral(sizeof(T)) << (positiveScenario ? " - POSITIVE" : " - NEGATIVE") << " - - -" << std::endl;
    setConsoleTextColor();
    int64 expected = 1ll;
    auto* a = newFillPtr<T>(n);
    auto* b = newCopyPtr<T>(a, n);
    if (!positiveScenario) {
        expected = 0ll;
        b[rand() % n] += 1;
    }
    printPtr(a, n);
    printPtr(b, n);
    auto startTime = getTime();
    auto y = asmFun(n, a, b);
    auto endTime = getTime();
    std::cout << "Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(expected, y);
    freePtr(a);
    freePtr(b);
    std::cout << std::endl;
}

template <typename T> void cmpsIdxWrapper(const uint n, int64(*asmFun)(uint, T*, T*), const char* title, const bool positiveScenario = true) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - CMPS" << getTypeLiteral(sizeof(T)) << (positiveScenario ? " - POSITIVE" : " - NEGATIVE") << " - - -" << std::endl;
    setConsoleTextColor();
    int64 expected = 1ll;
    auto* a = newFillPtr<T>(n);
    auto* b = newCopyPtr<T>(a, n);
    if (!positiveScenario) {
        expected = static_cast<int64>(rand() % n);
        b[expected] += 1;
    }
    std::cout << "a: ";
    printPtr(a, n);
    std::cout << "b: ";
    printPtr(b, n);
    auto startTime = getTime();
    auto y = asmFun(n, a, b);
    auto endTime = getTime();
    std::cout << "Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(expected, y);
    freePtr(a);
    freePtr(b);
    std::cout << std::endl;
}

template <typename T> void scasBoolWrapper(const uint n, int64(*asmFun)(uint, T*, T), const char* title, const bool positiveScenario = true) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - SCAS" << getTypeLiteral(sizeof(T)) << (positiveScenario ? " - POSITIVE" : " - NEGATIVE") << " - - -" << std::endl;
    setConsoleTextColor();
    T* a;
    T v;
    if (positiveScenario) {
        a = newFillPtr<T>(n);
        const uint idx = rand() % n;
        v = a[idx];
        std::cout << "a[" << idx << "] = " << v << std::endl;
    }
    else {
        a = newFillPtr<T>(n, false, 0);
        v = static_cast<T>(1);
    }
    printPtr(a, n);
    auto startTime = getTime();
    auto yAsm = asmFun(n, a, v);
    auto endTime = getTime();
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    auto yCpp = cpp06_04_bool(n, a, v);
    endTime = getTime();
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(yCpp, yAsm);
    freePtr(a);
    std::cout << std::endl;
}

template <typename T> void scasIdxWrapper(const uint n, int64(*asmFun)(uint, T*, T), const char* title, const bool positiveScenario = true) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - SCAS" << getTypeLiteral(sizeof(T)) << (positiveScenario ? " - POSITIVE" : " - NEGATIVE") << " - - -" << std::endl;
    setConsoleTextColor();
    T* a;
    T v;
    if (positiveScenario) {
        a = newFillPtr<T>(n);
        const uint idx = rand() % n;
        v = a[idx];
        std::cout << "a[" << idx << "] = " << v << std::endl;
    }
    else {
        a = newFillPtr<T>(n, false, 0);
        v = static_cast<T>(1);
    }
    printPtr(a, n);
    auto startTime = getTime();
    int64 yAsm = asmFun(n, a, v);
    auto endTime = getTime();
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    auto yCpp = cpp06_04_idx(n, a, v);
    endTime = getTime();
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(yCpp, yAsm);
    freePtr(a);
    std::cout << std::endl;
}

template <typename T> void scasCntWrapper(const uint n, int64(*asmFun)(uint, T*, T), const char* title, int64(*cppFun)(uint, T*, T), const T val = T()) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - SCAS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor();
    auto* a = newFillPtr<T>(n);
    printPtr(a, n);
    auto startTime = getTime();
    int64 yAsm = asmFun(n, a, val);
    auto endTime = getTime();
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    auto yCpp = cppFun(n, a, val);
    endTime = getTime();
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(yCpp, yAsm);
    freePtr(a);
    std::cout << std::endl;
}

template <typename T> void lodsParityWrapper(const uint n, int64(*asmFun)(uint, T*), const char* title, int64(*cppFun)(uint, T*)) {
    setConsoleTextColor(GOLD); 
    std::cout << "- - - " << __func__ << " - " << title << " - LODS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor(); 
    auto* a = newFillPtr<T>(n);
    printPtr(a, n);
    auto startTime = getTime();
    int64 yAsm = asmFun(n, a);
    auto endTime = getTime();
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    auto yCpp = cppFun(n, a);
    endTime = getTime();
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(yCpp, yAsm);
    freePtr(a);
    std::cout << std::endl;
}

template <typename T> void lodsCntWrapper(const uint n, int64(*asmFun)(uint, T*, T), const char* title, int64(*cppFun)(uint, T*, T), const T val = T()) {
    setConsoleTextColor(GOLD); 
    std::cout << "- - - " << __func__ << " - " << title << " - LODS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor();
    auto* a = newFillPtr<T>(n);
    printPtr(a, n);
    auto startTime = getTime();
    int64 yAsm = asmFun(n, a, val);
    auto endTime = getTime();
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    auto yCpp = cppFun(n, a, val);
    endTime = getTime();
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(yCpp, yAsm);
    freePtr(a);
    std::cout << std::endl;
}

template <typename T> void lodsOtherWrapper(const uint n, void(*asmFun)(uint, T*, T*), const char* title, void(*cppFun)(uint, T*, T*)) {
    setConsoleTextColor(GOLD);
    std::cout << "- - - " << __func__ << " - " << title << " - LODS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor(); 
    auto* a = newFillPtr<T>(n);
    auto* b = newCopyPtr<T>(a, n);
    auto* y = newPtr<T>(n);
    printPtr(a, n);
    auto startTime = getTime();
    asmFun(n, a, y);
    auto endTime = getTime();
    printPtr(y, n);
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    cppFun(n, b, b);
    endTime = getTime();
    printPtr(b, n);
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(b, y, n);
    freePtr(a);
    freePtr(b);
    freePtr(y);
    std::cout << std::endl;
}

template <typename T> void lodsInSituWrapper(const uint n, void(*asmFun)(uint, T*), const char* title, void(*cppFun)(uint, T*, T*)) {
    setConsoleTextColor(GOLD); 
    std::cout << "- - - " << __func__ << " - " << title << " - LODS" << getTypeLiteral(sizeof(T)) << " - - -" << std::endl;
    setConsoleTextColor(); 
    auto* a = newFillPtr<T>(n);
    auto* b = newCopyPtr<T>(a, n);
    printPtr(a, n);
    auto startTime = getTime();
    asmFun(n, a);
    auto endTime = getTime();
    printPtr(a, n);
    std::cout << "[ASM] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    startTime = getTime();
    cppFun(n, b, b);
    endTime = getTime();
    printPtr(b, n);
    std::cout << "[C++] Time duration: " << getDurationNs(startTime, endTime) << " ns" << std::endl;
    resultComparator(b, a, n);
    freePtr(a);
    freePtr(b);
    std::cout << std::endl;
}

const uint len = 40u;
const uint testCasesCnt = 3;

// NOTE. The strings array need to be initialized every time because procedures are modyfing them.
void trimWrapper(void (*asmTrimFun)(uint, char*), const char* title) {
    for (uint i = 0u; i < testCasesCnt; ++i) {
        char strings[testCasesCnt][len] = {
            "                    Asembler jest super",
            "Asembler jest super                    ",
            "          Asembler jest super          "
        };
        setConsoleTextColor(GOLD);
        std::cout << "- - - " << __func__ << " - " << title << " - - -" << std::endl;
        setConsoleTextColor();
        std::cout << strings[i] << "!" << std::endl;
        asmTrimFun(len, strings[i]);
        std::cout << strings[i] << "!" << std::endl;
        std::cout << std::endl;
    }
}

// NOTE. The strings array need to be initialized every time because procedures are modyfing them.
void replaceWrapper(const char oldChar, const char newchar, void (*asmReplaceFun)(uint, char*, char, char), const char* title) {
    for (uint i = 0u; i < testCasesCnt; ++i) {
        char strings[testCasesCnt][len] = {
            "                    Asembler jest super",
            "Asembler jest super                    ",
            "          Asembler jest super          "
        };
        setConsoleTextColor(GOLD);
        std::cout << "- - - " << __func__ << " - " << title << " - - -" << std::endl;
        setConsoleTextColor();
        std::cout << strings[i] << "!" << std::endl;
        asmReplaceFun(len, strings[i], oldChar, newchar);
        std::cout << strings[i] << "!" << std::endl;
        std::cout << std::endl;
    }
}