#ifndef MINIWIDGET2_H
#define MINIWIDGET2_H

#include <QWidget>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<QPainter>


class miniWidget2 : public QWidget
{
    Q_OBJECT
public:
    explicit miniWidget2(QWidget *parent = nullptr);


signals:

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setPen(QPen(Qt::black, 2)); // 设置画笔颜色和宽度
        painter.drawRect(rect().adjusted(0, 0, -1, -1)); // 绘制边框
    }


private:
    QWidget* contextList;
};

#endif // MINIWIDGET2_H
