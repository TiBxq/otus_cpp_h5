#include "Shape.h"
#include "File.h"
#include "Logger.h"

void Circle::SaveToSVG(FileSVG*)
{
    Logger::Instance().Write("Circle saved to SVG");
}

void Circle::SaveToEPS(FileEPS*)
{
    Logger::Instance().Write("Circle saved to EPS");
}

void Circle::LoadFromSVG(FileSVG*)
{
    Logger::Instance().Write("Circle loaded from SVG");
}

void Circle::LoadFromEPS(FileEPS*)
{
    Logger::Instance().Write("Circle loaded from EPS");
}

void Circle::Draw() const
{
    Logger::Instance().Write("Circle drawn");
}

void Rectangle::SaveToSVG(FileSVG*)
{
    Logger::Instance().Write("Rectangle saved to SVG");
}

void Rectangle::SaveToEPS(FileEPS*)
{
    Logger::Instance().Write("Rectangle saved to EPS");
}

void Rectangle::LoadFromSVG(FileSVG*)
{
    Logger::Instance().Write("Rectangle loaded from SVG");
}

void Rectangle::LoadFromEPS(FileEPS*)
{
    Logger::Instance().Write("Rectangle loaded from EPS");
}

void Rectangle::Draw() const
{
    Logger::Instance().Write("Rectangle drawn");
}