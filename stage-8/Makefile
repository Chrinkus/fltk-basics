#
# FLTK makefile template
#
# Adapted from ianmacarthur's article www.fltk.org/articles.php?L599
#
# Stage 8 - Controlling Shapes with Widgets
#

# Define compiler
CXX = $(shell fltk-config --cxx)

# Set compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -std=c++14 -O3

# Library link
LINKFLTK = $(shell fltk-config --ldstaticflags)

# Define what target application is called
all: Stage8

# Define how to build the various object files
main.o: main.cpp Window.h Text.h Shape.h Widget.h Slider_output.h Ctrl_ellipse.h
	$(CXX) -c $< $(CXXFLAGS)
Shape.o: Shape.cpp Shape.h Point.h
	$(CXX) -c $< $(CXXFLAGS)
Window.o: Window.cpp Window.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)
Text.o: Text.cpp Text.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)
Ellipse.o: Ellipse.cpp Ellipse.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)
Widget.o: Widget.cpp Widget.h
	$(CXX) -c $< $(CXXFLAGS)
Slider_output.o: Slider_output.cpp Slider_output.h Widget.h
	$(CXX) -c $< $(CXXFLAGS)
Ctrl_ellipse.o: Ctrl_ellipse.cpp Ctrl_ellipse.h
	$(CXX) -c $< $(CXXFLAGS)

# Define how to link the final app
Stage8: main.o Shape.o Window.o Text.o Ellipse.o Widget.o Slider_output.o Ctrl_ellipse.o
	$(CXX) -o $@ main.o Shape.o Window.o Text.o Ellipse.o Widget.o Slider_output.o Ctrl_ellipse.o $(LINKFLTK)

.PHONY: clean
clean:
	rm Stage8 *.o
