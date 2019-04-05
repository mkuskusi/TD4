//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_DEVISE_H
#define TD4_DEVISE_H

#include <iostream>
#include <cstring>
class Devise {
    char code[4];
    std::string monnaie;
    std::string zone;

public:

    Devise(char *code, const std::string &monnaie, const std::string &zone);

    const char *getCode() const;

    const std::string &getMonnaie() const;

    const std::string &getZone() const;

    friend std::ostream &operator<<(std::ostream &os, const Devise &devise);

};


#endif //TD4_DEVISE_H
