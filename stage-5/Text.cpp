// 
// Text source
//

#include "./Text.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>

Text::Text(Point p, const std::string& s)
    : content{s}
{
    add(p);
}

void Text::draw() const
{
    fl_font(font, size);
    fl_color(get_line_color());
    fl_draw(content.c_str(), location().x, location().y);
}
