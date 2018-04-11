#
# FLTK makefile template
#
# Adapted from ianmacarthur's article www.fltk.org/articles.php?L599
#
# Stage 4 - Adding shapes and functionality
#

# Define compiler
CXX = $(shell fltk-config --cxx)

# Set compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -std=c++11 -O3

# Library link
LINKFLTK = $(shell fltk-config --ldstaticflags)

# Define what target application is called
all: Stage4

# Define how to build the various object files
main.o: main.cpp Window.h Text.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)
Shape.o: Shape.cpp Shape.h Point.h
	$(CXX) -c $< $(CXXFLAGS)
Window.o: Window.cpp Window.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)
Text.o: Text.cpp Text.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)
Ellipse.o: Ellipse.cpp Ellipse.h Shape.h
	$(CXX) -c $< $(CXXFLAGS)

# Define how to link the final app
Stage4: main.o Shape.o Window.o Text.o Ellipse.o
	$(CXX) -o $@ main.o Shape.o Window.o Text.o Ellipse.o $(LINKFLTK)

.PHONY: clean
clean:
	rm Stage4 *.o
