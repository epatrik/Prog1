/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

int main(){

    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    int x_size = 800;
    int y_size = 800;

    int x_grid = 100;
    int y_grid = 100;

    Lines grid;

    for (int x=x_grid; x<=x_size; x+=x_grid)
    grid.add(Point{x,0},Point{x,y_size});

    for (int y = y_grid; y<=y_size; y+=y_grid)
    grid.add(Point{0,y},Point{x_size,y});

    Rectangle r {Point{0,0}, 100, 100};
    r.set_fill_color(Color::red);
    win.attach(r);
    Rectangle r1 {Point{100,100}, 100, 100};
    r1.set_fill_color(Color::red);
    win.attach(r1);
    Rectangle r2 {Point{200,200}, 100, 100};
    r2.set_fill_color(Color::red);
    win.attach(r2);
    Rectangle r3 {Point{300,300}, 100, 100};
    r3.set_fill_color(Color::red);
    win.attach(r3);
    Rectangle r4 {Point{400,400}, 100, 100};
    r4.set_fill_color(Color::red);
    win.attach(r4);
    Rectangle r5 {Point{500,500}, 100, 100};
    r5.set_fill_color(Color::red);
    win.attach(r5);
    Rectangle r6 {Point{600,600}, 100, 100};
    r6.set_fill_color(Color::red);
    win.attach(r6);
    Rectangle r7 {Point{700,700}, 100, 100};
    r7.set_fill_color(Color::red);
    win.attach(r7);

    Image i {Point{600,100},"badge.jpg"};
    i.set_mask(Point{100,100},200,200);
    win.attach(i);
    Image i1 {Point{0,200},"badge.jpg"};
    i1.set_mask(Point{100,100},200,200);
    win.attach(i1);
    Image i2 {Point{300,500},"badge.jpg"};
    i2.set_mask(Point{100,100},200,200);
    win.attach(i2);
    
    win.attach(grid);

    
    while (true)
    {
        int random1 = rand() %8;
        int random2 = rand() %8;

        Image i3 {Point{random1*100,random2*100},"badge.jpg"};
        i3.set_mask(Point{200,200},100,100);
        i3.set_fill_color(Color::black);
        win.attach(i3);


        win.wait_for_button();
    }
}