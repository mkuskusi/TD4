//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_EVOLUTIONCOURSI_H
#define TD4_EVOLUTIONCOURSI_H


#include <ostream>
#include "PaireDevises.h"
#include "CoursOHLC.h"
#include "TradingException.h"

/**
 * @brief The class of evolution of courses for a share.
 */
class EvolutionCoursI {
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
    /**
     * @brief a nested class to support a design pattern in terms of iterator.
     */
    class Iterator{
        /**
         * @brief a pre-declaration of friend class of EvolutionCoursI such that the class EvolutionCoursI can visit the private members of class Iterator.
         * to make the class Iterator as a dedicate nested class for EvolutionCoursI.
         */
        friend class EvolutionCoursI;

        /**
         * @brief the instance of super carrier associated with the nested class.
         */
        EvolutionCoursI *evolutionCours = nullptr;
        /**
         * @brief the index of current element.
         */
        int index=0;


        /**
         * @brief Constructor with parameters.
         * @param evolutionCoursI see class evolutionCoursI
         */
        explicit Iterator(EvolutionCoursI *evolutionCoursI):evolutionCours(evolutionCoursI){
        }
    public:
        Iterator()= default;
        void next(){
           if(isDone()){
               throw TradingException("out of array");
           }
           index++;
        }
        bool isDone() const{
            return evolutionCours == nullptr || index == evolutionCours->getNbCours();
        }
        CoursOHLC& current() const{
            return evolutionCours->getCoursAt(index);
        }
    };

    class ConstIterator{
        /**
         * @brief a pre-declaration of friend class of EvolutionCoursI such that the class EvolutionCoursI can visit the private members of class Iterator.
         * to make the class Iterator as a dedicate nested class for EvolutionCoursI.
         */
        friend class EvolutionCoursI;

        /**
         * @brief the instance of super carrier associated with the nested class.
         */
        const EvolutionCoursI *evolutionCours = nullptr;
        /**
         * @brief the index of current element.
         */
        int index=0;


        /**
         * @brief Constructor with parameters.
         * @param evolutionCoursI see class evolutionCoursI
         */
        explicit ConstIterator(const EvolutionCoursI *evolutionCoursI): evolutionCours(evolutionCoursI){
        }
    public:
        ConstIterator()= default;
        void next(){
            if(isDone()){
                throw TradingException("out of array");
            }
            index++;
        }
        bool isDone(){
            return evolutionCours == nullptr || index == evolutionCours->getNbCours();
        }
        const CoursOHLC& current(){
            return evolutionCours->getCoursAt(index);
        }
    };
public:
    /**
     * @brief Constructor with parameters.
     * @param paireDevises see class PaireDevises.
     */
    explicit EvolutionCoursI(const PaireDevises &paireDevises);

    /**
     * @brief Constructor of recopy.
     * @param e the object in terms of EvolutionCoursI.
     */
    EvolutionCoursI(const EvolutionCoursI& e);

    /**
     * @brief An override of assignment operator.
     * @param p the object in terms of EvolutionCoursI.
     * @return  a copied object in terms of EvolutionCoursI.
     */
    EvolutionCoursI& operator=(const EvolutionCoursI& p);

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
    ~EvolutionCoursI();

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
    Iterator getIterator() {
        return Iterator (this);
    }

    /**
     * @brief Get the iterator of table for courses.
     * @return the corresponding iterator.
     */
    const ConstIterator getIterator() const {
        return ConstIterator(this);
    }

    friend std::ostream &operator<<(std::ostream &os, EvolutionCoursI &i);

    friend std::ostream &operator<<(std::ostream &os, const EvolutionCoursI &i);



};



#endif //TD4_EVOLUTIONCOURS_H
