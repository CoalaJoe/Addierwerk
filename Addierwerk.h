//
// Created by Dominik Müller on 13.10.17.
//

#ifndef THE_LEGEND_OF_TUX_ADDIERWERK_H
#define THE_LEGEND_OF_TUX_ADDIERWERK_H


#include <vector>
#include "Volladdierer.h"

class Addierwerk {
private:
    std::string binaryFirst;
    std::string binarySecond;
    std::vector<Volladdierer> werk;

    bool getLastCharacterAsBool(std::string &binaryString);
    std::string boolToString(bool boolean);
public:
    Addierwerk();

    void setInputs(int first, int second);
    unsigned long long int  operate();
};


#endif //THE_LEGEND_OF_TUX_ADDIERWERK_H
