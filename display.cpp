#include "display.h"

display::display()
    : m_program(0)
    , m_frame(0)
{
    QSurfaceFormat format;
    format.setSamples(16);
    this->setFormat(format);
}

void display::initialize()
{
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    m_program->link();
    m_posAttr = m_program->attributeLocation("posAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");
}

void display::render()
{
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,1,1,1);
    glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND) ;
    glHint(GL_POINT_SMOOTH, GL_NICEST); //图像渲染质量

    m_program->bind();
    QMatrix4x4 matrix;
    matrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);
    matrix.rotate(100.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

    m_program->setUniformValue(m_matrixUniform, matrix);

    draw();
    m_program->release();

    ++m_frame;
}

void display::draw() {
    std::vector<nodeLine>::iterator nodeData;
    for (nodeData=lineSet.begin();nodeData!=lineSet.end();nodeData++){
        glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, nodeData->vertex);
        glEnableVertexAttribArray(0);

        glLineWidth(0.5f);
        glDrawArrays(GL_POINTS, 0, nodeData->vertex_size);
        glDrawArrays(GL_LINE_STRIP, 0, nodeData->vertex_size);
        glDisableVertexAttribArray(0);
    }
}
