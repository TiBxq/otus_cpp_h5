#include "EditorManager.h"

//TODO: forward declaration?
//TODO: File Manager

void OnDraw()
{
    EditorManager::Instance().Draw();
}

void OnImportPressed(FileType type)
{
    EditorManager::Instance().ImportDocument(type);
}

void OnExportPressed(FileType type)
{
    EditorManager::Instance().ExportDocument(type);
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
