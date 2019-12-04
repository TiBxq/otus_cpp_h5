#pragma once

class FileSVG;
class FileEPS;

enum class ShapeType
{
    Circle, Rectangle
};

class Shape
{
public:
    virtual ~Shape() = default;

    virtual void Draw() const = 0;

    virtual void SaveToSVG(FileSVG* file) = 0;
    virtual void SaveToEPS(FileEPS* file) = 0;
    virtual void LoadFromSVG(FileSVG* file) = 0;
    virtual void LoadFromEPS(FileEPS* file) = 0;
};

class Circle : public Shape
{
public:
    virtual void Draw() const override {}

    virtual void SaveToSVG(FileSVG* file) override;
    virtual void SaveToEPS(FileEPS* file) override;
    virtual void LoadFromSVG(FileSVG* file) override;
    virtual void LoadFromEPS(FileEPS* file) override;
};

class Rectangle : public Shape
{
public:
    virtual void Draw() const override {}

    virtual void SaveToSVG(FileSVG* file) override;
    virtual void SaveToEPS(FileEPS* file) override;
    virtual void LoadFromSVG(FileSVG* file) override;
    virtual void LoadFromEPS(FileEPS* file) override;
};