//
// Created by chenghaowang on 29/03/19.
//

#include "../include/PaireDevises.h"

PaireDevises::PaireDevises(const Devise &base, const Devise &contrepartie, const std::string &surnom) : base(base),
                                                                                                        contrepartie(
                                                                                                                contrepartie),
                                                                                                        surnom(surnom) {}

const Devise &PaireDevises::getBase() const {
    return base;
}

const Devise &PaireDevises::getContrepartie() const {
    return contrepartie;
}

const std::string &PaireDevises::getSurnom() const {
    return surnom;
}

std::ostream &operator<<(std::ostream &os, const PaireDevises &devises) {
    os << "base: " << devises.base << " contrepartie: " << devises.contrepartie << " surnom: " << devises.surnom;
    return os;
}

bool PaireDevises::operator==(const PaireDevises &rhs) const {
    return base == rhs.base &&
           contrepartie == rhs.contrepartie;
}

bool PaireDevises::operator!=(const PaireDevises &rhs) const {
    return !(rhs == *this);
}


