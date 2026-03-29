// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
    const char* str1 = "Hello World! What i6 the weather5676 like 574today?";
    std::cout << "Func1: " << faStr1(str1) << std::endl;
    std::cout << "Func2: " << faStr2(str1) << std::endl;
    std::cout << "Func3: " << faStr3(str1) << std::endl;
}
