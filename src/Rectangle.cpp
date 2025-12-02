#include <Rectangle.h>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.2;
    height = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float width, float height, float r, float g, float b) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2); // top left corner
        glVertex2f(x + width/2, y + height/2); // top right corner
        glVertex2f(x + width/2, y - height/2); // bottom right corner
        glVertex2f(x - width/2, y - height/2); // bottom left corner
    glEnd();

    if (isSelected) {
        Rectangle inner = Rectangle(x, y, width-0.05, height-0.05, 1, 1, 1);
        inner.draw();
    }
}

bool Rectangle::contains(float mx, float my) {
    if (mx >= x-width/2 && mx <= x+width/2 && my >= y-height/2 && my <= y+height/2) {
        return true;
    }
    return false;
}