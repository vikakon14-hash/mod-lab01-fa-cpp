// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char* str) {
    if (str == nullptr) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool hasNum = false;
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i++) {
        char currentChar = str[i];
        if (std::isspace(currentChar)) {
            if (inWord && !hasNum) {
                count++;
            }
            inWord = false;
            hasNum = false;
        } else {
            if (!inWord) {
                inWord = true;
                hasNum = false;
            }
            if (std::isdigit(currentChar)) {
                hasNum = true;
            }
        }
    }
    if (inWord && !hasNum) {
        count++;
    }
    return count;
}

unsigned int faStr2(const char* str) {
    if (str == nullptr) return 0;
    unsigned int count = 0;
    bool inWord = false;
    bool correct = true;
    int charIndex = 0;

    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (std::isspace(ch)) {
            if (inWord && correct) {
                count++;
            }
            inWord = false;
            correct = true;
            charIndex = 0;
        } else {
            if (!inWord) {
                inWord = true;
                correct = true;
                charIndex = 0;
            }
            if (charIndex == 0) {
                if (!(ch >= 'A' && ch <= 'Z')) {
                    correct = false;
                }
            } else {
                if (!(ch >= 'a' && ch <= 'z')) {
                    correct = false;
                }
            }
            charIndex++;
        }
    }
    if (inWord && correct) {
        count++;
    }
    return count;
}

unsigned int faStr3(const char* str) {
    if (str == nullptr) return 0;
    unsigned int totalLen = 0;
    unsigned int currentLen = 0;
    unsigned int count = 0;
    bool inWord = false;

    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (std::isspace(ch)) {
            if (inWord) {
                totalLen += currentLen;
                count++;
                inWord = false;
                currentLen = 0;
            }
        } else {
            if (!inWord) {
                inWord = true;
                currentLen = 0;
            }
            currentLen++;
        }
    }
    if (inWord) {
        totalLen += currentLen;
        count++;
    }
    if (count == 0) return 0;
    double averageLen = static_cast<double>(totalLen) / count;
    return (unsigned int)std::round(averageLen);
}
