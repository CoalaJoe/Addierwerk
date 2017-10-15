//
// Created by Dominik Müller on 13.10.17.
//

#ifndef THE_LEGEND_OF_TUX_HALBADDIERER_H
#define THE_LEGEND_OF_TUX_HALBADDIERER_H


#include <utility>

class Halbaddierer {
private:
    bool initialized = false;
    bool first;
    bool second;

public:
    void setInputs(bool first, bool second);
    std::pair<bool, bool> operate();
};


#endif //THE_LEGEND_OF_TUX_HALBADDIERER_H
