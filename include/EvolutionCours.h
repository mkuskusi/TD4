//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_EVOLUTIONCOURS_H
#define TD4_EVOLUTIONCOURS_H


#include "PaireDevises.h"
#include "CoursOHLC.h"
#include "TradingException.h"

/**
 * @brief The class of
 */
class EvolutionCours {
    const PaireDevises & paireDevises;
    CoursOHLC *cours= nullptr;
    unsigned  int nbMaxCours=0;
    unsigned  int nbCours=0;
    class Iterator{
        // accessibility
        friend class EvolutionCours;
        EvolutionCours *evolutionCours = nullptr;
        int index=0;


        Iterator(EvolutionCours *evolutionCours){
            *this->evolutionCours = *evolutionCours;
        }


    public:
        Iterator()= default;
        void next(){
           if(isDone()){
               throw TradingException("out of array");
           }
           index++;
        }
        bool isDone(){
            return (evolutionCours == nullptr || index == evolutionCours->getNbCours()) ;
        }
        CoursOHLC& current(){
            return evolutionCours->getCoursAt(index);
        }
    };
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

    CoursOHLC& getCoursAt(int index) const;


    Iterator& getIterator(){
        Iterator(this);
    }


};



#endif //TD4_EVOLUTIONCOURS_H
