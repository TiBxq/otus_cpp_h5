#pragma once

class Shape
{
public:
    virtual void Draw() const = 0;
};

class Circle : public Shape
{
public:
    virtual void Draw() const override {}
};

class Rectangle : public Shape
{
public:
    virtual void Draw() const override {}
};