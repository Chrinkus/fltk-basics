// 
// Text source
//

#include "./Text.h"
#include <FL/fl_draw.H>

void Text::draw() const
{
    fl_font(font, size);
    fl_color(get_line_color());
    fl_draw(content.c_str(), loc.x, loc.y);
}
