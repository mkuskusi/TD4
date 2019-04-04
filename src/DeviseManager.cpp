//
// Created by chenghaowang on 29/03/19.
//

#include "../include/DeviseManager.h"

DevisesManager& DevisesManager::getManager() {
    if (!instance) instance = new DevisesManager;
    return *instance;
}


void DevisesManager::libererManager() {
    delete instance;
    instance = nullptr;
}

DevisesManager::~DevisesManager() {
    libererManager();
}
