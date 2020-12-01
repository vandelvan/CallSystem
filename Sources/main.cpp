#include "Headers/callSystemMenu.h"

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Muestra la splash screen
    QPixmap splashimg(":/Assets/Assets/SplashScreen.png");
    QSplashScreen splash(splashimg, Qt::WindowStaysOnTopHint);
    splash.show();
    //Entra al menu/control de agentes
    CallSystemMenu callSystemMeu;
    splash.finish(&callSystemMeu);
    callSystemMeu.show();
    return app.exec();
}
