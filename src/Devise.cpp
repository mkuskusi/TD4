//
// Created by chenghaowang on 29/03/19.
//

#include "../include/Devise.h"
#include "../include/TradingException.h"

Devise::Devise(char *code, const std::string &monnaie, const std::string &zone) : code(code), monnaie(monnaie),
                                                                                  zone(zone) {}

const char *Devise::getCode() const {
    return code;
}

const std::string &Devise::getMonnaie() const {
    return monnaie;
}

const std::string &Devise::getZone() const {
    return zone;
}

std::ostream &operator<<(std::ostream &os, const Devise &devise) {
    os << "code: " << devise.code << " monnaie: " << devise.monnaie << " zone: " << devise.zone;
    return os;
}
