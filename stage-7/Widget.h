// 
// Widget header
//
// This is an abstract class for creating different widget types.
//
// Initially I'm copying pretty much line for line from Bjarne Stroustrup's
// GUI library until I understand better how Callbacks work.
//
// A widget must be created AND attached before any of its members may be set.
// This is not quite the "pit of success" but its enough for now.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <string>
#include "./Point.h"
#include "./Window.h"
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Output.H>

// FLTK's required function type for callbacks
using Callback = void(*)(Fl_Widget*, void*);

template<typename W> W* down_cast(const std::unique_ptr<Fl_Widget>& pw)
{
    return dynamic_cast<W*>(pw.get());
}

class Widget {
    public:
        Widget(Point xy, int ww, int hh, const std::string& s, Callback cb = 0)
            : loc{xy}, w{ww}, h{hh}, lab{s}, do_it{cb} { }

        virtual void attach(Window&) = 0;

        virtual void set_callback(Callback, void*);

        virtual ~Widget() { }
    protected:
        Point loc;          // x,y location
        int w, h;           // width and height
        std::string lab;    // widget label content
        Callback do_it;     // PPP name preserved for fun
        Window* own;        // the window that the widget belongs to
        std::unique_ptr<Fl_Widget> pw;
};

struct Button : Widget {
    Button(Point xy, int ww, int hh, const std::string& s, Callback cb = 0)
        : Widget{xy, ww, hh, s, cb} { }

    void attach(Window&) override;
};

struct Slider : Widget {
    Slider(Point xy, int ww, int hh, const std::string& s, Callback cb = 0)
        : Widget{xy, ww, hh, s, cb} { }

    void attach(Window&) override;

    void set_value(int val);
    int get_value() const;
    void set_bounds(int low, int high);
};

struct Out_box : Widget {
    Out_box(Point xy, int ww, int hh, const std::string& s, Callback cb = 0)
        : Widget{xy, ww, hh, s, cb} { }

    void attach(Window&) override;

    void put(double);
};

#endif
