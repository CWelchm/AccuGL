#include "accuweather.h"
#include "ui_accuweather.h"
#include <QtGui/QOpenGLBuffer>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLVertexArrayObject>
#include <QtGui/QGuiApplication>


static const char* vertexSource =
        "in vec2 position;"
        "in vec3 color;"
        "out vec3 Color;"
        "void main() {\n"
        "   Color = color;"
        "   gl_Position = vec4(position, 0.0, 1.0);"
        "}\n";

static const char* fragSource =
        "in vec3 Color;"
        "out vec4 outColor;"
        "void main() {\n"
        "   outColor = vec4(1.0, 1.0, 1.0, 1.0);"
        "}\n";

AccuWeather::AccuWeather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccuWeather)
{
    ui->setupUi(this);
//    GLfloat vertices[] = {
//            0.0f, 0.707f,
//            -0.5f, -0.5f,
//            0.5f, -0.5f
//        };

//    GLfloat colors[] = {
//            1.0f, 0.0f, 0.0f,
//            0.0f, 1.0f, 0.0f,
//            0.0f, 0.0f, 1.0f
//        };

//    shader = new QOpenGLShaderProgram(this);
//    shader->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexSource);
//    shader->addShaderFromSourceCode(QOpenGLShader::Fragment, fragSource);
//    shader->link();
//    m_posAttr = shader->attributeLocation("posAttr");
//    m_colAttr = shader->attributeLocation("colAttr");
//    shader->release();

//    vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
//    vbo->create();
//    vbo->bind();
//    vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);
//    vbo->allocate(vertices, sizeof(vertices));

//    shader->enableAttributeArray(0);
//    shader->enableAttributeArray(1);

//    shader->setAttributeBuffer(m_posAttr, GL_FLOAT, 2, 0);
//    shader->setAttributeBuffer(m_colAttr, GL_FLOAT, 3, 0);

//    glDrawArrays(GL_TRIANGLES, 0, 3);

//    shader->disableAttributeArray(1);
//    shader->disableAttributeArray(0);

}

AccuWeather::~AccuWeather()
{
    delete ui;
}
