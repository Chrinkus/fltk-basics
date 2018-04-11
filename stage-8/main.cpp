// 
// Stage 8 - Controlling Shapes with Widgets
//

#include <FL/Fl.H>
#include "Window.h"
#include "Shape.h"
#include "Text.h"
#include "Ellipse.h"
#include "Widget.h"
#include "Slider_output.h"
#include "Ctrl_ellipse.h"
#include <iostream>

void print_slider_value(Fl_Widget*, void* v)
{
    auto ps = (Slider*)v;
    std::cout << ps->get_value() << '\n';
}

void print_out_value(Fl_Widget*, void* data)
{
    std::cout << ((Slider_output*)data)->get_value() << '\n';
}

void out_cb(Fl_Widget* pw, void* v)
{
    Fl_Slider* ps = (Fl_Slider*)pw;     // pw is actually an Fl_Slider*
    Out_box* po = (Out_box*)v;          // void* is an Out_box
    po->put(ps->value());
}

int main()
{
    Window win {Point{100, 100}, 600, 400, "Stage 8"};
    win.color(FL_DARK3);

    Text t1 {Point{200, 200}, "Stage 8 Complete"};
    t1.set_line_color(215);
    t1.set_font(FL_HELVETICA);
    t1.set_size(24);
    win.attach(t1);

    Line l1 {Point{100, 300}, Point{500, 300}};
    l1.set_line_color(FL_RED);
    win.attach(l1);

    Line l2 {Point{100, 100}, Point{500, 100}};
    l2.set_line_color(FL_BLUE);
    win.attach(l2);

    Ellipse e1 {Point{300, 200}, 200, 90};
    e1.set_line_color(FL_YELLOW);
    win.attach(e1);

    Button b1 {Point{550,350}, 40, 20, "Butt"};
    win.attach(b1);

    Slider s1 {Point{460,350}, 80, 20, "Slid"};
    win.attach(s1);
    s1.set_value(100);
    s1.set_bounds(50,500);

    Out_box o1 {Point{400,350}, 50, 20, "Value"};
    win.attach(o1);
    o1.put(s1.get_value());

    s1.set_callback(&out_cb, &o1);
    b1.set_callback(&print_slider_value, &s1);

    Slider_output so1 {Point{50, 50}, 210, 20, "Slideout"};
    win.attach(so1);
    so1.set_callback(&print_out_value, &so1);

    Slider_output so2 {Point{50, 25}, 210, 20, "Another!"};
    win.attach(so2);
    so2.set_bounds(100, 1000);
    so2.set_value(200);
    so2.set_callback(&print_out_value, &so2);

    Ellipse_controller ec1 {Point{350, 25}, 210, 20, ""};
    win.attach(ec1);
    ec1.set_a_bounds(20, 300);
    ec1.set_b_bounds(20, 200);
    Ctrl_ellipse ce1 {Point{300, 200}, 50, 50, ec1, win};
    ce1.set_line_color(FL_MAGENTA);
    win.attach(ce1);

    return Fl::run();
}
