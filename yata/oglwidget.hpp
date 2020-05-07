#pragma once

#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QList>
#include <cmath>
#include <QDebug>

#include "common.hpp"
#include "drawtools.hpp"

class OGLWidget : public QOpenGLWidget
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
    ~OGLWidget();
    void resizeGL(int w, int h);
    void initializeGL();
    void paintGL();
};
