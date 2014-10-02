#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QMouseEvent>
#include <QList>
#include <QPair>
#include <cmath>
#include <QDebug>

using Object = QList<QPair<GLint,GLint> >;

class DrawTool
{

public:
    //DrawTool() {};
    virtual void startDrawing(GLint x, GLint y) {}
    virtual void stopDrawing(GLint x, GLint y) {}
    ~DrawTool() {}
};


class Pencil: public DrawTool
{
private:
    QColor color;
    bool drawing;

public:
    Pencil();
    ~Pencil() {}
    void startDrawing(GLint x, GLint y);
    void stopDrawing(GLint x, GLint y);
};


class OGLWidget : public QGLWidget
{
    Q_OBJECT

private:
    QList<Object> objects;
    QPoint lastPos;
    DrawTool *currentTool;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    OGLWidget(QWidget *parent);
    void resizeGL(int w, int h);
    void initializeGL();
    void paintGL();

public slots:
    void drawCircle(GLint rad, GLint x, GLint y);
};


#endif // OGLWIDGET_H
