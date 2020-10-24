#include "Headers/start.h"

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QtDebug>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Muestra la splash screen
    QPixmap splashimg(":/Assets/Assets/SplashScreen.png");
    QSplashScreen splash(splashimg, Qt::WindowStaysOnTopHint);
    splash.show();
    splash.showMessage("Cargando Sistema");
    app.processEvents();
    //Entra al inicio de sesion
    Start start;
    start.show();
    splash.finish(&start);
    return app.exec();
}
