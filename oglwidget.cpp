#include "oglwidget.h"

static const char* vertexSource =
    "#version 150\n"
    "in vec2 posAttr;\n"
    "in vec3 colAttr;\n"
    "in vec2 texcoords;\n"
    "out vec2 Texcoords;\n"
    "out vec3 Color;\n"
    "uniform mat4 matrix;\n"
    "void main() {\n"
    "   Color = colAttr;\n"
    "   Texcoords = texcoords;\n"
    "   gl_Position = vec4(posAttr, 0.0, 1.0) * matrix;"
    "}\n";

static const char* fragSource =
    "#version 150\n"
    "in vec3 Color;\n"
    "in vec2 Texcoords;\n"
    "uniform sampler2D texture;\n"
    "out vec4 outColor;\n"
    "void main() {\n"
    "   outColor = texture2D(texture, Texcoords);\n"
    "}\n";



OGLWidget::OGLWidget(QWidget* parent):
    QOpenGLWidget(parent)
{

}
OGLWidget::~OGLWidget()
{

}

void OGLWidget::initializeGL()
{

    initializeOpenGLFunctions();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    shader = new QOpenGLShaderProgram(this);
    shader->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexSource);
    shader->addShaderFromSourceCode(QOpenGLShader::Fragment, fragSource);
    shader->link();
    shader->bind();

    QImage i(":/images/accuweather.png");

    texture = new QOpenGLTexture(i);
    texture->setWrapMode(QOpenGLTexture::Repeat);


}
void OGLWidget::paintGL()
{

    static GLfloat vertices[] = {
        -0.5, 0.5f, 0.0f, 0.0f,     //1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 1.0f, 0.0f,     //0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 1.0f, 1.0f,    //0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f, 1.0f    //1.0f, 1.0f, 1.0f,

        };

    initializeOpenGLFunctions();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClear(GL_COLOR_BUFFER_BIT);

    texture->bind();

    m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_vbo->create();
    m_vbo->bind();
    m_vbo->allocate(vertices, sizeof(vertices));
    m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);

    shader->setUniformValue("texture", 0);

    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f/3.2f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    m_matrixUni = shader->uniformLocation("matrix");
    shader->setUniformValue(m_matrixUni, matrix);

    m_posAttr = shader->attributeLocation("posAttr");
    glEnableVertexAttribArray(m_posAttr);
    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);

//    m_colAttr = shader->attributeLocation("colAttr");
//    glEnableVertexAttribArray(m_colAttr);
//    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (void*)(2*sizeof(float)));

    m_texture = shader->attributeLocation("texcoords");
    glEnableVertexAttribArray(m_texture);
    glVertexAttribPointer(m_texture, 2, GL_FLOAT, GL_FLOAT, 4 * sizeof(GLfloat), (void*)(2*sizeof(float)));

    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);

    shader->disableAttributeArray(m_colAttr);
    shader->disableAttributeArray(m_posAttr);

}

void OGLWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}
