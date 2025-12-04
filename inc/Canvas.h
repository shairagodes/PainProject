#ifndef CANVAS_H
#define CANVAS_H

#include <Point.h>
#include <Shape.h>
#include <Circle.h>
#include <bobcat_ui/all.h>
#include <vector>


class Canvas : public bobcat::Canvas_ {
    std::vector<Shape *> shapes;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float mx, float my, float r, float g, float b, int size);

    void addCircle(float mx, float my, float radius, float r, float g, float b);

    void addRectangle(float mx, float my, float width, float height, float r, float g, float b);
    
    Shape* getSelectedShape(float mx, float my);

    void clear();

    void render(); 

    ~Canvas();
};

#endif