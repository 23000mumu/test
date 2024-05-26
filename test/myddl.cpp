#include "myddl.h"

myDDL::myDDL(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    QLabel *label = new QLabel("Deadline:", this);
    dateTimeEdit = new QDateTimeEdit(this);
    dateTimeEdit->setCalendarPopup(true); // 让日期选择框可弹出日历
    dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss"); // 设置日期时间格式
    layout->addWidget(label);
    layout->addWidget(dateTimeEdit);
    setLayout(layout);

    //qDebug() << "myDDL created";
}

QString myDDL::deadline() const
{
    return dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
}
