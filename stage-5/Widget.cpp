// 
// Widget source file
// 

#include "./Widget.h"
#include <memory>
#include <sstream>
#include <iostream>

void Button::attach(Window& win)
{
    pw = std::make_unique<Fl_Button>(loc.x, loc.y, w, h, lab.c_str());
    pw->callback(do_it);
    own = &win;
}

void Slider::attach(Window& win)
{
    pw = std::make_unique<Fl_Slider>(loc.x, loc.y, w, h, lab.c_str());
    pw->type(FL_HOR_NICE_SLIDER);
    own = &win;
}

void Out_box::attach(Window& win)
{
    pw = std::make_unique<Fl_Output>(loc.x, loc.y, w, h, lab.c_str());
    own = &win;
}

void Out_box::put(int v)
{
    std::stringstream ss;
    ss << v;
    pw->value(ss.str().c_str());
}
