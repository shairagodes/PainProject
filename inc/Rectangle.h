#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <GL/freeglut.h>
#include <Shape.h>

class Rectangle {
    float width;
    float height;
  

public:
    Rectangle();

    Rectangle(float x, float y, float width, float height, float r, float g, float b);

    void draw();

    bool contains(float mx, float my);
};

#endif