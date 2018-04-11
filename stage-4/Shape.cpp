// 
// Shape source file
//

#include "./Shape.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>

void Shape::draw() const
{
    fl_color(line_color);
    fl_line_style(line_style, line_width);

    if (points.size() > 1)
        for (int i = 1; i < points.size(); ++i)
            fl_line(points[i-1].x, points[i-1].y, points[i].x, points[i].y);

    fl_line_style(0);
}
