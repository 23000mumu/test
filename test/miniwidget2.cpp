#include "miniwidget2.h"

miniWidget2::miniWidget2(QWidget *parent)
    : QWidget{parent}
{
    this->setMinimumSize(150,150);
    QVBoxLayout* pVLay = new QVBoxLayout(this);
    QHBoxLayout* pHLay = new QHBoxLayout(this);
    QLabel* title = new QLabel("重要但不紧急",this);
    pVLay->addWidget(title);
    contextList = new QWidget(this);
    contextList->setMinimumSize(200,120);
    contextList->setStyleSheet("background-color: white;");
    pVLay->addWidget(contextList);
    QPushButton* Add = new QPushButton("添加",this);
    QPushButton* Del = new QPushButton("删除",this);
    Add->setFixedSize(50,50);
    Del->setFixedSize(50,50);
    pHLay->addWidget(Add);
    pHLay->setSpacing(10);
    pHLay->addWidget(Del);
    pVLay->addLayout(pHLay);
    setLayout(pVLay);
}
