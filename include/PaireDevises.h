//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_PAIREDEVISES_H
#define TD4_PAIREDEVISES_H

#include <cstring>
#include <iostream>
#include "Devise.h"

/**
 * @brief the class of pair for currencies. Which is composed of a currency of base, and another of counterpart, then a nickname.
 */
class PaireDevises {
    /**
     * @brief the currency of base.
     */
    Devise base;
    /**
     * @brief the currency of counterpart.
     */
     Devise contrepartie;
    /**
     * @brief the nickname of the pair.
     */
    std::string surnom;

public:
    PaireDevises()= default;

    /**
     * @brief Constructor with parameters.
     * @param base the currency of base.
     * @param contrepartie the currency of counterpart.
     * @param surnom the nick name of pair of currencies.
     */
    PaireDevises(const Devise &base, const Devise &contrepartie, const std::string &surnom="");

    /**
     * @brief Getter for attribute of base.
     * @return the corresponding value for attribute of base.
     */
    const Devise &getBase() const;

    /**
     * @brief Getter for attribute of contrepartie.
     * @return the corresponding value for attribute of contrepartie.
     */
    const Devise &getContrepartie() const;

    /**
     * @brief Getter for attribute of surnom.
     * @return the corresponding value for attribute of surnom.
     */
    const std::string &getSurnom() const;

    /**
     * @brief An override of output stream operator.
     * @param os the standard output stream.
     * @param devises an object in terms of currencies.
     * @return the redirected output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const PaireDevises &devises);

    bool operator==(const PaireDevises &rhs) const;

    bool operator!=(const PaireDevises &rhs) const;
};

#endif //TD4_PAIREDEVISES_H
