//
// Created by Dominik Müller on 13.10.17.
//

#include "Volladdierer.h"

/**
 * Initializes the Volladdierer and set the previous carry bit to 0 by default.
 */
Volladdierer::Volladdierer()
{
    this->previousCarry = false;
    this->primary = Halbaddierer();
    this->secondary = Halbaddierer();
}

/**
 * Sets the inputs to the first Halbaddierer.
 *
 * @param first
 * @param second
 */
void Volladdierer::setInputs(bool first, bool second)
{
    primary.setInputs(first, second);
}

/**
 * Sets/Overrides the previous carry.
 *
 * @param carry
 */
void Volladdierer::setPreviousCarry(bool carry)
{
    this->previousCarry = carry;
}

/**
 * Calculates the first Halbaddierer, then with the result, the second Halbaddierer.
 *
 * Return result and caluclate next carry.
 *
 * @return std::pair<bool, bool> Result and Carry.
 */
std::pair<bool, bool> Volladdierer::operate()
{
    // Calculating the first Halbaddierer
    auto primResult = this->primary.operate();

    // Calculating the second Halbaddierer
    this->secondary.setInputs(primResult.first, this->previousCarry);
    auto secResult = this->secondary.operate();

    // The final result of the two Halbaddierer.
    bool result = secResult.first;

    // If during the calculation another carry got created.
    bool carry = primResult.second || secResult.second;

    return std::pair<bool, bool>(result, carry);
}



