//
// Created by chenghaowang on 29/03/19.
//

#include "../include/EvolutionCours.h"

EvolutionCours::EvolutionCours(const PaireDevises &paireDevises) : paireDevises(paireDevises) {}

EvolutionCours::EvolutionCours(const EvolutionCours &e)  : paireDevises(e.getPaireDevises()), nbCours(e.getNbCours()), nbMaxCours(e.getNbMaxCours()),
            cours(new CoursOHLC[e.getNbCours()]){
        for (unsigned int i = 0; i < nbCours; i++)
            cours[i] = e.getCoursAt(i);
}

EvolutionCours &EvolutionCours::operator=(const EvolutionCours &p) {
    if (&p != this) {
        if (nbMaxCours <getNbCours()) {
            delete[] cours;
            cours = new CoursOHLC[p.getNbCours()] ;
            nbMaxCours = p.getNbMaxCours();
        }
        nbCours = p.getNbCours();
        for (unsigned int i = 0; i < nbCours; i++)
            cours[i] = p.getCoursAt(i);
    }
    return *this;
}

void EvolutionCours::addCours(double openPrice, double highPrice, double lowPrice, double closePrice) {
    if (nbCours == nbMaxCours) {
        CoursOHLC* newtab = new CoursOHLC[nbMaxCours + 50];
        for (unsigned int i = 0; i < nbCours; i++)
            newtab[i] = cours[i];
        CoursOHLC* old = cours;
        nbMaxCours += 50;
        cours = newtab;
        delete[] old;
    }
    cours[nbCours++] = CoursOHLC(openPrice, highPrice, lowPrice, closePrice);
}

EvolutionCours::~EvolutionCours() {
    delete[](cours);
}

const PaireDevises &EvolutionCours::getPaireDevises() const {
    return paireDevises;
}

CoursOHLC *EvolutionCours::getCours() const {
    return cours;
}

unsigned int EvolutionCours::getNbMaxCours() const {
    return nbMaxCours;
}

unsigned int EvolutionCours::getNbCours() const {
    return nbCours;
}

CoursOHLC& EvolutionCours::getCoursAt(int index) const {
    if(index < 0 || index > nbCours - 1) return nullptr;
    return cours[index];
}
