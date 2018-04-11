// 
// Window header
//

#ifndef WINDOW_H
#define WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <string>
#include <vector>
#include "./Point.h"

class Shape;

class Window : public Fl_Double_Window {
    public:
        Window(Point tl, int ww, int hh, const std::string& ss);

        void attach(Shape& s);
        void draw();
    private:
        std::vector<Shape*> shapes;
};

#endif  /* WINDOW_H */
