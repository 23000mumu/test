#include "adddaily.h"
#include "widget.h"

AddDaily::AddDaily(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    lineEdit = new QLineEdit(this);
    mainLayout->addWidget(lineEdit);
    myddl = new myDDL(this);
    mainLayout->addWidget(myddl);
    textEdit = new QTextEdit(this);
    mainLayout->addWidget(textEdit);
    QHBoxLayout* pHlay = new QHBoxLayout();
    okBtn = new QPushButton("ok", this);
    cancelBtn = new QPushButton("cancel", this);
    pHlay->addWidget(okBtn);
    pHlay->addWidget(cancelBtn);
    mainLayout->addLayout(pHlay);
    setLayout(mainLayout);
    connect(okBtn, &QPushButton::clicked, this, &AddDaily::on_ok_clicked);
}

void AddDaily::on_ok_clicked()
{
    QString name = lineEdit->text();
    emit newBtn(name);
}
