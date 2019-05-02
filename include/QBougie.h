//
// Created by chenghaowang on 02/05/19.
//

#ifndef TD4_QBOUGIE_H
#define TD4_QBOUGIE_H


#include <QtCore/QArgument>
#include "CoursOHLC.h"
#include <QtCharts/QtCharts>

class QBougie : public QCandlestickSet {
Q_OBJECT
    CoursOHLC* cours = nullptr;
public:
    QBougie(CoursOHLC *c, qreal open, qreal high, qreal low, qreal close, qreal timestamp = 0.0,
            QObject *parent = nullptr): QCandlestickSet(open, high, low, close, timestamp, parent), cours(c){
        connect(this, SIGNAL(clicked()), this, SLOT( viewCoursOHLC()));
    }

    CoursOHLC& getCours() { return *cours; }
    const CoursOHLC& getCours() const { return *cours; }
    signals:
    void clickBougie(QBougie* c);
private slots:
    void viewCoursOHLC(){ emit clickBougie(this); }
};

#endif //TD4_QBOUGIE_H
