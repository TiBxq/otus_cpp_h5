#include "Document.h"
#include "File.h"

void Document::AddCircle()
{
    m_shapeList.emplace_back(new Circle());
}

void Document::AddRectangle()
{
    m_shapeList.emplace_back(new Rectangle());
}

Shape* Document::GetShapeByCoord(int, int)
{
    return nullptr;
}

void Document::SelectShape(Shape* shape)
{
    m_selectedShape = shape;
}

void Document::UnselectShape()
{
    m_selectedShape = nullptr;
}

void Document::ExportToSVG(FileSVG* file)
{
    for (Shape* shape : m_shapeList)
    {
        shape->SaveToSVG(file);
    }
}

void Document::ExportToEPS(FileEPS* file)
{
    for (Shape* shape : m_shapeList)
    {
        shape->SaveToEPS(file);
    }
}

void Document::Draw() const
{
    for (const Shape* shape : m_shapeList)
    {
        shape->Draw();
    }
}

Document::~Document()
{
    for (const Shape* shape : m_shapeList)
    {
        delete shape;
    }
}