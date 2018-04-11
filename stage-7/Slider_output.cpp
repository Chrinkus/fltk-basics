// 
// Slider_output source file
//

#include "Slider_output.h"

Slider_output::Slider_output(Point pp, int ww, int hh, const std::string& s)
    :Widget{pp, ww, hh, s}
{
    const int out_w = 40;
    const int horz_gap = 10;
    const int slider_offset = out_w + horz_gap;
    const Point slider_loc {pp.x + slider_offset, pp.y};

    po = std::make_unique<Out_box>(pp, out_w, hh, s);
    ps = std::make_unique<Slider>(slider_loc, ww - slider_offset, hh, "");
}

void Slider_output::attach(Window& win)
{
    po->attach(win);
    ps->attach(win);

    ps->set_callback(cb_set_out, (void*)this);

    set_bounds(1, 100);     // default
    set_value(50);          // default
}

void Slider_output::set_callback(Callback cb, void* data)
{
    // to be defined later..
}
