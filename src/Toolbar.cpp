#include <Toolbar.h>

using namespace bobcat;

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50, "./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50, 50, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50, "./assets/polygon.png");
    clearButton = new Image(x, y + 300, 50, 50, "./assets/clear.png");

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);

    selectedTool = PENCIL;

    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick);
    ON_CLICK(clearButton, Toolbar::onClick);
}

void Toolbar::onClick(Widget* sender) {
    deselectAllTools();

    if (sender == pencilButton) {
        selectedTool = PENCIL;
    }
    else if (sender == eraserButton) {
        selectedTool = ERASER;
    }
    else if (sender == circleButton) {
        selectedTool = CIRCLE;
    }
    else if (sender == triangleButton) {
        selectedTool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        selectedTool = RECTANGLE;
    }
    else if (sender == polygonButton) {
        selectedTool = POLYGON;
    }
    else if (sender == clearButton) {
        selectedTool = CLEAR;
    }

    visualizeSelectedTool();
    redraw();
}

void Toolbar::visualizeSelectedTool() {
    if (selectedTool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (selectedTool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (selectedTool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (selectedTool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (selectedTool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    }
    else if (selectedTool == POLYGON) {
        polygonButton->color(FL_WHITE);
    }
    else if (selectedTool == CLEAR) {
        clearButton->color(FL_WHITE);
    }
}

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR);
    clearButton->color(FL_BACKGROUND_COLOR);
}

TOOL Toolbar::getSelectedTool() const {
    return selectedTool;
}