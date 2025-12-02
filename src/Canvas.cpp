#include <Canvas.h>

Canvas::Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
    //
}

void Canvas::addPoint(float mx, float my, float r, float g, float b, int size) {
    points.push_back(new Point(mx, my, r, g, b, size));
}

void Canvas::addCircle(float mx, float my, float radius, float r, float g, float b) {
    circles.push_back(new Circle(mx, my, radius, r, g, b));
}

void Canvas::addRectangle(float mx, float my, float width, float height, float r, float g, float b) {
    rectangles.push_back(new Rectangle(mx, my, width, height, r, g, b));
}



// Shape* Canvas::getSelectedShape(float mx, float my) {
//     Shape* shape = nullptr;

//     for (unsigned int i = 0; i < shapes.size(); i++) {
//         shapes[i]->deselect();
//     }

//     for (unsigned int i = 0; i < shapes.size(); i++) {
//         if (shapes[i]->contains(mx, my)) {
//             shape = shapes[i];
//             shape->select();
//             break;
//         }
//     }

//     return shape;
// }

void Canvas::clear() {
    for (unsigned int i = 0; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();

    for (unsigned int i = 0; i < rectangles.size(); i++) {
        delete rectangles[i];
    }
    rectangles.clear();

    for (unsigned int i = 0; i < circles.size(); i++){
        delete circles[i];
    }
    circles.clear();

    

}

// void Canvas::render() {
//     for (unsigned int i = 0; i < shapes.size(); i++) {
//         shapes[i]->draw();
//     }
// }

Canvas::~Canvas(){
    clear();
}