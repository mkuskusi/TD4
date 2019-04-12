//
// Created by chenghaowang on 29/03/19.
//

#include "../include/Devise.h"
#include "../include/TradingException.h"

Devise::Devise(char *code, const std::string &monnaie, const std::string &zone) : monnaie(monnaie),
                                                                                  zone(zone) {
    this->code[0] = code[0];
    this->code[1] = code[1];
    this->code[2] = code[2];
    this->code[3] = '\0';

}

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

bool Devise::operator==(const Devise &rhs) const {
    return code[0] == rhs.code[0] && code[1] == rhs.code[1] && code[2] == rhs.code[2] ;
}

bool Devise::operator!=(const Devise &rhs) const {
    return !(rhs == *this);
}
