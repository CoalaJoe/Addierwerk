//
// Created by Dominik Müller on 13.10.17.
//

#ifndef THE_LEGEND_OF_TUX_VOLLADDIERER_H
#define THE_LEGEND_OF_TUX_VOLLADDIERER_H


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


#endif //THE_LEGEND_OF_TUX_VOLLADDIERER_H
