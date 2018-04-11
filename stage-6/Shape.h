// Shape header
//
// This will be the abstract class for Window objects to interface with the 
// various Shape entities that I will need.
// 
// Includes the Line struct due to its simplicity.

#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include "./Point.h"

class Shape {
    public:
        virtual void draw() const;

        void set_line_color(int c) { line_color = c; }
        int get_line_color() const { return line_color; }

        void set_line_width(int w) { line_width = w; }
        int get_line_width() const { return line_width; }

        void set_line_style(int s) { line_style = s; }
        int get_line_style() const { return line_style; }

        Point location() const { return points[0]; }

        virtual ~Shape() { }
    protected:
        Shape() { }

        void add(Point p) { points.push_back(p); }
    private:
        std::vector<Point> points;
        int line_color { 0 };
        int line_style { 0 };
        int line_width { 2 };
};

struct Line : Shape {
    Line(Point p1, Point p2) { add(p1); add(p2); }
};

#endif
