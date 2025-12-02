#ifndef APPLICATION_H
#define APPLICATION_H

#include <Canvas.h>
#include <ColorSelector.h>
#include <Toolbar.h>
#include <bobcat_ui/all.h>

class Application : public bobcat::Application_ {
    bobcat::Window *window;
    Canvas *canvas;
    Toolbar *toolbar;
    ColorSelector *colorSelector;
    Shape* selectedShape;

    void onCanvasMouseDown(bobcat::Widget *sender, float mx, float my);
    void onCanvasDrag(bobcat::Widget *sender, float mx, float my);
    void onToolbarChange(bobcat::Widget *sender);

public:
    Application();

    ~Application();

    friend struct ::AppTest;
};

#endif