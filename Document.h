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

    void ImportFromSVG(FileSVG* file) {}
    void ImportFromEPS(FileEPS* file) {}
    void ExportToSVG(FileSVG* file);
    void ExportToEPS(FileEPS* file);

    void Draw() const;

    ~Document();

private:
    std::vector<Shape*> m_shapeList;
};