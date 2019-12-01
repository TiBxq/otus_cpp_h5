#include "File.h"
#include "Shape.h"

void FileSVG::Save(Shape* shape)
{
    shape->SaveToSVG(this);
}

void FileSVG::Load(Shape* shape)
{
    shape->LoadFromSVG(this);
}

void FileEPS::Save(Shape* shape)
{
    shape->SaveToEPS(this);
}

void FileEPS::Load(Shape* shape)
{
    shape->LoadFromEPS(this);
}