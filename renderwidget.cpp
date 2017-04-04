#include "renderwidget.h"

RenderWidget::RenderWidget(QWidget *parent) : QGLWidget(parent)
{
    camera = new CCamera();
    readTestData("C:\\Qt\\Projects\\TrianglesFlipper\\test_data\\block_00.bin");
}

void RenderWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.7,0.7,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);

    glGenBuffers(1, &vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, pointsN * sizeof(vec3), t_v, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glGenBuffers(1, &index_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, meshN * sizeof(vec3i), t_n ,GL_STATIC_DRAW);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    delete[] t_v;
    delete[] t_n;
}

void RenderWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0f,(float)w/(float)h,0.5f,1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera->SetView();

    glDisable(GL_LIGHTING);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex3f(-1000.0, 0, 0);
        glVertex3f(1000.0, 0, 0);
    glEnd();

    glColor3f(0.3, 0.2, 0.1);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBindVertexArray(vao_id);
    glDrawElements(GL_TRIANGLES, meshN * sizeof(vec3i), GL_UNSIGNED_INT, NULL);
    glBindVertexArray(0);

    glEnable(GL_LIGHTING);
}

void RenderWidget::readTestData(const char *filename)
{
    FILE *f = fopen(filename, "rb");
    if(!f)
    {
        qDebug() << "Couldnt open file" << filename;
        return;
    }
    fread(&pointsN, sizeof(int), 1, f);
    fread(&meshN, sizeof(int), 1, f);
    qDebug() << "Points count:" << pointsN;
    qDebug() << "Mesh count:" << meshN;
    t_v = new vec3[pointsN];
    t_n = new vec3i[meshN];
    fread(t_v, sizeof(vec3), pointsN, f);
    fread(t_n, sizeof(vec3i), meshN, f);
    fclose(f);
}

void RenderWidget::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();
    if(control_state.old_mx != -100 && control_state.old_my != -100)
    {
        float dx = (float)(x - control_state.old_mx);
        float dy = (float)(y - control_state.old_my);
        if(control_state.lm_btn)
        {
            camera->RotZ(180.0f * dx / (float)width());
            camera->RotXY(180.0f * dy / (float)height());
        }
    }
    control_state.old_mx = x;
    control_state.old_my = y;
    updateGL();
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        control_state.lm_btn = true;
    if(event->button() == Qt::RightButton)
        control_state.rm_btn = true;
}

void RenderWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        control_state.lm_btn = false;
    if(event->button() == Qt::RightButton)
        control_state.rm_btn = false;
}

void RenderWidget::wheelEvent(QWheelEvent *event)
{
    float dang = (float)event->angleDelta().y() / 8.0f;
    camera->Move(dang / 5.0f);
    updateGL();
}
