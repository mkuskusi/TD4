//
// Created by chenghaowang on 05/04/19.
//

#ifndef TD4_BOUGIE_H
#define TD4_BOUGIE_H


#include <ostream>
#include "CoursOHLC.h"
#include "Couleur.h"

class Bougie {
    const CoursOHLC& cours;
    Couleur couleur;
    static double seuilToupie;

public:
    explicit Bougie(const CoursOHLC &cours);

    const CoursOHLC &getCours() const;

    Couleur getCouleur() const;

    std::string getForme() const;

    static void setSeuilToupie(double seuilToupie);

    friend std::ostream &operator<<(std::ostream &os, const Bougie &bougie);
};


#endif //TD4_BOUGIE_H
