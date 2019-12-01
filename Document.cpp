#include "Document.h"

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