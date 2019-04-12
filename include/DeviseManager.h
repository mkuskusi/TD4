//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_DEVISEMANAGER_H
#define TD4_DEVISEMANAGER_H


#include <ostream>
#include "Devise.h"
#include "PaireDevises.h"

/**
 * @brief The class of manager of currencies. Which is implemented as a singleton class.
 */
class DevisesManager {
private:

    /**
     * @brief Default constructor.  a "default" postfix to simplify the implementation.
     */
    DevisesManager() = default;
    /**
     * @brief Destructor.
     */
    ~DevisesManager();
    /**
     * @brief A static instance of DeviseManager.
     */
    static DevisesManager* instance;

    /**
     * @brief the table of currencies.
     */
    Devise* devises=nullptr;
    /**
     * @brief max number of currencies.
     */
    unsigned int nbMaxDevises = 0;
    /**
     * @brief the number of currencies in table.
     */
    unsigned int nbDevises = 0;
    /**
     * @brief the table of currency pair.
     */
    mutable PaireDevises* paires = nullptr;
    /**
     * @brief the max number of pairs.
     */
    mutable unsigned int nbMaxPairesDevises = 0;
    /**
     * @brief the number of pairs in table.
     */
    mutable unsigned int nbPairesDevises = 0;

public:
    /**
     * @brief Get the manager instance. if empty then return a new object, otherwise return the existed object.
     * @return
     */
    static DevisesManager& getManager();
    /**
    * @brief Constructor of recopy, a "delete" postfix here to forbid the duplication from recopy constructor.
    */
    DevisesManager(const DevisesManager&) = delete;
    /**
     * @brief An override of operator assignment. a "delete" postfix here to forbid the duplication from assignment operator.
     * @return a copied object in terms of DeviseManager.
     */
    DevisesManager& operator=(const DevisesManager&) = delete;

    /**
     * @brief create a currency.
     * @param c the code of a new currency.
     * @param m the monnaie of a new currency.
     * @param z the zone of a new currency.
     * @return the created object in terms of Devise.
     */
    const Devise& creationDevise(char *c, const std::string& m, const std::string& z);

    /**
     * @brief Get the currency by its code.
     * @param c the code to search.
     * @return the corresponding object of currency.
     */
    const Devise& getDevise(char *c) const;

    /**
     * @brief Get the pair of currencies by the two codes and its nickname.
     * @param c1 the code of currency in base.
     * @param c2 the code of currency in counterpart.
     * @param s the nickname of pair of currencies.
     * @return the corresponding object of pair of currencies.
     */
    const PaireDevises& getPaireDevises(char * c1, char * c2, const
    std::string& s="") const;


    friend std::ostream &operator<<(std::ostream &os, const DevisesManager &manager);
};


#endif //TD4_DEVISEMANAGER_H
