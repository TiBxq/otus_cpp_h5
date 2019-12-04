#include "EditorManager.h"

//TODO: forward declaration?
//TODO: File Manager

void OnDraw()
{
    EditorManager::Instance().Draw();
}

void OnImportPressed(FileType type, const std::string& path)
{
    EditorManager::Instance().ImportDocument(type, path);
}

void OnExportPressed(FileType type, const std::string& path )
{
    EditorManager::Instance().ExportDocument(type, path);
}

void OnShapeAdded(ShapeType type)
{
    EditorManager::Instance().AddShape(type);
}

void OnShapeRemoved(Shape* shape)
{
    EditorManager::Instance().RemoveShape(shape);
}

int main(/*int argc, char const *argv[]*/)
{
    EditorManager& editor = EditorManager::Instance();

    editor.CreateDocument();
    OnDraw();

    return 0;
}
