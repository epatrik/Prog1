/*
    g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) { return cos(x)+slope(x); }

int main(){

    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -10;
    int rmax = 11;

    int n_points = 400;

    Simple_window win{Point{100,100},xmax,ymax,"Function Graph"};

    Point origo {x_orig, y_orig};

	int xlength = 400;
	int ylength = 400;

	int xscale = 20, yscale = 20;

    Axis x {Axis::x, Point{100, y_orig}, xlength, 20, "1 = = 20 pixels"};
	Axis y {Axis::y, Point{x_orig, ylength + 100},ylength, 20, "1 = = 20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);

    Function s (one, rmin, rmax, origo, n_points, xscale, yscale);
    Function q (slope, rmin, rmax, origo, n_points, xscale, yscale);
    Function r (square, rmin, rmax, origo, n_points, xscale, yscale);
    Function cos_func ( [] (double x) { return cos(x); }, rmin, rmax, origo, n_points, xscale, yscale);
    cos_func.set_color(Color::blue);
    Function c (sloping_cos, rmin, rmax, origo, n_points, xscale, yscale);

    Text t {Point{100,380}, "x/2"};

    win.attach(r);
    win.attach(q);
    win.attach(s);
    win.attach(x);
    win.attach(y);
    win.attach(t);
    win.attach(cos_func);
    win.attach(c);
    win.wait_for_button();

}