#include <iostream>
#include "../include/Devise.h"
#include "../include/PaireDevises.h"
#include "../include/DeviseManager.h"

int main() {
    Devise USD("USD", "Dollar Américain");
    Devise BTC("BTC", "BitCoin");
    Devise EUR("EUR", "Euro");
    Devise RUB("RUB", "Rouble Russe");
    PaireDevises BTC_USD(BTC, USD);
    PaireDevises EUR_RUB(EUR, RUB, "Betty");
    PaireDevises USD_RUB(USD, RUB, "Barney");
    DeviseManager deviseManager = DeviseManager::getDeviseManager();
    return 0;

}