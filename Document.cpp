#include <algorithm>

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

void Document::RemoveShape(Shape* shape)
{
    m_shapeList.erase(std::find(m_shapeList.begin(), m_shapeList.end(), shape));
}

//TODO: file manager?

void Document::ImportFromSVG()
{
    for (Shape* shape : m_shapeList)
    {
        shape->LoadFromSVG(new FileSVG());
    }
}

void Document::ImportFromEPS()
{
    for (Shape* shape : m_shapeList)
    {
        shape->LoadFromEPS(new FileEPS());
    }
}

void Document::ExportToSVG()
{
    for (Shape* shape : m_shapeList)
    {
        shape->SaveToSVG(new FileSVG());
    }
}

void Document::ExportToEPS()
{
    for (Shape* shape : m_shapeList)
    {
        shape->SaveToEPS(new FileEPS());
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