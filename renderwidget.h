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

    bool isNeighbouring(vec3i a, vec3i b);

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
