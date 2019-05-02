//
// Created by chenghaowang on 29/03/19.
//

#include <utility>

#include "../include/CoursOHLC.h"
#include "../include/TradingException.h"

CoursOHLC::CoursOHLC(double openPrice, double highPrice, double lowPrice, double closePrice, const QDateTime &dateTime) : openPrice(openPrice),
                                                                                                highPrice(highPrice),
                                                                                                lowPrice(lowPrice),
                                                                                                closePrice( closePrice), dataCreated(dateTime) {}

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
       << " closePrice: " << ohlc.closePrice << " created time: " << ohlc.dataCreated.toString("hh:mm").toStdString();
    return os;
}

void CoursOHLC::setCours(double openPrice, double highPrice, double lowPrice, double closePrice, const QDateTime &dateTime){
    CoursOHLC::openPrice = openPrice;
    CoursOHLC::highPrice = highPrice;
    CoursOHLC::lowPrice = lowPrice;
    CoursOHLC::closePrice = closePrice;
    CoursOHLC::dataCreated = dateTime;
}

void CoursOHLC::setCours(double openPrice, double highPrice, double lowPrice, double closePrice) {
    CoursOHLC::openPrice = openPrice;
    CoursOHLC::highPrice = highPrice;
    CoursOHLC::lowPrice = lowPrice;
    CoursOHLC::closePrice = closePrice;
}

const QDateTime &CoursOHLC::getDataCreated() const {
    return dataCreated;
}

void CoursOHLC::setDataCreated(const QDateTime &dataCreated) {
    CoursOHLC::dataCreated = dataCreated;
}


CoursOHLC::CoursOHLC() = default;

