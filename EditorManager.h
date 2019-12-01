#pragma once
#include <vector>

#include "Document.h"

class EditorManager
{
public:
    EditorManager(const EditorManager&) = delete;
    EditorManager& operator=(const EditorManager&) = delete;

    static EditorManager& Instance()
    {
        static EditorManager instance;
        return instance;
    }

    void CreateDocument();
    void ImportDocument();
    void ExportDocument();

    void Draw() const;

private:
    EditorManager() : m_document(nullptr) {}
    ~EditorManager();

    //TODO: more documents? smart pointer?
    Document* m_document;
};