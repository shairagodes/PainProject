#include <Application.h>
#include <Color.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget *sender, float mx, float my) {
    TOOL tool = toolbar->getSelectedTool();
    Color color = colorSelector->getSelectedColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    } else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    } else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, 0.2, 0.2, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    } else if (tool == CIRCLE) {
        canvas->addCircle(mx, my, 0.1, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    } else if (tool == MOUSE) {
        Shape* shape = canvas->getSelectedShape(mx, my);
        selectedShape = shape;
        canvas->redraw();
    }
}

void Application::onCanvasDrag(bobcat::Widget *sender, float mx, float my) {
    TOOL tool = toolbar->getSelectedTool();
    Color color = colorSelector->getSelectedColor();

    if (tool == PENCIL) {
        canvas->addPoint(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    } else if (tool == ERASER) {
        canvas->addPoint(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    } else if (tool == MOUSE) {
        if (selectedShape) {
            selectedShape->setXY(mx, my);
            canvas->redraw();
        }
    }
}

void Application::onToolbarChange(bobcat::Widget *sender) {
    ACTION action = toolbar->getAction();

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
}

Application::Application() {
    window = new Window(25, 75, 400, 400, "Lecture 22");

    canvas = new Canvas(50, 0, 350, 350);

    toolbar = new Toolbar(0, 0, 50, 400);

    colorSelector = new ColorSelector(50, 350, 350, 50);

    selectedShape = nullptr;

    window->add(canvas);
    window->add(toolbar);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);

    window->show();
}

Application::~Application() {
    delete colorSelector;
    delete toolbar;
    delete canvas;
    delete window;
}