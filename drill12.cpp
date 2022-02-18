/*
    g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 1280;
    int ymax = 720;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function cos_func ( [] (double x) { return cos(x); },
						rmin, rmax, origo, n_points, xscale, yscale);

	Axis x {Axis::x, Point{20, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{200,200}, 200, 300};

	r.set_fill_color(Color::blue);
	r.set_style(Line_style(Line_style::dot, 2));

	Text t {Point{200,100}, "Hello graphics!"};
	t.set_font(Font::courier_italic);
	t.set_font_size(30);

	Image ii {Point{800,100}, "badge.jpg"};

	Circle c {Point{700,700}, 100};

	Ellipse e {Point{500,500}, 100, 50};
	e.set_fill_color(Color::magenta);

	win.attach(e);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(cos_func);
	win.attach(x);
	win.attach(y);

    win.wait_for_button();

}
