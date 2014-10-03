#ifndef DRAWTOOLS_HPP
#define DRAWTOOLS_HPP

#include <QColor>
#include <QDebug>

#include "common.hpp"


class DrawTool
{
public:
    virtual void startDrawing(GLint x, GLint y) = 0;
    virtual void update(GLint x, GLint y) = 0;
    virtual Object stopDrawing(GLint x, GLint y) = 0;
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

#endif // DRAWTOOLS_HPP
