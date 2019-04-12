//
// Created by chenghaowang on 29/03/19.
//

#include "../include/EvolutionCoursIII.h"

EvolutionCoursIII::EvolutionCoursIII(const PaireDevises &paireDevises) : paireDevises(paireDevises) {}

EvolutionCoursIII::EvolutionCoursIII(const EvolutionCoursIII &e)  : paireDevises(e.getPaireDevises()), nbCours(e.getNbCours()), nbMaxCours(e.getNbMaxCours()),
            cours(new CoursOHLC[e.getNbCours()]){
        for (unsigned int i = 0; i < nbCours; i++)
            cours[i] = e.getCoursAt(i);
}

EvolutionCoursIII &EvolutionCoursIII::operator=(const EvolutionCoursIII &p) {
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

void EvolutionCoursIII::addCours(double openPrice, double highPrice, double lowPrice, double closePrice) {
    if (nbCours == nbMaxCours) {
        auto * newtab = new CoursOHLC[nbMaxCours + 50];
        for (unsigned int i = 0; i < nbCours; i++)
            newtab[i] = cours[i];
        CoursOHLC* old = cours;
        nbMaxCours += 50;
        cours = newtab;
        delete[] old;
    }
    cours[nbCours++] = CoursOHLC(openPrice, highPrice, lowPrice, closePrice);
}

EvolutionCoursIII::~EvolutionCoursIII() {
    delete[](cours);
}

const PaireDevises &EvolutionCoursIII::getPaireDevises() const {
    return paireDevises;
}

CoursOHLC *EvolutionCoursIII::getCours() const {
    return cours;
}

unsigned int EvolutionCoursIII::getNbMaxCours() const {
    return nbMaxCours;
}

unsigned int EvolutionCoursIII::getNbCours() const {
    return nbCours;
}

CoursOHLC& EvolutionCoursIII::getCoursAt(int index) const {
    if(index < 0 || index > nbCours - 1) throw  TradingException("out of array!");
    return cours[index];
}

std::ostream &operator<<(std::ostream &os, EvolutionCoursIII &i) {
    for(EvolutionCoursIII::SearchIterator it= i.getIterator(EvolutionCoursIII::pente::
                                                            croissante);!it.isDone();it.next()){
        os<<it.current()<<"\n"; //ok
    }
    for(EvolutionCoursIII::SearchIterator it= i.getIterator(EvolutionCoursIII::pente::
                                                            decroissante);!it.isDone();it.next()){
        os<<it.current()<<"\n"; //ok
    }

    return os;
}