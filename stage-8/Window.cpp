// 
// Window source file
//

#include "./Window.h"
#include "./Shape.h"
#include "./Widget.h"

Window::Window(Point tl, int ww, int hh, const std::string& s)
    : Fl_Double_Window{ tl.x, tl.y, ww, hh, s.c_str() }
{
    show();
}

void Window::attach(Shape& s)
{
    shapes.push_back(&s);
}

void Window::attach(Widget& w)
{
    begin();
    w.attach(*this);
    end();
}

void Window::draw()
{
    Fl_Double_Window::draw();
    for (const auto& s : shapes)
        s->draw();
}
