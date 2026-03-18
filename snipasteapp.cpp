#include "snipasteapp.h"
#include<QDebug>
#include<QApplication>
#include<QScreen>
#include<QCursor>


SnipasteApp::SnipasteApp(QObject *parent)
    : QObject{parent},
    sysMenu(new QSystemTrayIcon(this)),
    view(new MyWidget)
{

    this->sysMenu->setIcon(QIcon(":/icon/logo.png"));

    initSystemMenu();

    this->sysMenu->show();

    connect(this,&SnipasteApp::shotFinished,this->view,&MyWidget::showPix);

}

void SnipasteApp::grapScreen()
{
    QList<QScreen*> screens = qApp->screens();
    if(screens.isEmpty())
    {
        qWarning() << "没有找到显示器";
        return;
    }

    auto cursorPos = QCursor::pos();
    QPixmap pix;
    for(auto screen:screens)
    {
        QRect rect = screen->geometry();
        if(rect.contains(cursorPos))
        {//包含鼠标
           pix = screen->grabWindow();
           break;
        }
    }

    if(pix.isNull())
    {
        qWarning() << "截图像素为空";
        return;
    }

    emit shotFinished(pix);
}

void SnipasteApp::initSystemMenu()
{
    QMenu* menu = new QMenu;
    menu->addAction("截图",this,SLOT(grapScreen()));
    menu->addAction("退出",qApp,SLOT(quit()));

    /*信号和槽
     *
     *信号的发出者 信号的类型 信号接收者  处理函数（槽函数）
     */

    this->sysMenu->setContextMenu(menu);
}
