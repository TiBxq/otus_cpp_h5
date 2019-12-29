#include "EditorManager.h"
#include "Logger.h"

void EditorManager::CreateDocument()
{
    m_documentList.emplace_back(Document());
    m_currentDocument = &m_documentList.back();
    Logger::Instance().Write("Document created");
}

void EditorManager::RemoveCurrentDocument()
{
    if (m_currentDocument)
    {
        RemoveDocument(m_currentDocument);
        if (!m_documentList.empty())
        {
            m_currentDocument = &m_documentList.back();
        }
        else
        {
            m_currentDocument = nullptr;
        }
    }
}

void EditorManager::ImportDocument(FileType type, const std::string& path )
{
    switch (type)
    {
    case FileType::SVG:
        if (m_currentDocument)
        {
            FileSVG file;
            file.Open(path);
            m_currentDocument->ImportFromSVG(file);
        }
        break;
    case FileType::EPS:
        if (m_currentDocument)
        {
            FileEPS file;
            file.Open(path);
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
            delete file;
        }
        break;
    case FileType::EPS:
        if (m_currentDocument)
        {
            FileEPS* file = new FileEPS();
            m_currentDocument->ExportToEPS(file);
            file->SaveTo(path);
            delete file;
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

void EditorManager::RemoveSelectedShape()
{
    if (m_currentDocument)
    {
        Shape* selected = m_currentDocument->GetSelectedShape();
        if (selected)
        {
            m_currentDocument->RemoveShape(selected);
            m_currentDocument->UnselectShape();
        }
    }
}

void EditorManager::SelectShape(int x, int y)
{
    if (m_currentDocument)
    {
        Shape* selected = m_currentDocument->GetShapeByCoord(x, y);
        if (selected)
        {
            m_currentDocument->SelectShape(selected);
        }
    }
}

Shape* EditorManager::GetSelectedShape()
{
    if (m_currentDocument)
    {
        return m_currentDocument->GetSelectedShape();
    }
    return nullptr;
}

void EditorManager::Draw() const
{
    if (m_currentDocument)
    {
        m_currentDocument->Draw();
    }
}