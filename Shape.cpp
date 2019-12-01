#include "Shape.h"
#include "File.h"
#include "Logger.h"

//TODO: different file types?

void Circle::SaveToSVG(File*)
{
    Logger::Instance().Write("Circle saved to SVG");
}

void Circle::SaveToEPS(File*)
{
    Logger::Instance().Write("Circle saved to EPS");
}

void Circle::LoadFromSVG(File*)
{
    Logger::Instance().Write("Circle loaded from SVG");
}

void Circle::LoadFromEPS(File*)
{
    Logger::Instance().Write("Circle loaded from EPS");
}

void Rectangle::SaveToSVG(File*)
{
    Logger::Instance().Write("Rectangle saved to SVG");
}

void Rectangle::SaveToEPS(File*)
{
    Logger::Instance().Write("Rectangle saved to EPS");
}

void Rectangle::LoadFromSVG(File*)
{
    Logger::Instance().Write("Rectangle loaded from SVG");
}

void Rectangle::LoadFromEPS(File*)
{
    Logger::Instance().Write("Rectangle loaded from EPS");
}