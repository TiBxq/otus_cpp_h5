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

    void RemoveShape(Shape* shape);

    void ImportFromSVG(FileSVG* file);
    void ImportFromEPS(FileEPS* file);
    void ExportToSVG(FileSVG* file);
    void ExportToEPS(FileEPS* file);

    void Draw() const;

    ~Document();

private:
    //TODO: smart pointers?
    std::vector<Shape*> m_shapeList;
};