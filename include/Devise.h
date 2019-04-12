//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_DEVISE_H
#define TD4_DEVISE_H

#include <iostream>
#include <cstring>
/**
 * @brief the class of currency used in a trading simulator. Which is composed of a code in three character, the name, and the zone.
 */
class Devise {
    /**
     * @brief the code of a currency.
     */
    char code[4];
    /**
     * @brief the name of a currency.
     */
    std::string monnaie;
    /**
     * @brief the one of a currency.
     */
    std::string zone;

public:

    Devise() = default;

    /**
     * @brief Constructor with parameters.
     * @param code the code of a currency.
     * @param monnaie the name of a currency.
     * @param zone the zone of a currency.
     */
    explicit Devise(char *code, const std::string &monnaie="", const std::string &zone="");

    /**
     * @brief Getter for attribute of code.
     * @return the corresponding value for attribute of code.
     */
    const char *getCode() const;

    /**
     * @brief Getter for attribute of monnaie.
     * @return the corresponding value for attribute of moonaie.
     */
    const std::string &getMonnaie() const;

    /**
     * @brief Getter for attribute of zone.
     * @return the corresponding value for attribute of zone.
     */
    const std::string &getZone() const;

    /**
     * @brief An override of output stream operator.
     * @param os the standard output stream.
     * @param devise an object in terms of currency.
     * @return the redirected output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const Devise &devise);



    bool operator==(const Devise &rhs) const;

    bool operator!=(const Devise &rhs) const;


};


#endif //TD4_DEVISE_H
