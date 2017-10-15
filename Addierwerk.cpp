//
// Created by Dominik Müller on 13.10.17.
//

#include <iostream>
#include "Addierwerk.h"

/**
 * Creates the Addierwerk and sets, how many Volladdierer it needs.
 *
 * @note The multiple Volladdierer are unpractical in programming. One could easily use just 1.
 *
 * @param bits
 */
Addierwerk::Addierwerk()
{
    for (int i = 0; i < 8; ++i) {
        this->werk.emplace_back(Volladdierer());
    }
}

/**
 * Gets the inputs as integers and converts them to binary.
 *
 * @param first
 * @param second
 */
void Addierwerk::setInputs(int first, int second)
{
    this->binaryFirst  = std::bitset<8>(first).to_string();
    this->binarySecond = std::bitset<8>(second).to_string();

    std::cout << "First input: \t" << this->binaryFirst << "\n";
    std::cout << "Second input: \t" << this->binarySecond << "\n";
}

unsigned long long int Addierwerk::operate()
{
    std::string binaryResult;

    std::pair<bool, bool> tempResult; // Used to store the intermediate results from between the Volladdierer.
    bool lastCarry = 0;

    for (int i = 0; i < 8; ++i) {
        // Gets the next numbers to add.
        auto leastFirst = getLastCharacterAsBool(this->binaryFirst);
        auto leastSecond = getLastCharacterAsBool(this->binarySecond);

        // Adds the new values to the next Addierwerk.
        this->werk[i].setInputs(leastFirst, leastSecond);
        this->werk[i].setPreviousCarry(lastCarry);

        tempResult = this->werk[i].operate();

        // Set the carry from the last computation.
        lastCarry = tempResult.second;

        binaryResult.insert(0, this->boolToString(tempResult.first));
    }

    std::cout << "Result: \t\t" << binaryResult << "\n";
    std::bitset<8> result(binaryResult);

    return result.to_ullong();
}

/**
 * Gets last character. Removes it from the string and returns true, if it was a 1.
 *
 * @note This function only works with 0 and 1.
 *
 * @param binaryString
 * @return
 */
bool Addierwerk::getLastCharacterAsBool(std::string &binaryString)
{
    char ch = binaryString.back();
    binaryString.pop_back();

    return ch == '1';
}

/**
 * Turns booleans to strings.
 *
 * @param boolean
 * @return
 */
std::string Addierwerk::boolToString(bool boolean)
{
    return boolean ? "1" : "0";
}



