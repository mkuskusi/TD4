//
// Created by chenghaowang on 29/03/19.
//

#include "../include/DeviseManager.h"
#include "../include/TradingException.h"

DevisesManager *DevisesManager::instance = nullptr;

DevisesManager& DevisesManager::getManager() {
    if (!instance) instance = new DevisesManager;
    return *instance;
}


DevisesManager::~DevisesManager() {
    delete[] devises;
    delete[] paires;
    delete instance;
    instance = nullptr;
}

const Devise &DevisesManager::creationDevise(char *c, const std::string &m, const std::string &z) {
    Devise devise(c, m, z);
    for (unsigned int i = 0; i < nbDevises; i++) {
        if (devises[i] == devise)
            throw TradingException("error this currency has been existed!");
    }
    if (nbDevises == nbMaxDevises) {
        auto *newtab = new Devise[nbDevises + 10];
        for (unsigned int i = 0; i < nbDevises; i++)
            newtab[i] = devises[i];
        Devise* old = devises;
        nbMaxDevises += 10;
        devises = newtab;
        delete[] old;
    }
    devises[nbDevises] = devise;
    return devises[nbDevises++];

}

const Devise &DevisesManager::getDevise(char * c) const {
    Devise devise(c);
    for (unsigned int i = 0; i < nbDevises; i++) {
        if (devises[i] == devise) return devises[i];
    }
    throw TradingException("can't find a currency!");

}

const PaireDevises &
DevisesManager::getPaireDevises(char *c1,  char * c2, const std::string &s) const {
    const Devise& d1=getDevise(c1);
    const Devise& d2 = getDevise(c2);
    PaireDevises paireDevises(d1, d2, s);
    for (unsigned int i = 0; i < nbPairesDevises; i++) {
        if (paires[i] == paireDevises)
            return paires[i];
    }
    // if does not find, then create it.
    if (nbPairesDevises == nbMaxPairesDevises) {
        auto newtab = new PaireDevises[nbPairesDevises + 10];
        for (unsigned int i = 0; i < nbPairesDevises; i++)
            newtab[i] = paires[i];
        PaireDevises* old = paires;
        nbMaxPairesDevises += 10;
        paires = newtab;
        delete[] old;
    }
    paires[nbPairesDevises] = paireDevises;
    return paires[nbPairesDevises++];

}

std::ostream &operator<<(std::ostream &os, const DevisesManager &manager) {
    for (int i = 0; i < manager.nbDevises; ++i) {
        os << "devises: " << manager.devises[i] << std::endl;
    }
    for (int j = 0; j < manager.nbPairesDevises ; ++j) {
        os <<  "paires: " << manager.paires[j] << std::endl;
    }
    return os;
}
