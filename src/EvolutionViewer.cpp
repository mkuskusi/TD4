//
// Created by chenghaowang on 12/04/19.
//

#include "../include/EvolutionViewer.h"
EvolutionViewer::EvolutionViewer(EvolutionCoursII& e, QWidget *parent):QWidget(parent), evolution(e)
{
    series = new QCandlestickSeries();
    series->setName((const QString &) evolution.getPaireDevises().getSurnom());
    series->setIncreasingColor(QColor(Qt::green));
    series->setDecreasingColor(QColor(Qt::red));
    QStringList categories;
    for(EvolutionCoursII::IteratorII it = evolution.begin(); it!= evolution.end(); ++it) {
        CoursOHLC & cours = *it;
        auto * bougie = new QBougie(&cours, cours.getOpenPrice(), cours.getHighPrice(), cours.getLowPrice(), cours.getClosePrice());
        connect(bougie,SIGNAL(clickBougie(QBougie*)),this,SLOT(viewCoursOHLC(QBougie *)));
        categories << cours.getDataCreated().toString("hh.mm");
        series->append(bougie);
    }

    chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Cours OHLC");

    chart->createDefaultAxes();
    QBarCategoryAxis *axisX = (QBarCategoryAxis *) chart->axes(Qt::Horizontal).at(0);
    axisX->setCategories(categories);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chartView = new QChartView(chart,this);
    chartView->setFixedWidth(1200);
    chartView->setFixedHeight(600);
    open=new QLineEdit(this);
    high=new QLineEdit(this);
    low=new QLineEdit(this);
    close=new QLineEdit(this);
    openl=new QLabel("Open",this);
    highl=new QLabel("High",this);
    lowl=new QLabel("Low",this);
    closel=new QLabel("Close",this);
    save=new QPushButton("save", this);

    open->setFixedWidth(100);
    high->setFixedWidth(100);
    low->setFixedWidth(100);
    close->setFixedWidth(100);
    save->setFixedWidth(140);

    copen=new QHBoxLayout;
    copen->addWidget(openl);
    copen->addWidget(open);

    chigh=new QHBoxLayout;;
    chigh->addWidget(highl);
    chigh->addWidget(high);

    clow=new QHBoxLayout;;
    clow->addWidget(lowl);
    clow->addWidget(low);

    cclose=new QHBoxLayout;;
    cclose->addWidget(closel);
    cclose->addWidget(close);

    coucheCours=new QVBoxLayout ;
    coucheCours->addLayout(copen);
    coucheCours->addLayout(chigh);
    coucheCours->addLayout(clow);
    coucheCours->addLayout(cclose);
    coucheCours->addWidget(save);

    fenetre = new QHBoxLayout;
    fenetre->addWidget(chartView);
    fenetre->addLayout(coucheCours);
    connect(save,SIGNAL(clicked()),this,SLOT(saveCoursOHLC()));
    setLayout(fenetre);
}
void EvolutionViewer::viewCoursOHLC(QBougie* c) {
    QString str;
    str.setNum(c->getCours().getOpenPrice());
    open->setText(str);
    str.setNum(c->getCours().getHighPrice());
    high->setText(str);
    str.setNum(c->getCours().getLowPrice());
    low->setText(str);
    str.setNum(c->getCours().getClosePrice());
    close->setText(str);
    lastBougieClicked=c;
}

void EvolutionViewer::saveCoursOHLC(){
    double o=open->text().toDouble();
    double h=high->text().toDouble();
    double l=low->text().toDouble();
    double c=close->text().toDouble();
    lastBougieClicked->getCours().setCours(o,h,l,c);
}
