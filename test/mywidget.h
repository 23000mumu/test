#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QCheckBox>
#include "miniwidget.h"
#include<QPushButton>
#include<QGridLayout>
#include "miniwidget1.h"
#include "miniwidget2.h"
#include "miniwidget3.h"


class myWidget : public QWidget
{
    Q_OBJECT
public:
    explicit myWidget(QWidget *parent = nullptr);

signals:

private:
    miniWidget* mini;
    miniWidget1* mini1;
    miniWidget2* mini2;
    miniWidget3* mini3;
    QPushButton* show;
    QPushButton* paint;
};

#endif // MYWIDGET_H
