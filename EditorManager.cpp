#include "EditorManager.h"
#include "Logger.h"

void EditorManager::CreateDocument()
{
    //TODO: name?
    m_document = new Document();
    Logger::Instance().Write("Document created");
}

void EditorManager::ImportDocument(FileType type)
{
    switch (type)
    {
    case FileType::SVG:
        if (m_document)
        {
            m_document->ImportFromSVG();
        }
        break;
    case FileType::EPS:
        if (m_document)
        {
            m_document->ImportFromEPS();
        }
        break;
    }
}

void EditorManager::ExportDocument(FileType type)
{
    switch (type)
    {
    case FileType::SVG:
        if (m_document)
        {
            m_document->ImportFromSVG();
        }
        break;
    case FileType::EPS:
        if (m_document)
        {
            m_document->ImportFromEPS();
        }
        break;
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