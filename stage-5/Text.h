// 
// Text Header
//

#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "./Shape.h"

class Text : public Shape {
    public:
        Text(Point p, const std::string& s);

        void draw() const override;

        void set_font(int f) { font = f; }
        int get_font() const { return font; }

        void set_size(int s) { size = s; }
        int get_size() const { return size; }

    private:
        int font { 0 };
        int size { 0 };
        std::string content;
};

#endif
