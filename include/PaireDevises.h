//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_PAIREDEVISES_H
#define TD4_PAIREDEVISES_H

#include <cstring>
#include <iostream>
#include "Devise.h"

class PaireDevises {
    const Devise* base;
    const Devise* contrepartie;
    std::string surnom;

public:

    PaireDevises(const Devise *base, const Devise *contrepartie, const std::string &surnom);

    const Devise *getBase() const;

    const Devise *getContrepartie() const;

    const std::string &getSurnom() const;

    friend std::ostream &operator<<(std::ostream &os, const PaireDevises &devises);
};

#endif //TD4_PAIREDEVISES_H
