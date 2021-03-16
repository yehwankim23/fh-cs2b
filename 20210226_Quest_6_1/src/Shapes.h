// Student ID: 20382528
// Quest: Magnum Octopus

#ifndef Shapes_h
#define Shapes_h

#include <iostream> // ostream
#include <string> // string
#include <vector> // vector

using namespace std;

class Screen
{
    friend class Shape;

private:
    size_t _w, _h;
    vector<vector<char>> _pix;

public:
    static const char FG = '*', BG = '.';

    Screen(size_t w, size_t h);

    size_t get_w() const { return _w; }
    size_t get_h() const { return _h; }
    vector<vector<char>>& get_pic() { return _pix; }

    void set_w(size_t w) { _w = w; }
    void set_h(size_t h) { _h = h; }

    void clear() { fill(BG); }
    void fill(char c);
    string to_string() const;

    friend ostream& operator<<(ostream& os, const Screen& scr)
    {
        return os << scr.to_string();
    }

    friend class Tests;
};

class Shape
{
public:
    virtual ~Shape() {}

    virtual bool draw(Screen& scr, char ch = Screen::FG) = 0;

    friend class Tests;
};

class Point : public Shape
{
private:
    size_t _x, _y;

public:
    Point(size_t x, size_t y) : _x(x), _y(y) {}
    virtual ~Point() {}

    bool draw(Screen& scr, char ch = Screen::FG);

    friend class Tests;
};

class Line : public Shape
{
private:
    size_t _x1, _y1, _x2, _y2;

    static bool draw_by_x(Screen& scr, char ch, size_t x1, size_t y1, size_t x2,
        size_t y2);
    static bool draw_by_y(Screen& scr, char ch, size_t x1, size_t y1, size_t x2,
        size_t y2);

public:
    Line(size_t a, size_t b, size_t c, size_t d) : _x1(a), _y1(b), _x2(c),
        _y2(d)
    {}
    virtual ~Line() {}

    bool draw(Screen& scr, char ch = Screen::FG);

    friend class Tests;
};

class Quadrilateral : public Shape
{
private:
    size_t _x1, _y1, _x2, _y2, _x3, _y3, _x4, _y4;

public:
    Quadrilateral(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f,
        size_t g, size_t h) : _x1(a), _y1(b), _x2(c), _y2(d), _x3(e), _y3(f),
        _x4(g), _y4(h)
    {}
    virtual ~Quadrilateral() {}

    bool draw(Screen& scr, char ch = Screen::FG);

    friend class Tests;
};

class Upright_Rectangle : public Quadrilateral
{
public:
    Upright_Rectangle(size_t x1, size_t y1, size_t x2, size_t y2)
        : Quadrilateral(x1, y1, x1, y2, x2, y2, x2, y1)
    {}
    virtual ~Upright_Rectangle() {}
};

class Stick_Man : public Shape
{
    static const size_t DEFAULT_W = 20, DEFAULT_H = 40;

private:
    size_t _x, _y, _w, _h;
    vector<Shape*> _parts;

public:
    Stick_Man(size_t x = 0, size_t y = 0, size_t w = DEFAULT_W,
        size_t h = DEFAULT_H);
    virtual ~Stick_Man() {}

    const vector<Shape*>& get_parts() const { return _parts; }

    bool draw(Screen& scr, char ch = Screen::FG);

    friend class Tests;
};

#endif
