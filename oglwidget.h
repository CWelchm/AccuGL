#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLVertexArrayObject>
#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLExtraFunctions>
#include <QApplication>
#include <QOpenGLTexture>
class OGLWidget: public QOpenGLWidget, protected QOpenGLExtraFunctions
{
public:
    OGLWidget(QWidget* parent = 0);
    ~OGLWidget();
    void paintGL() override;
    void initializeGL() override;
    void resizeGL(int width, int height) override;

protected:
    QOpenGLVertexArrayObject* m_vao;
    QOpenGLBuffer* m_vbo;
    QOpenGLShaderProgram* shader;
    QOpenGLTexture* texture;

    GLint m_posAttr;
    GLint m_colAttr;
    GLint m_matrixUni;
    GLuint m_texture;



};

#endif // OGLWIDGET_H
