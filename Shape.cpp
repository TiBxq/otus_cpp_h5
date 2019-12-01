#include "Shape.h"
#include "File.h"
#include "Logger.h"

void Circle::SaveToSVG(File* file)
{
    Logger::Instance().Write("Circle saved to SVG");
}

void Circle::SaveToEPS(File* file)
{
    Logger::Instance().Write("Circle saved to EPS");
}

void Circle::LoadFromSVG(File* file)
{
    Logger::Instance().Write("Circle loaded from SVG");
}

void Circle::LoadFromEPS(File* file)
{
    Logger::Instance().Write("Circle loaded from EPS");
}

void Rectangle::SaveToSVG(File* file)
{
    Logger::Instance().Write("Rectangle saved to SVG");
}

void Rectangle::SaveToEPS(File* file)
{
    Logger::Instance().Write("Rectangle saved to EPS");
}

void Rectangle::LoadFromSVG(File* file)
{
    Logger::Instance().Write("Rectangle loaded from SVG");
}

void Rectangle::LoadFromEPS(File* file)
{
    Logger::Instance().Write("Rectangle loaded from EPS");
}