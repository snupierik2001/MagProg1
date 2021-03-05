#include "./Simple_window.h"
#include "./Graph.h"

#include <string>
#include <iostream>

/* Fordítás
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ch12_drill.cpp `fltk-config --ldflags --use-images` -o a.out
*/

using namespace Graph_lib;

int main()
try {
    // 1. empty Simple_window
    Point tl {100, 100};        // bal fentről indulva.
    Simple_window win {tl, 600, 400, "My window"};
        // ablak méret 600*400)
        // cím: My window 
    win.wait_for_button(); 



    // 2. add more examples
    // 12.7.3 Axis
    Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};   // tengely készítése
    


    win.attach(xa);                 // Képernyőre "ragasztás."
    win.set_label("My window 2");  
    win.wait_for_button();          

    Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
    	ya.set_color(Color::cyan);              // szín választás
    	ya.label.set_color(Color::dark_red);    // Betűnek szín



    win.attach(ya);
    win.set_label("My window 3");
    win.wait_for_button();                 



    // 12.7.4 Graphing a function
    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};

    win.attach(sine);
    win.set_label("My window 4");
    win.wait_for_button();
    


    // 12.7.5 Polygons
    sine.set_color(Color::blue);   

    Polygon poly;                   // polygon az egy shape
    poly.add(Point{300, 200});      // 3 pont a 3 szöghöz
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);



    win.attach(poly);
    win.set_label("My window 5");
    win.wait_for_button();



    // 12.7.6 Rectangles
    Rectangle r {Point{200, 200}, 100, 50}; 
    win.attach(r);

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});



    win.attach(poly_rect);

    win.set_label("My window 6");
    win.wait_for_button();




    // 12.7.7 Fill
    r.set_fill_color(Color::yellow);    
    poly.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    poly_rect.set_fill_color(Color::green);
    win.set_label("My window 7");
    win.wait_for_button();




    // 12.7.8 Text
    Text t {Point{150, 150}, "Hello, graphical world!"};
    win.attach(t);
    win.set_label("My window 8");
    win.wait_for_button();

    t.set_font(Font::times_bold);
    t.set_font_size(20);
    win.set_label("My window 9");
    win.wait_for_button();




    // 12.7.9 Images
    Image ii {Point{100, 50}, "./badge.jpg"};
    win.attach(ii);
    win.set_label("My window 10");
    win.wait_for_button();
    

    ii.move(100, 200);
    win.set_label("My window 11");
    win.wait_for_button();

}
catch(exception& e) {
    cerr << "exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    cerr << "error\n";
    return 2;
}

