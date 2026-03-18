#include "mywidget.h"
#include<QPainter>
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{

}

MyWidget::~MyWidget() {}

void MyWidget::showPix(QPixmap pix)
{
    this->windPix = pix;
    this->show();
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(! this->windPix.isNull())
    {
        painter.drawPixmap(this->rect(),this->windPix);
    }
}
