// 
// Stage 2 - Begin the abstract interface
//

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <string>
#include <vector>

struct Point {
    int x, y;
};

class Shape {
    public:
        Shape(Point xy) : loc{xy} { }

        virtual void draw() const { }

        void set_line_color(int c) { line_color = c; }
        int get_line_color() const { return line_color; }
    protected:
        Point loc;
    private:
        int line_color;
};

class Text : public Shape {
    public:
        Text(Point xy, const std::string& s)
            : Shape{xy}, content{s} { }

        void draw() const
        {
            fl_font(font, size);
            fl_color(get_line_color());
            fl_draw(content.c_str(), loc.x, loc.y);
        }
    private:
        int font { FL_HELVETICA_BOLD };
        int size { 24 };
        std::string content;
};

class My_Window : public Fl_Double_Window {
    public:
        My_Window(Point tl, int ww, int hh, const std::string& label)
            : Fl_Double_Window{ tl.x, tl.y, ww, hh, label.c_str() }
        {
            show();
        }

        void attach(Shape& s)
        {
            shapes.push_back(&s);
        }

        void draw()
        {
            Fl_Double_Window::draw();
            for (const auto& s : shapes)
                s->draw();
        }

    private:
        std::vector<Shape*> shapes;
};

int main()
{
    My_Window win {Point{100, 100}, 600, 400, "Stage 2"};
    win.color(FL_DARK3);

    Text text {Point{200, 200}, "Stage 2 Complete"};
    text.set_line_color(215);
    win.attach(text);

    return Fl::run();
}
