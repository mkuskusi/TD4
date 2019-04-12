//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_EVOLUTIONCOURSIII_H
#define TD4_EVOLUTIONCOURSIII_H


#include "PaireDevises.h"
#include "CoursOHLC.h"
#include "TradingException.h"

/**
 * @brief The class of evolution of courses for a share.
 */
class EvolutionCoursIII {
    /**
     * @brief the object in terms of pair of currencies.
     */
    const PaireDevises & paireDevises;
    /**
     * @brief the course table.
     */
    CoursOHLC *cours= nullptr;
    /**
     * @brief the max number of cours.
     */
    unsigned  int nbMaxCours=0;
    /**
     * @brief the current number of cours in the table.
     */
    unsigned  int nbCours=0;

    enum class pente { croissante, decroissante };

    /**
     * @brief a nested class to support a design pattern in terms of iterator.
     */
    class SearchIterator{
        /**
         * @brief a pre-declaration of friend class of EvolutionCoursI such that the class EvolutionCoursI can visit the private members of class Iterator.
         * to make the class Iterator as a dedicate nested class for EvolutionCoursI.
         */
        friend class EvolutionCoursIII;

        /**
         * @brief the instance of super carrier associated with the nested class.
         */
        EvolutionCoursIII *evolution = nullptr;
        int i = 0;
        pente direction=pente::croissante;
        SearchIterator(EvolutionCoursIII* e, pente p) :
                direction(p) {
            *this->evolution = *e;
            while (i < evolution->nbCours &&
                   ((direction == pente::croissante && evolution->cours[i].getClosePrice() < evolution
                           ->cours[i].getOpenPrice()) ||
                    (direction == pente::decroissante && evolution->cours[i].getClosePrice() > evolution
                            ->cours[i].getOpenPrice()))) i++;
        }



    public:
        SearchIterator()= default;
        void next() {
            if (isDone())
                throw TradingException("error, next on an iterator which is done");
            i++;
            while (i < evolution->nbCours &&
                   ((direction == pente::croissante && evolution->cours[i].getClosePrice() < evolution
                           ->cours[i].getOpenPrice()) ||
                    (direction == pente::decroissante && evolution->cours[i].getClosePrice() > evolution
                            ->cours[i].getOpenPrice()))) i++;
        }

        bool isDone() const{
            return evolution  == nullptr || i == evolution->getNbCours();
        }

        CoursOHLC& current() const {
            if (isDone())
                throw TradingException("error, indirection on an iterator which is done");
            return evolution->cours[i];
        }

    };


public:
    /**
     * @brief Constructor with parameters.
     * @param paireDevises see class PaireDevises.
     */
    explicit EvolutionCoursIII(const PaireDevises &paireDevises);

    /**
     * @brief Constructor of recopy.
     * @param e the object in terms of EvolutionCoursIII.
     */
    EvolutionCoursIII(const EvolutionCoursIII& e);

    /**
     * @brief An override of assignment operator.
     * @param p the object in terms of EvolutionCoursIII.
     * @return  a copied object in terms of EvolutionCoursIII.
     */
    EvolutionCoursIII& operator=(const EvolutionCoursIII& p);

    /**
     * @brief Add a course into table of courses.
     * @param openPrice the open price of a new course.
     * @param highPrice the high price of a new course.
     * @param lowPrice the low price of a new course.
     * @param closePrice the close price of a new course.
     */
    void addCours(double openPrice, double highPrice, double lowPrice, double closePrice);

    /**
     * @brief Destructor.
     */
    ~EvolutionCoursIII();

    /**
     * @brief Getter for attribute of paireDevises.
     * @return the corresponding value for attribute of paireDevises.
     */
    const PaireDevises &getPaireDevises() const;

    /**
     * @brief Getter for attribute of cours.
     * @return the corresponding value for attribute of cours.
     */
    CoursOHLC *getCours() const;

    /**
     * @brief Getter for attribute of nbMaxCours.
     * @return the corresponding value for attribute of nbMaxCours.
     */
    unsigned int getNbMaxCours() const;

    /**
     * @brief Getter for attribute of nbCours.
     * @return the corresponding value for attribute of nbCours.
     */
    unsigned int getNbCours() const;

    /**
     * @brief Get the course at its index.
     * @param index the index of queried course.
     * @return the corresponding course.
     */
    CoursOHLC& getCoursAt(int index) const;

    /**
     * @brief Get the iterator of table for courses.
     * @return the corresponding iterator.
     */
    SearchIterator & getIterator(pente p) {
        SearchIterator(this, p);
    }

    friend std::ostream &operator<<(std::ostream &os, EvolutionCoursIII &i);

};



#endif //TD4_EVOLUTIONCOURS_H
