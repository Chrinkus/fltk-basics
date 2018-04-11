#
# FLTK makefile template
#
# Adapted from ianmacarthur's article www.fltk.org/articles.php?L599
#
# Stage 1 - single file compilation, link FLTK, display a window
#

# Define compiler
CXX = $(shell fltk-config --cxx)

# Set compiler flags
CXXFLAGS = $(shell fltk-config --cxxflags) -std=c++11 -O3

# Library link
LINKFLTK = $(shell fltk-config --ldstaticflags)

# Define what target application is called
all: Stage2

main.o: main.cpp
	$(CXX) -c $< $(CXXFLAGS)

Stage2: main.o
	$(CXX) -o $@ main.o $(LINKFLTK)

.PHONY: clean
clean:
	rm Stage2 *.o
