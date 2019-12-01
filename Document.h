#pragma once
#include <vector>

#include "Shape.h"

class Document
{
public:
    void AddCircle();
    void AddRectangle();

    void RemoveShape(Shape* shape);

    void Draw() const;

    ~Document();

private:
    //TODO: smart pointers?
    std::vector<Shape*> m_shapeList;
};