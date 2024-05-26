#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QDesktopServices>
#include <QDir>
#include <QUrl>
#include<QPixmap>
#include "adddaily.h"
#include "myddl.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_userName_clicked();
    void buttonClicked();
    void openAddDaily();
    void AddItems(const QString &newText);
    void on_changePhoto_clicked();

private:
    void initWindow();
    QLabel *userPhoto;
    QStackedWidget *stackWidget;
    QButtonGroup *btnGroup;
    QWidget *dailyList;
    AddDaily *addDaily;
};

#endif // WIDGET_H
