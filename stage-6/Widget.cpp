// 
// Widget source file
// 

#include "./Widget.h"
#include <memory>
#include <sstream>          // std::stringstream (Out_box::put)
#include <math.h>           // round (Out_box::put)
#include <iostream>         // debug

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void Widget::set_callback(Callback cb, void* v)
{
    pw->callback(cb, v);
    do_it = cb;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void Button::attach(Window& win)
{
    pw = std::make_unique<Fl_Button>(loc.x, loc.y, w, h, lab.c_str());
    pw->callback(do_it);
    own = &win;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void Slider::attach(Window& win)
{
    pw = std::make_unique<Fl_Slider>(loc.x, loc.y, w, h, lab.c_str());
    pw->type(FL_HOR_NICE_SLIDER);
    pw->callback(do_it);
    own = &win;
}

void Slider::set_value(int v)
{
    auto ps = down_cast<Fl_Slider>(pw);
    ps->value(v);
}

int Slider::get_value() const
{
    auto ps = down_cast<Fl_Slider>(pw);
    return round(ps->value());
}

void Slider::set_bounds(int low, int high)
{
    auto ps = down_cast<Fl_Slider>(pw);
    ps->bounds(low, high);
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

void Out_box::attach(Window& win)
{
    pw = std::make_unique<Fl_Output>(loc.x, loc.y, w, h, lab.c_str());
    own = &win;
}

void Out_box::put(double v)
{
    auto po = down_cast<Fl_Output>(pw);
    std::stringstream ss;
    ss << round(v);
    po->value(ss.str().c_str());
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
