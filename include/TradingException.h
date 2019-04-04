//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_TRADINGEXCEPTION_H
#define TD4_TRADINGEXCEPTION_H

#include <iostream>
class TradingException {
private:
    std::string info;
public:
    explicit TradingException(const std::string &info);

    const std::string &getInfo() const;

};


#endif //TD4_TRADINGEXCEPTION_H
