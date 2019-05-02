#include <iostream>
#include <include/EvolutionViewer.h>
#include "../include/DeviseManager.h"
#include "../include/EvolutionCoursIII.h"


int main(int argc, char* argv[]) {
    try {
        QApplication app(argc, argv);
        QWidget window;
        DevisesManager &m = DevisesManager::getManager();
        const Devise &USD = m.creationDevise(const_cast<char *>("USD"), "Dollar Américain", "USA");
        const Devise &BTC = m.creationDevise(const_cast<char *>("BTC"), "BitCoin", "monnaie virtuelle");
        const PaireDevises &BTC_USD = m.getPaireDevises(const_cast<char *>("BTC"), const_cast<char *>("USD"));
        EvolutionCoursII e(BTC_USD);
        e.addCours(1554.530029, 1561.660034, 1525.349976, 1544.930054, QDateTime(QDate(2019, 05, 01), QTime(8, 30, 0)));

        e.addCours(1550.339966, 1587.000000, 1545.410034, 1586.510010, QDateTime(QDate(2019, 05, 01), QTime(8, 31, 0)));

        e.addCours(1586.449951, 1590.000000, 1563.170044, 1581.859985, QDateTime(QDate(2019, 05, 01), QTime(8, 32, 0)));

        e.addCours(1565.469971, 1573.849976, 1542.400024, 1544.920044, QDateTime(QDate(2019, 05, 01), QTime(8, 33, 0)));

        e.addCours(1539.010010, 1549.020020, 1495.359985, 1495.560059, QDateTime(QDate(2019, 05, 01), QTime(8, 34, 0)));

        e.addCours(1530.000000, 1556.989990, 1499.250000, 1555.859985, QDateTime(QDate(2019, 05, 01), QTime(8, 35, 0)));

        e.addCours(1572.400024, 1575.969971, 1482.319946, 1497.050049, QDateTime(QDate(2019, 05, 01), QTime(8, 36, 0)));

        e.addCours(1447.000000, 1455.900024, 1386.170044, 1431.420044, QDateTime(QDate(2019, 05, 01), QTime(8, 37, 0)));
        EvolutionViewer viewer(e, &window);
        window.show();
        return app.exec();
    }
    catch (const TradingException& e){
        std::cout << e.getInfo() << std::endl;
    }
    return 0;

}
