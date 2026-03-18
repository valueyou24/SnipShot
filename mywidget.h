#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include<QPixmap>


class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

public slots:
    void showPix(QPixmap pix);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPixmap windPix;
};
#endif // MYWIDGET_H
