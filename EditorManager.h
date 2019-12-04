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

    void ImportDocument(FileType type, const std::string& path);
    void ExportDocument(FileType type, const std::string& path);

    void AddShape(ShapeType type);
    void RemoveShape(Shape* shape);

    void Draw() const;

private:
    EditorManager() : m_document(nullptr) {}
    ~EditorManager();

    //TODO: more documents? smart pointer?
    Document* m_document;
};