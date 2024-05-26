#include "widget.h"
#include "adddaily.h"
#include "mywidget.h"
#include <QInputDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDate>
#include <QPixmap>
#include <QDebug>
#include<QFileDialog>

void Widget::initWindow() {
    for (int i = 0; i < 7; ++i) {
        stackWidget->addWidget(new myWidget());
    }
}

void Widget::AddItems(const QString &newText)
{
    QPushButton *btn = new QPushButton(newText, dailyList);
    btn->show(); // Ensure the button is shown
}

void Widget::on_changePhoto_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "请选择图片", "E:\\FourPlans\\photos", "(*jpg *png);;");
    if(fileName.isEmpty()){
        return;
    }

    userPhoto->setPixmap(fileName);
}


Widget::Widget(QWidget *parent)
    : QWidget(parent), stackWidget(new QStackedWidget(this)), btnGroup(new QButtonGroup(this)), addDaily(nullptr)
{

    this->setStyleSheet("background-color:rgb(230,230,230)");
    this->setMinimumSize(800, 600);
    qDebug() << this->width() << this->height();

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(5, 5, 5, 5);
    mainLayout->setSpacing(5);

    QHBoxLayout *userInfoLayout = new QHBoxLayout();
    userInfoLayout->setContentsMargins(5, 5, 5, 5);

    userPhoto = new QLabel(this);
    userPhoto->setMouseTracking(true);
    userPhoto->setOpenExternalLinks(true);

    userPhoto->setFixedSize(60, 60);
    QPixmap pixmap("E://FourPlans//photos//photo1");
    userPhoto->setText("<a href=\"E://FourPlans//photos//photo1\">User Photo</a>");

    userPhoto->setPixmap(pixmap);
    userPhoto->setScaledContents(true);
    userInfoLayout->addWidget(userPhoto);

    QPushButton *userName = new QPushButton(this);
    userName->setMinimumSize(60, 40);
    userName->setText("新用户");
    connect(userName, &QPushButton::clicked, this, &Widget::on_userName_clicked);
    userInfoLayout->addWidget(userName);

    QPushButton *changePhoto = new QPushButton(this);
    changePhoto->setText("换头像");
    userInfoLayout->addWidget(changePhoto);

    userInfoLayout->addStretch();

    QLabel *todayDate = new QLabel(this);
    todayDate->setMinimumSize(100, 40);
    QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("yyyy-MM-dd");
    todayDate->setText(dateString);
    userInfoLayout->addWidget(todayDate);

    mainLayout->addLayout(userInfoLayout);

    QWidget *weekWidget = new QWidget(this);
    weekWidget->setContentsMargins(0, 0, 0, 0);
    weekWidget->setMinimumSize(800, 30);
    QHBoxLayout *weekLayout = new QHBoxLayout(weekWidget);
    weekLayout->setContentsMargins(0, 0, 0, 0);
    weekLayout->setSpacing(5);

    QStringList names;
    names << "Monday" << "Tuesday" << "Wednesday" << "Thursday" << "Friday" << "Saturday" << "Sunday";
    for (int i = 0; i < names.count(); ++i) {
        QPushButton *btn = new QPushButton();
        btn->setStyleSheet("font:18px");
        btn->setFixedSize(90, 25);
        btn->setText(names.at(i));
        btn->setCheckable(true);
        connect(btn, &QPushButton::clicked, this, &Widget::buttonClicked);
        btnGroup->addButton(btn, i);
        weekLayout->addWidget(btn);
    }
    btnGroup->button(0)->click();
    mainLayout->addWidget(weekWidget);

    QHBoxLayout *todoPlanLayout = new QHBoxLayout();
    todoPlanLayout->setSpacing(5);

    QVBoxLayout *dailyLay = new QVBoxLayout();
    QLabel *title = new QLabel("每日打卡", this);
    title->setFixedSize(150, 30);
    dailyList = new QWidget(this);
    dailyList->setStyleSheet("background-color: white;");
    dailyList->setMinimumSize(150, 300);

    QHBoxLayout *BtnLay = new QHBoxLayout();
    BtnLay->setSpacing(5);
    QPushButton *Add = new QPushButton("添加", this);
    QPushButton *Del = new QPushButton("删除", this);
    Add->setFixedSize(50, 50);
    Del->setFixedSize(50, 50);

    BtnLay->addWidget(Add);
    BtnLay->addWidget(Del);

    dailyLay->addWidget(title);
    dailyLay->addWidget(dailyList);
    dailyLay->addLayout(BtnLay);

    todoPlanLayout->addLayout(dailyLay);

    QWidget *mainWidget = new QWidget(this);
    mainWidget->setMinimumWidth(400);
    QVBoxLayout *rightLay = new QVBoxLayout(mainWidget);
    rightLay->setSpacing(0);
    rightLay->setContentsMargins(0, 0, 0, 0);

    rightLay->addWidget(stackWidget);

    todoPlanLayout->addWidget(mainWidget);
    mainLayout->addLayout(todoPlanLayout);

    initWindow();

    connect(Add, &QPushButton::clicked, this, &Widget::openAddDaily);

    connect(changePhoto, &QPushButton::clicked, this, &Widget::on_changePhoto_clicked);

}

Widget::~Widget() {
    delete addDaily;
}

void Widget::on_userName_clicked() {
    bool ok;
    QString strName = QInputDialog::getText(this, tr("输入窗口"), tr("请输入用户名:"), QLineEdit::Normal, tr(""), &ok);
    if (ok && !strName.isEmpty()) {
        QPushButton *userName = qobject_cast<QPushButton *>(sender());
        if (userName) {
            userName->setText(strName);
        }
    }
}

void Widget::buttonClicked() {
    int id = btnGroup->checkedId();
    stackWidget->setCurrentIndex(id);
    qDebug() << "Button clicked, ID:" << id;
}

void Widget::openAddDaily()
{
    if (!addDaily) {
        addDaily = new AddDaily(this);
        connect(addDaily, &AddDaily::newBtn, this, &Widget::AddItems);
        connect(addDaily, &AddDaily::destroyed, [this]() {
            addDaily = nullptr;
        });
    }
    qDebug() << "Showing AddDaily window";
    addDaily->show();
    qDebug() << "AddDaily window shown";
}
