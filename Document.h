#pragma once
#include <vector>

#include "Shape.h"

class FileSVG;
class FileEPS;

class Document
{
public:
    void AddCircle();
    void AddRectangle();

    void RemoveShape(const Shape*) {}
    
    Shape* GetShapeByCoord(int, int);
    Shape* GetSelectedShape() { return m_selectedShape; }

    void SelectShape(Shape* shape);
    void UnselectShape();

    void ImportFromSVG(FileSVG*) {}
    void ImportFromEPS(FileEPS*) {}
    void ExportToSVG(FileSVG* file);
    void ExportToEPS(FileEPS* file);

    void Draw() const;

    ~Document();

private:
    std::vector<Shape*> m_shapeList;
    Shape* m_selectedShape = nullptr;
};