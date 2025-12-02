#ifndef CANVAS_H
#define CANVAS_H

#include <Point.h>
#include <Shape.h>
#include <Rectangle.h>
#include <Circle.h>
#include <Polygon.h>
#include <Triangle.h>
#include <bobcat_ui/all.h>
#include <vector>
#include <Enums.h>

using namespace std;

class Canvas : public bobcat::Canvas_ {
    vector<Point *> points; 
    //vector<Shape*> shapes;
    vector<Rectangle *> rectangles;
    vector<Circle *> circles;
    vector<Triangle*> triangles; 
    vector<Polygon*> polygons;

public:
    Canvas(int x, int y, int w, int h);

    void addPoint(float mx, float my, float r, float g, float b, int size);

    void addCircle(float mx, float my, float radius, float r, float g, float b);

    void addRectangle(float mx, float my, float width, float height, float r, float g, float b);

    void addPolygon(float x, float y, int sides, float length, float r, float g, float b);

    void addTriangle(float x, float y, float base, float height, float r, float g, float b);
    
    Shape* getSelectedShape(float mx, float my);

    void clear();

    void render(); 

    ~Canvas();
};

#endif