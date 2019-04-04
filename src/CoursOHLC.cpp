//
// Created by chenghaowang on 29/03/19.
//

#include "../include/CoursOHLC.h"
#include "../include/TradingException.h"

CoursOHLC::CoursOHLC(double openPrice, double highPrice, double lowPrice, double closePrice) : openPrice(openPrice),
                                                                                                highPrice(highPrice),
                                                                                                lowPrice(lowPrice),
                                                                                                closePrice(
                                                                                                        closePrice) {}

double CoursOHLC::getOpenPrice() const {
    return openPrice;
}

double CoursOHLC::getHighPrice() const {
    return highPrice;
}

double CoursOHLC::getLowPrice() const {
    return lowPrice;
}

double CoursOHLC::getClosePrice() const {
    return closePrice;
}

std::ostream &operator<<(std::ostream &os, const CoursOHLC &ohlc) {
    os << "openPrice: " << ohlc.openPrice << " highPrice: " << ohlc.highPrice << " lowPrice: " << ohlc.lowPrice
       << " closePrice: " << ohlc.closePrice;
    return os;
}

CoursOHLC::CoursOHLC() = default;

