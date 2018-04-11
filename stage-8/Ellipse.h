// 
// Ellipse header
//

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "./Shape.h"

class Ellipse : public Shape {
    public:
        Ellipse(Point p, int aa, int bb);

        void set_a(int aa) { a = aa; }
        void set_b(int bb) { b = bb; }

        void draw() const override;
    private:
        int a, b;       // major and minor radii
};

#endif
