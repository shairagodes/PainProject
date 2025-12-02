#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <iostream>

class Shape {
protected:
    float x;
    float y;
    float r;
    float g;
    float b;
    bool isSelected;

public:
    Shape() {
        x = 0.0;
        y = 0.0;
        r = 0.0;
        g = 0.0;
        b = 0.0;
        isSelected = false;
    }

    virtual void draw() = 0;

    virtual bool contains(float mx, float my) {
        return false;
    }

    void select() {
        isSelected = true;
    }

    void deselect() {
        isSelected = false;
    }

    void setXY(float x, float y) {
        this->x = x;
        this->y = y;
    }

    virtual ~Shape() {
        
    };
};

#endif