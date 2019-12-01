#include "EditorManager.h"
#include "Logger.h"

void EditorManager::CreateDocument()
{
    //TODO: name?
    m_document = new Document();
    Logger::Instance().Write("Document created");
}

void EditorManager::ImportDocument()
{

}

void EditorManager::ExportDocument()
{

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