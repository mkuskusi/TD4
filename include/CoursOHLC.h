//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_COURSOHLC_H
#define TD4_COURSOHLC_H

#include <iostream>
class CoursOHLC {
private:
    double openPrice = 0.0;
    double highPrice = 0.0;
    double lowPrice = 0.0;
    double closePrice= 0.0;
public:

    CoursOHLC();

    CoursOHLC(double openPrice, double highPrice, double lowPrice, double closePrice);

    double getOpenPrice() const;

    double getHighPrice() const;

    double getLowPrice() const;

    double getClosePrice() const;

    friend std::ostream &operator<<(std::ostream &os, const CoursOHLC &ohlc);

};


#endif //TD4_COURSOHLC_H
