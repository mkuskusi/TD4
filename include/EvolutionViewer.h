//
// Created by chenghaowang on 12/04/19.
//

#ifndef TD4_EVOLUTIONVIEWER_H
#define TD4_EVOLUTIONVIEWER_H
#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QHBoxLayout>
#include <QtCharts/QtCharts>
#include "EvolutionCoursI.h"
#include "EvolutionCoursII.h"
#include "Bougie.h"
#include "QBougie.h"

class EvolutionViewer : public QWidget{
    Q_OBJECT EvolutionCoursII &evolution;
    QtCharts::QCandlestickSeries* series;
    QtCharts::QChart *chart;
    QtCharts::QChartView *chartView;
    QLineEdit* open;
    QLineEdit* high;
    QLineEdit* low;
    QLineEdit* close;
    QLabel* openl;
    QLabel* highl;
    QLabel* lowl;
    QLabel* closel;
    QPushButton* save;
    QHBoxLayout* copen;
    QHBoxLayout* chigh;
    QHBoxLayout* clow;
    QHBoxLayout* cclose;
    QVBoxLayout* coucheCours;
    QHBoxLayout* fenetre;
    QBougie* lastBougieClicked=nullptr;
public:
    explicit EvolutionViewer(EvolutionCoursII& e, QWidget *parent = nullptr);
signals:
    void clickBougie(QBougie* c);

private slots:
    void viewCoursOHLC(QBougie* c);
    void saveCoursOHLC();
};





#endif //TD4_EVOLUTIONVIEWER_H
