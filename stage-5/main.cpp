// 
// Stage 5 - Add widgets
//

#include <FL/Fl.H>
#include "./Window.h"
#include "./Shape.h"
#include "./Text.h"
#include "./Ellipse.h"
#include "./Widget.h"
#include <iostream>

void cb1(Fl_Widget*, void*)
{
    std::cout << "Button pushed!\n";
}

int main()
{
    Window win {Point{100, 100}, 600, 400, "Stage 5"};
    win.color(FL_DARK3);

    Text t1 {Point{200, 200}, "Stage 5 Complete"};
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

    Button b1 {Point{550,350}, 40, 20, "Butt", cb1};
    win.attach(b1);

    Slider s1 {Point{460,350}, 80, 20, "Slid"};
    win.attach(s1);
    s1.set_value(100);
    s1.set_bounds(50,500);

    Out_box o1 {Point{400,350}, 50, 20, "Value"};
    win.attach(o1);
    o1.put(37);

    return Fl::run();
}
