//
// Created by chenghaowang on 29/03/19.
//

#include "../include/TradingException.h"

TradingException::TradingException(const std::string &info) : info(info) {}

const std::string &TradingException::getInfo() const {
    return info;
}
