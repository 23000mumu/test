#ifndef MYDDL_H
#define MYDDL_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QDateTimeEdit>

class myDDL : public QWidget
{
    Q_OBJECT

public:
    explicit myDDL(QWidget *parent = nullptr);
    QString deadline() const;

private:
    QDateTimeEdit *dateTimeEdit;
};

#endif // MYDDL_H
