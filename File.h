#pragma once
#include <string>

class Shape;

enum class FileType
{
    SVG, EPS
};

class File
{
public:
    virtual ~File() = default;

    virtual void Save(Shape* shape) = 0;
    virtual void Load(Shape* shape) = 0;

    virtual void Open(const std::string&) {}
    virtual void SaveTo(const std::string&) {}
};

class FileSVG : public File
{
public:
    FileSVG() = default;

    virtual void Save(Shape* shape) override;
    virtual void Load(Shape* shape) override;
};

class FileEPS : public File
{
public:
    FileEPS() = default;

    virtual void Save(Shape* shape) override;
    virtual void Load(Shape* shape) override;
};