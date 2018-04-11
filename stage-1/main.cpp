// 
// Stage 1 - utilize FLTK to draw a window and populate it with some text
//

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main()
{
    Fl_Window* window = new Fl_Window{100, 100, 600, 400, "Window Test"};

    Fl_Box* box = new Fl_Box{100, 50, 400, 100, "Stage 1 Complete"};
    box->box(FL_NO_BOX);
    box->labelfont(FL_HELVETICA);
    box->labelsize(24);
    box->labelcolor(FL_LIGHT2);

    window->end();
    window->color(FL_DARK3);
    window->show();
    return Fl::run();
}
