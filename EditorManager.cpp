#include "EditorManager.h"
#include "Logger.h"

void EditorManager::CreateDocument()
{
    m_documentList.emplace_back(Document());
    m_currentDocument = &m_documentList.back();
    Logger::Instance().Write("Document created");
}

void EditorManager::ImportDocument(FileType type, const std::string& path )
{
    switch (type)
    {
    case FileType::SVG:
        if (m_currentDocument)
        {
            FileSVG* file = new FileSVG();
            file->Open(path);
            m_currentDocument->ImportFromSVG(file);
        }
        break;
    case FileType::EPS:
        if (m_currentDocument)
        {
            FileEPS* file = new FileEPS();
            file->Open(path);
            m_currentDocument->ImportFromEPS(file);
        }
        break;
    }
}

void EditorManager::ExportDocument(FileType type, const std::string& path)
{
    switch (type)
    {
    case FileType::SVG:
        if (m_currentDocument)
        {
            FileSVG* file = new FileSVG();
            m_currentDocument->ExportToSVG(file);
            file->SaveTo(path);
        }
        break;
    case FileType::EPS:
        if (m_currentDocument)
        {
            FileEPS* file = new FileEPS();
            m_currentDocument->ExportToEPS(file);
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
        if (m_currentDocument)
        {
            m_currentDocument->AddCircle();
        }
        break;
    case ShapeType::Rectangle:
        if (m_currentDocument)
        {
            m_currentDocument->AddRectangle();
        }
        break;
    }
}

void EditorManager::RemoveShape(const Shape* shape)
{
    if (m_currentDocument)
    {
        m_currentDocument->RemoveShape(shape);
    }
}

void EditorManager::Draw() const
{
    if (m_currentDocument)
    {
        m_currentDocument->Draw();
        Logger::Instance().Write("Draw");
    }
}