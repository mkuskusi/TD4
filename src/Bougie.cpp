//
// Created by chenghaowang on 05/04/19.
//

#include "../include/Bougie.h"

Bougie::Bougie(const CoursOHLC &cours) : cours(cours) {}

const CoursOHLC &Bougie::getCours() const {
    return cours;
}

Couleur Bougie::getCouleur() const {
    return couleur;
}

void Bougie::setSeuilToupie(double seuilToupie) {
    Bougie::seuilToupie = seuilToupie;
}

std::string Bougie::getForme() const {
    if (abs(static_cast<int>(cours.getClosePrice() - cours.getOpenPrice())) < seuilToupie) return "Toupie";
    return "";
}

std::ostream &operator<<(std::ostream &os, const Bougie &bougie) {
    if (bougie.couleur == Couleur::rouge) os << "rouge"; else os << "vert";
    return os;
}
