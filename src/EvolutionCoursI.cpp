//
// Created by chenghaowang on 29/03/19.
//

#include "../include/EvolutionCoursI.h"

EvolutionCoursI::EvolutionCoursI(const PaireDevises &paireDevises) : paireDevises(paireDevises) {}

EvolutionCoursI::EvolutionCoursI(const EvolutionCoursI &e)  : paireDevises(e.getPaireDevises()), nbCours(e.getNbCours()), nbMaxCours(e.getNbMaxCours()),
            cours(new CoursOHLC[e.getNbCours()]){
        for (unsigned int i = 0; i < nbCours; i++)
            cours[i] = e.getCoursAt(i);
}

EvolutionCoursI &EvolutionCoursI::operator=(const EvolutionCoursI &p) {
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

void EvolutionCoursI::addCours(double openPrice, double highPrice, double lowPrice, double closePrice) {
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

EvolutionCoursI::~EvolutionCoursI() {
    delete[](cours);
}

const PaireDevises &EvolutionCoursI::getPaireDevises() const {
    return paireDevises;
}

CoursOHLC *EvolutionCoursI::getCours() const {
    return cours;
}

unsigned int EvolutionCoursI::getNbMaxCours() const {
    return nbMaxCours;
}

unsigned int EvolutionCoursI::getNbCours() const {
    return nbCours;
}

CoursOHLC& EvolutionCoursI::getCoursAt(int index) const {
    if(index < 0 || index > nbCours - 1) throw TradingException("out of array!");
    return cours[index];
}

std::ostream &operator<<(std::ostream &os, EvolutionCoursI &i) {
    for(EvolutionCoursI::Iterator it= i.getIterator();!it.isDone();it.next()){
        os <<it.current()<<"\n";
        //it.current().setCours(0,0,0,0); // modification possible
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const EvolutionCoursI &i) {
    for(EvolutionCoursI::ConstIterator it= i.getIterator();!it.isDone();it.next()){
        os <<it.current()<<"\n";
        //it.current().setCours(0,0,0,0); // modification impossible
    }
    return os;
}
