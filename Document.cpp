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

}

//TODO: file manager?

void Document::ImportFromSVG(FileSVG* file)
{

}

void Document::ImportFromEPS(FileEPS* file)
{

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