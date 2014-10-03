#include "oglwidget.hpp"




OGLWidget::OGLWidget(QWidget *parent=NULL) :
    QGLWidget(parent)
{
    currentTool = new Pencil();
    Object obj;
    obj.append(Point(10, 10));
    obj.append(Point(50, 100));
    obj.append(Point(150, 50));
    objects.append(obj);
}


void OGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
    if (event->buttons() & Qt::LeftButton) {
        currentTool->startDrawing(event->x(), event->y());
    } else if (event->buttons() & Qt::RightButton) {
        qDebug() << "Right button pressed";
    }
}


void OGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    GLint x = event->x();
    GLint y = event->y();
    GLint dx = event->x() - lastPos.x();
    GLint dy = event->y() - lastPos.y();

    lastPos = event->pos();
    this->currentTool->update(x, y);
    qDebug() << x << "; " << y << "  [" << dx << "; " << dy << "]";
}

void OGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() & Qt::LeftButton) {
        this->objects.append(currentTool->stopDrawing(event->x(), event->y()));
    }
}


void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       glOrtho(0, w, h, 0, -1, 1);
       glMatrixMode(GL_MODELVIEW);
}


void OGLWidget::initializeGL()
{
    glDisable(GL_DEPTH_TEST);
    glClearColor(0, 0.4, 0.7, 0);
    GLfloat w = width();
    GLfloat h = height();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, w, h, 0, -1, 1);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.3, 0.5);

    for(auto &o: objects) {
        glBegin(GL_LINE_LOOP);
        for(auto &dot: o) {
            glVertex2f(dot.first, dot.second);
        }
        glEnd();
        currentTool->drawTemporary();
    }
}

void OGLWidget::clearAll()
{
    this->objects.clear();
    this->bgcolor = QColor(255, 255, 255);
}


//void OGLWidget::drawCircle(GLint rad, GLint x, GLint y)
//{
//    Object obj;
//    for (int i = 0; i <= 50; i++) {
//        GLint cur_x = x + rad*cos(2*M_PI / 50 * i);
//        GLint cur_y = y + rad*sin(2*M_PI / 50 * i);
//        obj.append(Point(cur_x, cur_y));
//    }
//    objects.append(obj);
//}
