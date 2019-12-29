#include "EditorManager.h"

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

void OnShapeSelected(int x, int y)
{
    EditorManager::Instance().SelectShape(x, y);
}

void OnSelectedShapeRemoved()
{
    EditorManager::Instance().RemoveSelectedShape();
}

void OnCurrentDocumentRemoved()
{
    EditorManager::Instance().RemoveCurrentDocument();
}

int main(/*int argc, char const *argv[]*/)
{
    EditorManager& editor = EditorManager::Instance();

    editor.CreateDocument();
    OnImportPressed(FileType::SVG, "myFile.svg");
    OnShapeAdded(ShapeType::Circle);
    OnShapeAdded(ShapeType::Rectangle);
    OnDraw();
    OnExportPressed(FileType::EPS, "myFile.eps");

    return 0;
}
