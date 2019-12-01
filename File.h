#pragma once

class Shape;

class File
{
    virtual ~File() = default;

    virtual void Save(Shape* shape) = 0;
    virtual void Load(Shape* shape) = 0;
};

class FileSVG : public File
{
    virtual void Save(Shape* shape) override;
    virtual void Load(Shape* shape) override;
};

class FileEPS : public File
{
    virtual void Save(Shape* shape) override;
    virtual void Load(Shape* shape) override;
};