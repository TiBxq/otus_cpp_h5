#include "EditorManager.h"

//TODO: forward declaration?
//TODO: File Manager


void OnDraw()
{
    EditorManager::Instance().Draw();
}

void OnImportPressed()
{
    EditorManager::Instance().ImportDocument();
}

void OnExportPressed()
{
    EditorManager::Instance().ExportDocument();
}

int main(/*int argc, char const *argv[]*/)
{
    EditorManager& editor = EditorManager::Instance();

    editor.CreateDocument();
    OnDraw();

    return 0;
}
