// 
// Stage 3 - Break out components into headers and source files
//

#include <FL/Fl.H>
#include "./Window.h"
#include "./Text.h"

int main()
{
    Window win {Point{100, 100}, 600, 400, "Stage 3"};
    win.color(FL_DARK3);

    Text text {Point{200, 200}, "Stage 3 Complete"};
    text.set_line_color(215);
    text.set_font(FL_HELVETICA);
    text.set_size(24);
    win.attach(text);

    return Fl::run();
}
