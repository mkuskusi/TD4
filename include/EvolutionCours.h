//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_EVOLUTIONCOURS_H
#define TD4_EVOLUTIONCOURS_H


#include "PaireDevises.h"
#include "CoursOHLC.h"

class EvolutionCours {
    const PaireDevises & paireDevises;
    CoursOHLC *cours= nullptr;
    unsigned  int nbMaxCours=0;
    unsigned  int nbCours=0;
public:
    explicit EvolutionCours(const PaireDevises &paireDevises);
    EvolutionCours(const EvolutionCours& e);
    EvolutionCours& operator=(const EvolutionCours& p);

    void addCours(double openPrice, double highPrice, double lowPrice, double closePrice);
    ~EvolutionCours();

    const PaireDevises &getPaireDevises() const;

    CoursOHLC *getCours() const;

    unsigned int getNbMaxCours() const;

    unsigned int getNbCours() const;

    const CoursOHLC& getCoursAt(int index) const;

};


#endif //TD4_EVOLUTIONCOURS_H
