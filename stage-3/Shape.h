// 
// Shape header
//
// This will be the abstract class for Window objects to interface with the 
// various Shape entities that I will need.
// 

#ifndef SHAPE_H
#define SHAPE_H

#include "./Point.h"

class Shape {
    public:
        Shape(Point xy) : loc{xy} { }

        virtual void draw() const { }

        void set_line_color(int c) { line_color = c; }
        int get_line_color() const { return line_color; }

    protected:
        Point loc;
    private:
        int line_color;
};

#endif  /* SHAPE_H */
