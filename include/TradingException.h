//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_TRADINGEXCEPTION_H
#define TD4_TRADINGEXCEPTION_H

#include <iostream>
/**
 * @brief the class of my exception for trading simulator.
 */
class TradingException {
    /**
     * @brief the message for an exception.
     */
    std::string info;
public:
    /**
     * @brief Constructor with parameters.
     * @param info the message of an exception.
     * attention, when only one parameter, it is better to add a prefix "explicit" to avoid the implicit conversion.
     */
    explicit TradingException(const std::string &info);

    /**
     * @brief Getter for attribute of info.
     * @return the corresponding value of message of the exception.
     */
    const std::string &getInfo() const;
};


#endif //TD4_TRADINGEXCEPTION_H
