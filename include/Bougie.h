//
// Created by chenghaowang on 05/04/19.
//

#ifndef TD4_BOUGIE_H
#define TD4_BOUGIE_H


#include <ostream>
#include "CoursOHLC.h"
#include "Couleur.h"

/**
 * @brief The class of candle in a trading simulator, where a candle is composed of an object in terms of course, its color and a threshold of difference between open price and close price.
 */
class Bougie {
    /**
     * @brief An object in terms of CoursOHLC.
     */
    const CoursOHLC& cours;
    /**
     * @brief The color of a candle.
     */
    Couleur couleur;

    /**
     * @brief The threshold of difference between the open price and close price.
     */
    static double seuilToupie;

public:
    /**
     * @brief Constructor with parameters.
     * @param cours see CoursOHLC
     * attention, when there only one parameter, it is better to add explicit prefix to avoid implicit conversion.
     */
    explicit Bougie(const CoursOHLC &cours);

    /**
     * @brief Getter for cours attribute.
     * @return the corresponding value of attribute cours.
     */
    const CoursOHLC &getCours() const;

    /**
     * @brief Getter for color of candle.
     * @return the corresponding value of candle's color.
     */
    Couleur getCouleur() const;

    /**
     * @brief Get the form of candle, when the difference between open price and close price exceeds the threshold, then the form will be a horizontal line either at top or at bottom .
     * @return the corresponding value of candle's form.
     */
    std::string getForme() const;

    /**
     * @brief Setter for the threshold of difference between open price and close price.
     * @param seuilToupie
     */
    static void setSeuilToupie(double seuilToupie);

    /**
     * @brief An override of output stream operator to print the Candle object.
     * @param os the standard output stream.
     * @param bougie an object in terms of candle.
     * @return the redirected output stream.
     * the "friend" prefix make the standard output stream can accede the private member of class candle.
     */
    friend std::ostream &operator<<(std::ostream &os, const Bougie &bougie);
};

// either we can move the override operator "<<" out of class as a global method.
//std::ostream &operator<<(std::ostream &os, const Bougie &bougie);


#endif //TD4_BOUGIE_H
