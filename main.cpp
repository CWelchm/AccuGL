//#include "accuweather.h"
#include "oglwidget.h"
#include <QApplication>
#include <QtGui/QGuiApplication>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QSurface>
#include <QtGui/QMatrix4x4>
#include <QtGui/QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setDepthBufferSize(24);
    QSurfaceFormat::setDefaultFormat(format);

    //AccuWeather w;
    OGLWidget widget;
    widget.show();

    return a.exec();
}
