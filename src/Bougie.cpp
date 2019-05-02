//
// Created by chenghaowang on 05/04/19.
//

#include "../include/Bougie.h"
double Bougie::seuilToupie=1;

Bougie::Bougie(CoursOHLC &cours) : cours(cours) {}

CoursOHLC &Bougie::getCours() {
    return cours;
}

Couleur Bougie::getCouleur() const {
    return couleur;
}

void Bougie::setSeuilToupie(double seuilToupieNew) {
    seuilToupie = seuilToupieNew;
}

std::string Bougie::getForme() const {
    if (abs(static_cast<int>(cours.getClosePrice() - cours.getOpenPrice())) < seuilToupie) return "Toupie";
    return "";
}

std::ostream &operator<<(std::ostream &os, const Bougie &bougie) {
    if (bougie.couleur == Couleur::rouge) os << "rouge"; else os << "vert";
    return os;
}
