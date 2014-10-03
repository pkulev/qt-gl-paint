#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QMouseEvent>
#include <QList>
#include <QPair>
#include <cmath>
#include <QDebug>

#include "common.hpp"


class DrawTool
{

public:
    virtual void startDrawing(GLint x, GLint y) {}
    virtual void update(GLint x, GLint y) {}
    virtual Object stopDrawing(GLint x, GLint y) {}
    virtual void drawTemporary() {}
    ~DrawTool() {}
};


class Pencil: public DrawTool
{
private:
    QColor color;
    Object temp;

public:
    Pencil();
    ~Pencil() {}
    void startDrawing(GLint x, GLint y);
    void update(GLint x, GLint y);
    Object stopDrawing(GLint x, GLint y);
    void drawTemporary();
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
};


#endif // OGLWIDGET_H
