// 
// Stage 4 - Add shapes and functionality
//

#include <FL/Fl.H>
#include "./Window.h"
#include "./Shape.h"
#include "./Text.h"
#include "./Ellipse.h"

int main()
{
    Window win {Point{100, 100}, 600, 400, "Stage 4"};
    win.color(FL_DARK3);

    Text t1 {Point{200, 200}, "Stage 4 Complete"};
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

    return Fl::run();
}
