#pragma once
#include <vector>

#include "Document.h"
#include "File.h"
#include "Shape.h"

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
    void RemoveDocument(const Document*) {}
    void RemoveCurrentDocument();

    void ImportDocument(FileType type, const std::string& path);
    void ExportDocument(FileType type, const std::string& path);

    void AddShape(ShapeType type);
    void RemoveSelectedShape();
    void SelectShape(int x, int y);
    Shape* GetSelectedShape();

    void Draw() const;

private:
    EditorManager() : m_currentDocument(nullptr) {}

    Document* m_currentDocument;
    std::vector<Document> m_documentList;
};