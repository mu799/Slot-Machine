

#include <iostream>
#include <sstream>
using namespace std;
#include<fl/fl.h>
#include<fl/fl_window.h>
#include<fl/fl_button.h>
#include<fl/fl_input.h>
#include<fl/fl_output.h>
#include<fl/fl_box.h>
#include<fl/fl_jpeg_image.h>



const int width = 640;
const int height = 480;
struct Widgets
{
Fl_Box* box;
Fl_JPEG_Image* img[3];
};



void button_clicked(Fl_Widget* o, void* v)
{
static int counter = 0;
Widgets* w = static_cast<Widgets*>(v);
w->box->image(w->img[counter%3]);
w->box->position(w->box->x()+5,w->box->y()-5);
w->box->parent()->redraw();
counter++;
}

int main()
{


Fl_Window* w = new Fl_Window(width,height);


Widgets widgets;
w->begin();
widgets.img[0] = new Fl_JPEG_Image("f1.jpg");
widgets.img[1] = new Fl_JPEG_Image("f2.jpg");
widgets.img[2] = new Fl_JPEG_Image("f3.jpg");
widgets.box = new Fl_Box(100,100,100,100);
Fl_Button* button = new Fl_Button(300,400,50,30,"CHANGE");
w->end();


button->callback(button_clicked,&widgets);


w->show();

return(Fl::run());
 
}
