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

    flipTriangles();

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

void RenderWidget::flipTriangles()
{
    for(int iter = 0; iter < 5; iter++) {
        int numt = 0;
        for(int mesh = 0; mesh < meshN - 1; mesh++)
        {
            vec4i res = {-1, -1, -1, -1};
            vec2i edge = {0, 0};
            vec2i reverse = {0, 0};
            if(isNeighbouringByEdge(t_n[mesh], t_n[mesh+1], res, edge, reverse)) {
                if(checkCorrectQuad(res)) {
                    vec3 p0, p1, p2, p3;
                    memcpy(p0, t_v[res[3]], sizeof(vec3));
                    memcpy(p1, t_v[res[0]], sizeof(vec3));
                    memcpy(p2, t_v[res[1]], sizeof(vec3));
                    memcpy(p3, t_v[res[2]], sizeof(vec3));


                    if(val < 0.01) {
                        vec3i nt_1 = {
                            reverse[0],
                            reverse[1],
                            edge[0],
                        };
                        vec3i nt_2 = {
                            edge[1],
                            reverse[0],
                            reverse[1]
                        };
                        numt++;
                        memcpy(t_n[mesh], nt_1, sizeof(vec3i));
                        memcpy(t_n[mesh+1], nt_2, sizeof(vec3i));
                    }
                }
                else
                {
                    qDebug() << "Error";
                    //qDebug() << t_n[mesh][0] << t_n[mesh][1] << t_n[mesh][2];
                    //qDebug() << t_n[mesh+1][0] << t_n[mesh+1][1] << t_n[mesh+1][2];
                    //qDebug() << "Res: " << res[0] << res[1] << res[2] << res[3];
                    //qDebug() << "===============================================";
                }
            }
        }
        qDebug() << numt << " triangles flipped";
    }
}

int RenderWidget::getNeighbourTrianglePoint(vec3i a, vec3i b)
{
    if(b[0] != a[0] && b[0] != a[1] && b[0] != a[2])
        return b[0];
    if(b[1] != a[0] && b[1] != a[1] && b[1] != a[2])
        return b[1];
    if(b[2] != a[0] && b[2] != a[1] && b[2] != a[2])
        return b[2];
    return -1;
}

bool RenderWidget::isNeighbouringByEdge(vec3i a, vec3i b, vec4i &res, vec2i &edge, vec2i &reverse)
{
    int ind = 0;
    if(a[0] == b[0] || a[0] == b[1] || a[0] == b[2]) {
        res[0] = a[0];
        ind++;
    }
    if(a[1] == b[0] || a[1] == b[1] || a[1] == b[2]) {
        ind++;
        res[1] = a[1];
    }
    if(a[2] == b[0] || a[2] == b[1] || a[2] == b[2]) {
        ind++;
        res[2] = a[2];
    }
    if(res[0] == -1 && res[3] == -1) {
        if(a[1] == b[1] && a[2] == b[0]) { res[0] = a[0]; res[3] = b[2]; }
        if(a[1] == b[0] && a[2] == b[2]) { res[0] = a[0]; res[3] = b[1]; }
        if(a[1] == b[2] && a[2] == b[1]) { res[0] = a[0]; res[3] = b[0]; }
        if(a[1] == b[2] && a[2] == b[0]) { res[0] = a[0]; res[3] = b[1]; }
        if(a[1] == b[0] && a[2] == b[1]) { res[0] = a[0]; res[3] = b[2]; }
        if(a[1] == b[1] && a[2] == b[2]) { res[0] = a[0]; res[3] = b[0]; }
        edge[0] = res[1]; edge[1] = res[2];
        reverse[0] = res[0]; reverse[1] = res[3];
    }
    if(res[2] == -1 && res[3] == -1) {
        if(a[0] == b[2] && a[1] == b[1]) { res[2] = a[2]; res[3] = b[0]; }
        if(a[0] == b[0] && a[1] == b[2]) { res[2] = a[2]; res[3] = b[1]; }
        if(a[0] == b[1] && a[1] == b[0]) { res[2] = a[2]; res[3] = b[2]; }
        if(a[0] == b[0] && a[1] == b[1]) { res[2] = a[2]; res[3] = b[2]; }
        if(a[0] == b[2] && a[1] == b[0]) { res[2] = a[2]; res[3] = b[1]; }
        if(a[0] == b[1] && a[1] == b[2]) { res[2] = a[2]; res[3] = b[0]; }
        edge[0] = res[0]; edge[1] = res[1];
        reverse[0] = res[2]; reverse[1] = res[3];
    }
    if(res[1] == -1 && res[3] == -1) {
        if(a[0] == b[1] && a[2] == b[2]) { res[1] = a[1]; res[3] = b[0]; }
        if(a[0] == b[0] && a[2] == b[1]) { res[1] = a[1]; res[3] = b[2]; }
        if(a[0] == b[2] && a[2] == b[0]) { res[1] = a[1]; res[3] = b[1]; }
        if(a[0] == b[0] && a[2] == b[2]) { res[1] = a[1]; res[3] = b[1]; }
        if(a[0] == b[1] && a[2] == b[0]) { res[1] = a[1]; res[3] = b[2]; }
        if(a[0] == b[2] && a[2] == b[1]) { res[1] = a[1]; res[3] = b[0]; }
        edge[0] = res[0]; edge[1] = res[2];
        reverse[0] = res[1]; reverse[1] = res[3];
    }
    if(ind == 2)
        return true;
    return false;
}

bool RenderWidget::isNeighbouringByVertex(vec3i a, vec3i b)
{
    int ind = 0;
    if(a[0] == b[0] || a[0] == b[1] || a[0] == b[2]) {
        ind++;
    }
    if(a[1] == b[0] || a[1] == b[1] || a[1] == b[2]) {
        ind++;
    }
    if(a[2] == b[0] || a[2] == b[1] || a[2] == b[2]) {
        ind++;
    }
    if(ind == 1)
        return true;
    return false;
}

bool RenderWidget::checkCorrectQuad(vec4i q)
{
    if(q[0] == q[1] || q[0] == q[2] || q[0] == q[3])
        return false;
    if(q[1] == q[2] || q[1] == q[3])
        return false;
    if(q[2] == q[3])
        return false;
    return true;
}

void RenderWidget::flip(vec3i t1,
                        vec3i t2,
                        vec4i quad,
                        vec2i edge,
                        vec2i reverse_edge,
                        vec3i &r1,
                        vec3i &r2)
{
    qDebug() << "Edge" << edge[0] << edge[1];
    qDebug() << "Reverse" << reverse_edge[0] << reverse_edge[1];
    qDebug() << "=====================";
    r1[0] = edge[0];
    r1[1] = reverse_edge[1];
    r1[2] = reverse_edge[2];

    r2[0] = reverse_edge[1];
    r2[1] = reverse_edge[2];
    r2[2] = edge[1];
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
