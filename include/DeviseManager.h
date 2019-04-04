//
// Created by chenghaowang on 29/03/19.
//

#ifndef TD4_DEVISEMANAGER_H
#define TD4_DEVISEMANAGER_H


#include "Devise.h"
#include "PaireDevises.h"

class DevisesManager {
private:
    DevisesManager(const DevisesManager&) = delete;
    DevisesManager& operator=(const DevisesManager&) = delete;
    DevisesManager() = default;
    ~DevisesManager();
    static DevisesManager* instance = nullptr;
    static void libererManager();
public:
    static DevisesManager& getManager();

};


#endif //TD4_DEVISEMANAGER_H
