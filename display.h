#ifndef DISPLAY_H

#include "openglwindow.h"
#include <vector>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QMatrix4x4>
#include <QtGui/QScreen>
#include <qdebug.h>
#include <QtCore/qmath.h>

struct nodeLine{
    GLfloat *vertex;
    int vertex_size = 0;
};

class display: public OpenGLWindow
{

public:
    display();

    std::vector<nodeLine> lineSet;
    void initialize() Q_DECL_OVERRIDE;
    void render() Q_DECL_OVERRIDE;
    void draw();

private:
    GLuint m_posAttr;
    GLuint m_matrixUniform;

    const char *vertexShaderSource =
            "attribute highp vec4 posAttr;\n"
            "varying lowp vec4 col;\n"
            "uniform highp mat4 matrix;\n"
            "void main() {\n"
            "   gl_Position = matrix * posAttr;\n"
            "   gl_PointSize = 4.0;\n"
            "}\n";

    const char *fragmentShaderSource =
            "void main() {\n"
            "   gl_FragColor = vec1(0,0,0,1.0); \n"
            "}\n";

    QOpenGLShaderProgram *m_program;
    int m_frame;
};

#define DISPLAY_H
#endif // DISPLAY_H
