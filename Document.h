#pragma once
#include <vector>

#include "Shape.h"

class Document
{
public:
    void AddCircle();
    void AddRectangle();

    void RemoveShape(Shape* shape);

    void ImportFromSVG();
    void ImportFromEPS();
    void ExportToSVG();
    void ExportToEPS();

    void Draw() const;

    ~Document();

private:
    //TODO: smart pointers?
    std::vector<Shape*> m_shapeList;
};