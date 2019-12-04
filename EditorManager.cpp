#include "EditorManager.h"
#include "Logger.h"

void EditorManager::CreateDocument()
{
    //TODO: name?
    m_document = new Document();
    Logger::Instance().Write("Document created");
}

void EditorManager::ImportDocument(FileType type, const std::string& path )
{
    switch (type)
    {
    case FileType::SVG:
        if (m_document)
        {
            FileSVG* file = new FileSVG();
            file->Open(path);
            m_document->ImportFromSVG(file);
        }
        break;
    case FileType::EPS:
        if (m_document)
        {
            FileEPS* file = new FileEPS();
            file->Open(path);
            m_document->ImportFromEPS(file);
        }
        break;
    }
}

void EditorManager::ExportDocument(FileType type, const std::string& path)
{
    switch (type)
    {
    case FileType::SVG:
        if (m_document)
        {
            FileSVG* file = new FileSVG();
            m_document->ExportToSVG(file);
            file->SaveTo(path);
        }
        break;
    case FileType::EPS:
        if (m_document)
        {
            FileEPS* file = new FileEPS();
            m_document->ExportToEPS(file);
            file->SaveTo(path);
        }
        break;
    }
}

void EditorManager::AddShape(ShapeType type)
{
    switch (type)
    {
    case ShapeType::Circle:
        if (m_document)
        {
            m_document->AddCircle();
        }
        break;
    case ShapeType::Rectangle:
        if (m_document)
        {
            m_document->AddRectangle();
        }
        break;
    }
}

void EditorManager::RemoveShape(Shape* shape)
{
    if (m_document)
    {
        m_document->RemoveShape(shape);
    }
}

void EditorManager::Draw() const
{
    if (m_document)
    {
        m_document->Draw();
        Logger::Instance().Write("Draw");
    }
}

EditorManager::~EditorManager()
{
    delete m_document;
}