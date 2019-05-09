#ifndef ACCUWEATHER_H
#define ACCUWEATHER_H

#include <QMainWindow>
#include <QWidget>
#include <QOpenGLWidget>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLFunctions>
namespace Ui {
class AccuWeather;
}

class AccuWeather : public QMainWindow
{
    Q_OBJECT

public:
    explicit AccuWeather(QWidget *parent = 0);
    ~AccuWeather();

private:
    Ui::AccuWeather *ui;
    QOpenGLBuffer* vbo;
    QOpenGLShaderProgram* shader;
    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUni;

};

#endif // ACCUWEATHER_H
