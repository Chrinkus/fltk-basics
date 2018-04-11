//
// Ctrl_ellipse source
//

#include "Ctrl_ellipse.h"

Ctrl_ellipse::Ctrl_ellipse(Point pp, int aa, int bb, Ellipse_controller& ec,
        Window& win_ref)
    : Ellipse{pp, aa, bb}, ctrl{ec}, win{win_ref}
{
    ctrl.set_a_ctrl(cb_set_a, (void*)this);
    ctrl.set_b_ctrl(cb_set_b, (void*)this);
}

void Ctrl_ellipse::change_a()
{
    set_a(ctrl.get_a_value());
    win.redraw();
}

void Ctrl_ellipse::change_b()
{
    set_b(ctrl.get_b_value());
    win.redraw();
}

Ellipse_controller::Ellipse_controller(Point pp, int ww, int hh,
        const std::string& ss)
    : Widget{pp, ww, hh, ss}
{
    const int vert_gap = 5;
    const Point p2 {pp.x, pp.y + hh + vert_gap};

    a_ctrl = std::make_unique<Slider_output>(pp, ww, hh, "Set a");
    b_ctrl = std::make_unique<Slider_output>(p2, ww, hh, "Set b");
}

void Ellipse_controller::attach(Window& win)
{
    a_ctrl->attach(win);
    b_ctrl->attach(win);
}

void Ellipse_controller::set_a_ctrl(Callback cb, void* data)
{
    a_ctrl->set_callback(cb, data);
}

void Ellipse_controller::set_b_ctrl(Callback cb, void* data)
{
    b_ctrl->set_callback(cb, data);
}
