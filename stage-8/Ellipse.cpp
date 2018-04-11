// 
// Ellipse source
//

#include "./Ellipse.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>

Ellipse::Ellipse(Point p, int aa, int bb)
    : a{aa}, b{bb}
{
    add(p);
}

void Ellipse::draw() const
{
    fl_color(get_line_color());
    fl_line_style(get_line_style(), get_line_width());
    fl_arc(location().x - a, location().y - b, 2*a, 2*b, 0, 360);

    fl_line_style(0);
}
