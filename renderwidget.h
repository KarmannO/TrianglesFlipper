#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H
#include "camera.h"
#include <QGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include "vectors.h"
#include <QDebug>
#include <QOpenGLContext>
#include <QWheelEvent>
#include <QMouseEvent>
#include "controlbuttonstate.h"

class RenderWidget : public QGLWidget, public QOpenGLFunctions_3_3_Core
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = 0);

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void readTestData(const char *filename);
    void flipTriangles();

    int getNeighbourTrianglePoint(vec3i a, vec3i b);
    bool isNeighbouringByEdge(vec3i a, vec3i b, vec4i &res, vec2i &edge, vec2i &reverse);
    bool isNeighbouringByVertex(vec3i a, vec3i b);
    bool checkCorrectQuad(vec4i q);
    void flip(vec3i t1, vec3i t2, vec4i quad, vec2i edge, vec2i reverse_edge, vec3i &r1, vec3i &r2);

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
private:
    CCamera *camera;
    int pointsN, meshN;
    vec3 *t_v;
    vec3i *t_n;

    GLuint vao_id;
    GLuint vbo_id;
    GLuint index_id;
    QOpenGLContext* ctx;
    CControlButtonState control_state;
};

#endif // RENDERWIDGET_H
