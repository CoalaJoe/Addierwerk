//
// Created by Dominik Müller on 13.10.17.
//

#ifndef VOLLADDIERER_H
#define VOLLADDIERER_H


#include "Halbaddierer.h"

class Volladdierer {
private:
    bool         first;
    bool         second;
    bool previousCarry;
    Halbaddierer primary;
    Halbaddierer secondary;
public:
    Volladdierer();

    void setInputs(bool first, bool second);
    void setPreviousCarry(bool carry);
    std::pair<bool, bool> operate();
};


#endif //VOLLADDIERER_H
