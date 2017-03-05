#include <QtGui/QGuiApplication>
#include "display.h"

#include <qdebug.h>

class NeuroPoint
{
public:
    int x = 0;
    int y = 0;
    int z = 0;
    NeuroPoint(int m_x,int m_y,int m_z) {
        x=m_x;
        y=m_y;
        z=m_z;
    };
};

//邻接表表节点
struct Neuro_EdgeNode
{
    size_t adjvertex;	//临接点域，顶点对应序号
    Neuro_EdgeNode *next = NULL;	//指向下一个邻接点的指针域
};

//邻接表顶点节点
struct Neuro_VertexNode
{
    NeuroPoint vertex;	//顶点域
    Neuro_EdgeNode *firstedge = NULL;	//边表头指针
    void print() const;
};

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    display window;
    window.resize(1000, 480);

    GLfloat m_vertices[] = {
        0.0f, 0.707f,-0.5f,
        -0.5f,0.5f, -0.5f
    };
    nodeLine d1;
    d1.vertex = m_vertices;
    d1.vertex_size = 2;


    GLfloat kk[] = {
        0.0f, 0.707f,-0.5f,
        -0.9f,0.3f, -0.3f
    };

    nodeLine d2;
    d2.vertex = kk;
    d2.vertex_size = 2;

    GLfloat k3[] = {
        0.0f, 0.707f,-0.5f,
        -0.7f,0.8f, -0.8f
    };

    nodeLine d3;
    d3.vertex = k3;
    d3.vertex_size = 2;

    window.lineSet.push_back(d1);
    window.lineSet.push_back(d2);
    window.lineSet.push_back(d3);

    window.show();

    window.setAnimating(true);

    return app.exec();
}

