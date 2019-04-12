//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_EVOLUTIONCOURSII_H
#define TD4_EVOLUTIONCOURSII_H


#include "PaireDevises.h"
#include "CoursOHLC.h"
#include "TradingException.h"

/**
 * @brief The class of evolution of courses for a share.
 */
class EvolutionCoursII {
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
    class IteratorII{
        /**
         * @brief a pre-declaration of friend class of EvolutionCoursI such that the class EvolutionCoursI can visit the private members of class Iterator.
         * to make the class Iterator as a dedicate nested class for EvolutionCoursI.
         */
        friend class EvolutionCoursII;

        /**
         * @brief the instance of super carrier associated with the nested class.
         */
        EvolutionCoursII *evolutionCours = nullptr;
        /**
         * @brief the index of current element.
         */
        int index=0;


        /**
         * @brief Constructor with parameters.
         * @param evolutionCours see class evolutionCoursI
         * @param j index of course.
         */
        explicit IteratorII(EvolutionCoursII *evolutionCours,  int j=0):evolutionCours(evolutionCours),index(j){
        }
        bool isDone() const{
            return evolutionCours == nullptr || index == evolutionCours->getNbCours();
        }

    public:
        IteratorII()= default;
        void operator++(){
            if(isDone()){
                throw TradingException("out of array");
            }
            index++;
        }
        CoursOHLC& operator*() const {
            if (isDone())
                throw TradingException("error, indirection on an iterator which is done");
            return evolutionCours->getCoursAt(index);
        }

        bool operator==(const IteratorII &rhs) const;

        bool operator!=(const IteratorII &rhs) const;
    };

    /**
     * @brief a nested class to support a design pattern in terms of iterator.
     */
    class ConstIteratorII{
        /**
         * @brief a pre-declaration of friend class of EvolutionCoursI such that the class EvolutionCoursI can visit the private members of class Iterator.
         * to make the class Iterator as a dedicate nested class for EvolutionCoursII.
         */
        friend class EvolutionCoursII;

        /**
         * @brief the instance of super carrier associated with the nested class.
         */
        const EvolutionCoursII *evolutionCours = nullptr;
        /**
         * @brief the index of current element.
         */
        int index=0;


        /**
         * @brief Constructor with parameters.
         * @param evolutionCours see class evolutionCoursI
         * @param j index of course.
         */
        explicit ConstIteratorII(const EvolutionCoursII *evolutionCours,  int j=0): evolutionCours(evolutionCours),index(j){}
        bool isDone() const{
            return evolutionCours == nullptr || index == evolutionCours->getNbCours();
        }

    public:
        ConstIteratorII()= default;
        void operator++(){
            if(isDone()){
                throw TradingException("out of array");
            }
            index++;
        }
        const CoursOHLC& operator*() const {
            if (isDone())
                throw TradingException("error, indirection on an iterator which is done");
            return evolutionCours->getCoursAt(index);
        }

        bool operator==(const ConstIteratorII &rhs) const;

        bool operator!=(const ConstIteratorII &rhs) const;
    };
public:
    /**
     * @brief Constructor with parameters.
     * @param paireDevises see class PaireDevises.
     */
    explicit EvolutionCoursII(const PaireDevises &paireDevises);

    /**
     * @brief Constructor of recopy.
     * @param e the object in terms of EvolutionCoursII.
     */
    EvolutionCoursII(const EvolutionCoursII& e);

    /**
     * @brief An override of assignment operator.
     * @param p the object in terms of EvolutionCoursII.
     * @return  a copied object in terms of EvolutionCoursII.
     */
    EvolutionCoursII& operator=(const EvolutionCoursII& p);

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
    ~EvolutionCoursII();

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

    IteratorII begin() { return IteratorII(this); }
    IteratorII end() { return IteratorII(this, nbCours); }

    ConstIteratorII begin() const { return ConstIteratorII(this); }
    ConstIteratorII end() const{ return ConstIteratorII(this, nbCours); }

    friend std::ostream &operator<<(std::ostream &os, EvolutionCoursII &i);

    friend std::ostream &operator<<(std::ostream &os, const EvolutionCoursII &i);

};



#endif //TD4_EVOLUTIONCOURS_H
