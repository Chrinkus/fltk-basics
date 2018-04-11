// 
// Slider_output
//
// This is a combination widget that is used to output the current value of
// a slider. An external callback may be hooked into the output box to receive
// data when its value changes.
//

#ifndef SLIDER_OUTPUT_H
#define SLIDER_OUTPUT_H

#include "Widget.h"

class Slider_output : public Widget {
    public:
        Slider_output(Point p, int w, int h, const std::string& s);

        void attach(Window&) override;
        void set_callback(Callback, void*) override;

        void set_value(int v) { ps->set_value(v); po->put(v); }
        void set_bounds(int lo, int hi) { ps->set_bounds(lo, hi); }
    private:
        std::unique_ptr<Slider> ps;
        std::unique_ptr<Out_box> po;

        void set_out() { po->put(ps->get_value()); }

        static void cb_set_out(Fl_Widget*, void* data)
        {
            ((Slider_output*)data)->set_out();
        }
};

#endif
