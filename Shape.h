#pragma once

class File;

class Shape
{
public:
    virtual ~Shape() = default;

    virtual void Draw() const = 0;

    virtual void SaveToSVG(File* file) = 0;
    virtual void SaveToEPS(File* file) = 0;
    virtual void LoadFromSVG(File* file) = 0;
    virtual void LoadFromEPS(File* file) = 0;
};

class Circle : public Shape
{
public:
    virtual void Draw() const override {}

    virtual void SaveToSVG(File* file) override;
    virtual void SaveToEPS(File* file) override;
    virtual void LoadFromSVG(File* file) override;
    virtual void LoadFromEPS(File* file) override;
};

class Rectangle : public Shape
{
public:
    virtual void Draw() const override {}

    virtual void SaveToSVG(File* file) override;
    virtual void SaveToEPS(File* file) override;
    virtual void LoadFromSVG(File* file) override;
    virtual void LoadFromEPS(File* file) override;
};