#ifndef ADDDAILY_H
#define ADDDAILY_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "myddl.h"

class AddDaily : public QWidget
{
    Q_OBJECT

public:
    explicit AddDaily(QWidget *parent = nullptr);

signals:
    void newBtn(const QString &name);

private slots:
    void on_ok_clicked();

private:
    QLineEdit *lineEdit;
    myDDL *myddl;
    QTextEdit *textEdit;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
};

#endif // ADDDAILY_H
