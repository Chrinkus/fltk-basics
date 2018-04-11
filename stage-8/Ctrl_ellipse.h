// 
// Ctrl_ellipse
//
// An ellipse that is controllable by a widget.
//

#ifndef CTRL_ELLIPSE_H
#define CTRL_ELLIPSE_H

#include "Ellipse.h"
#include "Slider_output.h"

class Ellipse_controller : public Widget {
    public:
        Ellipse_controller(Point pp, int ww, int hh, const std::string& ss);

        void attach(Window&) override;

        void set_a_ctrl(Callback cb, void* data);
        void set_b_ctrl(Callback cb, void* data);

        void set_a_bounds(int low, int high) { a_ctrl->set_bounds(low, high); }
        void set_b_bounds(int low, int high) { b_ctrl->set_bounds(low, high); }

        int get_a_value() const { return a_ctrl->get_value(); }
        int get_b_value() const { return b_ctrl->get_value(); }
    private:
        std::unique_ptr<Slider_output> a_ctrl;
        std::unique_ptr<Slider_output> b_ctrl;
};

class Ctrl_ellipse : public Ellipse {
    public:
        Ctrl_ellipse(Point pp, int aa, int bb, Ellipse_controller& ec,
                Window& win_ref);

        void change_a();        // changes 'a' and redraws ellipse
        void change_b();        // changes 'b' and redraws ellipse

    private:
        Ellipse_controller& ctrl;
        Window& win;

        static void cb_set_a(Fl_Widget*, void* data)
        {
            ((Ctrl_ellipse*)data)->change_a();
        }

        static void cb_set_b(Fl_Widget*, void* data)
        {
            ((Ctrl_ellipse*)data)->change_b();
        }
};

#endif  /* CTRL_ELLIPSE_H */
