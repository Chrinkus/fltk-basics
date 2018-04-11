// 
// Slider_output source file
//

#include "Slider_output.h"

Slider_output::Slider_output(Point pp, int ww, int hh, const std::string& s)
    :Widget{pp, ww, hh, s}
{
    const int horz_gap = 10;
    const int outbox_w = 40;
    const int button_w = 50;
    const int slider_w = ww - outbox_w - button_w - 2 * horz_gap;
    const int slider_offset = outbox_w + horz_gap;
    const int button_offset = slider_offset + slider_w + horz_gap;
    const Point slider_loc {pp.x + slider_offset, pp.y};
    const Point button_loc {pp.x + button_offset, pp.y};

    po = std::make_unique<Out_box>(pp, outbox_w, hh, "");
    ps = std::make_unique<Slider>(slider_loc, slider_w, hh, "");
    pb = std::make_unique<Button>(button_loc, button_w, hh, s);
}

void Slider_output::attach(Window& win)
{
    po->attach(win);
    ps->attach(win);
    pb->attach(win);

    ps->set_callback(cb_set_out, (void*)this);

    set_bounds(1, 100);     // default
    set_value(50);          // default
}

void Slider_output::set_callback(Callback cb, void* data)
{
    pb->set_callback(cb, data);
}
