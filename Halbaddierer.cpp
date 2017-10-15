//
// Created by Dominik Müller on 13.10.17.
//

#include <stdexcept>
#include "Halbaddierer.h"

/**
 * Sets the first and second input of the Halbaddierer.
 *
 * @param first
 * @param second
 */
void Halbaddierer::setInputs(bool first, bool second)
{
    this->initialized = true;

    this->first  = first;
    this->second = second;
}

/**
 * Adds the two inputs and returns the result and the carry.
 *
 * @return std::pair<bool, bool> Result and Carry.
 */
std::pair<bool, bool> Halbaddierer::operate()
{
    if (!this->initialized) {
        std::logic_error("The Halbaddierer has not been initialized. Please set the inputs first.");
    }

    // XOR
    bool result = this->first != this->second;
    // Carry
    bool carry = this->first && this->second;

    return std::pair<bool, bool>(result, carry);
}
