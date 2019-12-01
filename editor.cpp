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

int main(/*int argc, char const *argv[]*/)
{
    EditorManager& editor = EditorManager::Instance();

    editor.CreateDocument();
    OnDraw();

    return 0;
}
