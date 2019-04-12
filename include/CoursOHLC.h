//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_COURSOHLC_H
#define TD4_COURSOHLC_H

#include <iostream>
/**
 * @brief The class of course recording information for candle in a trading simulator. which is composed of four parts: open price, close price, higher price and lower price.
 */
class CoursOHLC {
private:
    /**
     * @brief the open price, i.e. for a share.
     */
    double openPrice = 0.0;
    /**
     * @brief the highest price during a day.
     */
    double highPrice = 0.0;
    /**
     * @brief the lowest price during a day.
     */
    double lowPrice = 0.0;
    /**
     * @brief the close price, i.e. for a share.
     */
    double closePrice= 0.0;
public:

    /**
     * @brief Default Constructor.
     * attention: if need to create an array of object in term of CoursOHLC, a default constructor is then obliged.
     * if an creation for an array of pointer in terms of CoursOHLC, it is not necessary.
     */
    CoursOHLC();

    /**
     * @brief Constructor with parameters.
     * @param openPrice
     * @param highPrice
     * @param lowPrice
     * @param closePrice
     */
    CoursOHLC(double openPrice, double highPrice, double lowPrice, double closePrice);

    void setCours(double openPrice, double highPrice, double lowPrice, double closePrice);

    /**
     * @brief Getter for attribute of open price.
     * @return the corresponding value of attribute of open price.
     */
    double getOpenPrice() const;

    /**
     * @brief Getter for attribute of high price.
     * @return the corresponding value of attribute of high price.
     */
    double getHighPrice() const;

    /**
     * @brief Getter for attribute of low price.
     * @return the corresponding value of attribute of low price.
     */
    double getLowPrice() const;

    /**
     * @brief Getter for attribute of close price.
     * @return the corresponding value of attribute of close price.
     */
    double getClosePrice() const;

    /**
     * @brief An override of output stream operator.
     * @param os the standard output stream.
     * @param ohlc the object in terms of CoursOHLC.
     * @return the redirected output stream.
     */
    friend std::ostream &operator<<(std::ostream &os, const CoursOHLC &ohlc);

};


#endif //TD4_COURSOHLC_H
