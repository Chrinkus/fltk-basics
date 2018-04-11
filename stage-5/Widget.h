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

class Widget {
    public:
        Widget(Point xy, int ww, int hh, const std::string& s, Callback cb)
            : loc{xy}, w{ww}, h{hh}, lab{s}, do_it{cb} { }

        virtual void attach(Window&) = 0;

        virtual ~Widget() { }
    protected:
        Point loc;          // x,y location
        int w, h;           // width and height
        std::string lab;    // widget label content
        Callback do_it;
        Window* own;        // the window that the widget belongs to
};

class Button : public Widget {
    public:
        Button(Point xy, int ww, int hh, const std::string& s, Callback cb)
            : Widget{xy, ww, hh, s, cb} { }

        void attach(Window&) override;
    private:
        std::unique_ptr<Fl_Button> pw;
};

class Slider : public Widget {
    public:
        Slider(Point xy, int ww, int hh, const std::string& s)
            : Widget{xy, ww, hh, s, 0} { }

        void attach(Window&) override;

        void set_value(int v) { pw->value(v); }
        int get_value() const { return pw->value(); }
        void set_bounds(int low, int high) { pw->bounds(low, high); }
    private:
        std::unique_ptr<Fl_Slider> pw;
};

class Out_box : public Widget {
    public:
        Out_box(Point xy, int ww, int hh, const std::string& s)
            : Widget{xy, ww, hh, s, 0} { }

        void attach(Window&) override;

        void put(int);
    private:
        std::unique_ptr<Fl_Output> pw;
};

#endif
