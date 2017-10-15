#include <iostream>
#include "Addierwerk.h"

int main() {
    int first = 5;
    int second = -3;

    auto werk = Addierwerk();
    werk.setInputs(first, second);

    auto result = static_cast<int>(werk.operate());

    std::cout << result;

    return 0;
}