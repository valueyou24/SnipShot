#ifndef SNIPASTEAPP_H
#define SNIPASTEAPP_H

#include<QMenu>
#include <QObject>
#include<QSystemTrayIcon>
#include "mywidget.h"

class SnipasteApp : public QObject
{
    Q_OBJECT
public:
    explicit SnipasteApp(QObject *parent = nullptr);

signals:
    void shotFinished(QPixmap pix);

public slots:
    void grapScreen();

private:
    void initSystemMenu();

private:
    QSystemTrayIcon* sysMenu;
    MyWidget* view;
};

#endif // SNIPASTEAPP_H
