#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <Enums.h>
#include <bobcat_ui/all.h>

class Toolbar : public bobcat::Group {
    bobcat::Image* pencilButton;
    bobcat::Image* eraserButton;
    bobcat::Image* circleButton;
    bobcat::Image* triangleButton;
    bobcat::Image* rectangleButton;
    bobcat::Image* polygonButton;
    bobcat::Image* clearButton;
    bobcat::Image* mouseButton;

    TOOL selectedTool;
    ACTION action; 

    void onClick(bobcat::Widget* sender);
    void visualizeSelectedTool();
    void deselectAllTools();

public:
    Toolbar(int x, int y, int w, int h);

    TOOL getSelectedTool() const;
    ACTION getAction() const;

    ~Toolbar();
};

#endif