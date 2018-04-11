// 
// Text Header
//

#ifndef TEXT_H
#define TEXT_H

#include <FL/Fl.H>
#include <string>
#include "./Shape.h"
#include "./Point.h"

class Text : public Shape {
    public:
        Text(Point xy, const std::string& s)
            : Shape{xy}, content{s} { }

        void draw() const;

        void set_font(int f) { font = f; }
        int get_font() const { return font; }

        void set_size(int s) { size = s; }
        int get_size() const { return size; }

    private:
        int font;
        int size;
        std::string content;
};

#endif  /* TEXT_H */
