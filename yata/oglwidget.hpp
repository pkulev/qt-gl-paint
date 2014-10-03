#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QtOpenGL/QGLWidget>
#include <QMouseEvent>
#include <QList>
#include <cmath>
#include <QDebug>

#include "common.hpp"
#include "drawtools.hpp"

class OGLWidget : public QGLWidget
{
    Q_OBJECT

private:
    QList<Object> objects;
    QPoint lastPos;
    DrawTool *currentTool;
    QColor bgcolor;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public slots:
    void clearAll();
public:
    OGLWidget(QWidget *parent);
    void resizeGL(int w, int h);
    void initializeGL();
    void paintGL();
};


#endif // OGLWIDGET_H
