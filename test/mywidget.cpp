#include "mywidget.h"

myWidget::myWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* pVLay = new QVBoxLayout(this);
    show = new QPushButton("显示未完成",this);
    show->setMinimumSize(50,20);
    paint = new QPushButton("查看",this);
    paint->setMinimumSize(50,20);
    QHBoxLayout* tmpLay = new QHBoxLayout(this);
    tmpLay->addWidget(show);
    tmpLay->addWidget(paint);
    pVLay->addLayout(tmpLay);
    QGridLayout* gridLay = new QGridLayout(this);
    mini = new miniWidget(this);
    mini1 = new miniWidget1(this);
    mini2 = new miniWidget2(this);
    mini3 = new miniWidget3(this);
    mini->setStyleSheet("border: 2px solid black;");
    mini1->setStyleSheet("border: 2px solid black;");
    mini2->setStyleSheet("border: 2px solid black;");
    mini3->setStyleSheet("border: 2px solid black;");
    gridLay->addWidget(mini,0,0);
    gridLay->addWidget(mini1,0,1);
    gridLay->addWidget(mini2,1,0);
    gridLay->addWidget(mini3,1,1);
    pVLay->addLayout(gridLay);
    setLayout(pVLay);
}
