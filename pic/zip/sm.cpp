

#include <iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<sstream>
#include<iomanip>
#include<fl/fl.h>
#include<fl/fl_window.h>
#include<fl/fl_button.h>
#include<fl/fl_output.h>
#include<fl/fl_jpeg_image.h>
#include<fl/fl_box.h>
using namespace std;


const int total_symbol = 9;
const int symbol=3;
const int width = 640;
const int height = 480;


struct Widgets
{
Fl_Output* out;
Fl_Output* credits;
Fl_Output* credit_earned;
Fl_Output* bet;
Fl_Box* box1;
Fl_Box* box2;
Fl_Box* box3;
Fl_JPEG_Image* img[12];
int main_bet;
int credit;
};




string fill ()
{
 int f;
 ostringstream ostr;	  
 
 f=rand()%1000;
 ostr << setw(3) << setfill('0') << f;
 string sequence=ostr.str();
 
 return sequence;
}



int select_image(char e)
{
int d;
     if (e == '0') {d=0;return d;}
else if (e == '1') {d=1;return d;}
else if (e == '2') {d=2;return d;}
else if (e == '3') {d=3;return d;}
else if (e == '4') {d=4;return d;}
else if (e == '5') {d=5;return d;}
else if (e == '6') {d=6;return d;}
else if (e == '7') {d=7;return d;}
else if (e == '8') {d=8;return d;}
else               {d=9;return d;}

}

void out_image(void* v, string s)
{
Widgets* w = static_cast<Widgets*>(v);

int a=select_image(s[0]);
int b=select_image(s[1]);
int c=select_image(s[2]);
w->box1->image(w->img[a]);
w->box1->redraw();
w->box2->image(w->img[b]);
w->box2->redraw();
w->box3->image(w->img[c]);
w->box3->redraw();
cout << "M here in image";

w->box1->parent()->redraw();
w->box2->parent()->redraw();
w->box3->parent()->redraw();

}

int credit_earned(int c, int bet, string s)
{
char e[4];
double p;
strcpy(e,s.c_str());
 
s=s.c_str();

if (bet==5){p=0.25;}
else if (bet==10){p=0.50;}
else if (bet==25){p=0.75;}
else if (bet==50){p=1;}
 
if(s == "111") {c += p*100000000;}
else if(s == "222") {c += p*10000000;}
else if(s == "333") {c += p*5000000;}
else if(s == "444") {c += p*1000000;}
else if(s == "000") {c /= 3;}
else if(e[0] == e[1] and e[1] == e[2]) {c += p*100000;}
else if((e[0] == '1' and e[1] == '1') or (e[0] == '1' and e[2] == '1') or (e[2] == '1' and e[1] == '1')) {c += 100;}
else if((e[0] == '2' and e[1] == '2') or (e[0] == '2' and e[2] == '2') or (e[2] == '2' and e[1] == '2')) {c += 80;}
else if((e[0] == '3' and e[1] == '3') or (e[0] == '3' and e[2] == '3') or (e[2] == '3' and e[1] == '3')) {c += 75;}
else if((e[0] == '4' and e[1] == '4') or (e[0] == '4' and e[2] == '4') or (e[2] == '4' and e[1] == '4')) {c += 50;}
else if((e[0] == '0' and e[1] == '0') or (e[0] == '0' and e[2] == '0') or (e[2] == '0' and e[1] == '0')) {c -= bet;}
else if(e[0] == e[2] or e[0] == e[1] or e[1] == e[2]) {c += 45;}
else if(e[0] == '1' or e[1] == '1' or e[2] == '1') {c += 25;}
else if(e[0] == '2' or e[1] == '2' or e[2] == '2') {c += 20;}
else if(e[0] == '3' or e[1] == '3' or e[2] == '3') {c += 15;}
else if(e[0] == '4' or e[1] == '4' or e[2] == '4') {c += 10;}
else {}
 	
 
return c;
}
 

void bet_update_1(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->main_bet=5;
 ostringstream ostr;	  
 ostr << w->main_bet;
 
w->bet->value(ostr.str().c_str());
}


void bet_update_2(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->main_bet=10;
 ostringstream ostr;	  
 ostr << w->main_bet;

w->bet->value(ostr.str().c_str());

}


void bet_update_3(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->main_bet=20;
 ostringstream ostr;	  
 ostr << w->main_bet;
 
w->bet->value(ostr.str().c_str());
}


void bet_update_max(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->main_bet=50;
 ostringstream ostr;	  
 ostr << w->main_bet;
 
w->bet->value(ostr.str().c_str());
}



void bet_update_reset(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->main_bet=0;
 ostringstream ostr;	  
 ostr << w->main_bet;
 
w->bet->value(ostr.str().c_str());
}




void bet_again(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->credit_earned->value("");

o->parent()->child(7)->show();
o->parent()->child(8)->hide();


}





void spin(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);

if(w->credit < 50)
{
	for(int i=0;i<14;i++)
	{
	o->parent()->child(i)->hide();
	}
	
	o->parent()->child(4)->show();
	w->box2->image(w->img[11]);
	w->box2->redraw();
}

else
{
double difference;

cout << "M here in spin";
string sequence;
sequence=fill();
out_image(v,sequence);
w->credit=w->credit-w->main_bet;
double creditearned=w->credit;
w->credit=credit_earned(w->credit,w->main_bet,sequence);
difference=fabs(w->credit-creditearned);

 ostringstream ostr;	  
 ostr << difference;
 
 ostringstream ostr1;	  
 ostr1 << w->credit;


w->credit_earned->value(ostr.str().c_str());
w->credits->value(ostr1.str().c_str());

o->parent()->child(8)->show();
o->parent()->child(7)->hide();
}

}





void withdraw(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
for(int i=0;i<14;i++)
{
o->parent()->child(i)->hide();
}

o->parent()->child(5)->show();
w->box3->image(w->img[10]);
w->box3->redraw();
}





int main()
{

 srand(time(0));
cout << "M here1";

Fl_Window* w = new Fl_Window(width,height);
cout << "M here2";

Widgets widgets;
widgets.credit=200;
widgets.main_bet=0;

w->begin();
cout << "M here3";
widgets.credits = new Fl_Output(100,75,150,30,"CREDITS:");
	ostringstream ostr;	     
 	ostr << widgets.credit;
	widgets.credits->value(ostr.str().c_str());
widgets.bet = new Fl_Output(35,350,100,25,"Bet");
widgets.credit_earned = new Fl_Output(250,350,200,25,"Credits Earned");cout << "M here4";

widgets.img[0] = new Fl_JPEG_Image("f0.jpg");
widgets.img[1] = new Fl_JPEG_Image("f1.jpg");
widgets.img[2] = new Fl_JPEG_Image("f2.jpg");
widgets.img[3] = new Fl_JPEG_Image("f3.jpg");
widgets.img[4] = new Fl_JPEG_Image("f4.jpg");
widgets.img[5] = new Fl_JPEG_Image("f5.jpg");
widgets.img[6] = new Fl_JPEG_Image("f6.jpg");
widgets.img[7] = new Fl_JPEG_Image("f7.jpg");
widgets.img[8] = new Fl_JPEG_Image("f8.jpg");
widgets.img[9] = new Fl_JPEG_Image("f9.jpg");
widgets.img[10] = new Fl_JPEG_Image("tfp.jpg");
widgets.img[11] = new Fl_JPEG_Image("roc.jpg");

widgets.box1 = new Fl_Box(5,125,150,200);cout << "M here5";
widgets.box2 = new Fl_Box(158,125,150,200);cout << "M here5";
widgets.box3 = new Fl_Box(311,125,150,200);cout << "M here5";

Fl_Button* button_withdraw = new Fl_Button(480,450,160,30,"Withdraw");
Fl_Button* button_spin = new Fl_Button(470,350,130,30,"Spin");
Fl_Button* button_bet_again = new Fl_Button(470,300,130,30,"Bet Again");
Fl_Button* button1 = new Fl_Button(170,400,100,30,"5 Credits");
Fl_Button* button2 = new Fl_Button(270,400,100,30,"10 Credits");
Fl_Button* button3 = new Fl_Button(370,400,100,30,"20 Credits");
Fl_Button* buttonreset = new Fl_Button(50,400,100,30,"Reset");
Fl_Button* buttonmax = new Fl_Button(490,400,100,30,"Bet Max");

w->end();

cout << "M here6";

button1->callback(bet_update_1,&widgets);
button2->callback(bet_update_2,&widgets);
button3->callback(bet_update_3,&widgets);
buttonmax->callback(bet_update_max,&widgets);
buttonreset->callback(bet_update_reset,&widgets);
button_bet_again->callback(bet_again,&widgets);
button_spin->callback(spin,&widgets);
button_withdraw->callback(withdraw,&widgets);
cout << "M here7";

w->show();
cout << "M here";

return(Fl::run());
}
 


