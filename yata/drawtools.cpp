#include "drawtools.hpp"

Pencil::Pencil()
    : DrawTool()
    {
    color = QColor(255, 0, 0);
}

void Pencil::startDrawing(GLint x, GLint y) {
    qDebug() << "Drawing with pencil";
    this->temp.clear();
    this->temp.append(Point(x, y));
}

void Pencil::update(GLint x, GLint y) {
    this->temp.append(Point(x, y));
}

Object Pencil::stopDrawing(GLint x, GLint y) {
    //Add temporary object into oglwidget's list
    this->temp.append(Point(x, y));
    qDebug() << "Stop drawing";
    return temp;
}

void Pencil::drawTemporary()
{
    glColor3f(color.red(), color.green(), color.blue());
    glBegin(GL_LINE_LOOP);
    for (auto &dot: temp) {
        glVertex2f(dot.first, dot.second);
    }
    glEnd();
}
