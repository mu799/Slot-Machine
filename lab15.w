\documentclass{article}
\usepackage{hyperref}
\usepackage{graphicx}
% Setup to make nuWEB use hyperref features
\renewcommand{\NWtarget}[2]{\hypertarget{#1}{#2}}
\renewcommand{\NWlink}[2]{\hyperlink{#1}{#2}}
\title{FLTK GUI Lab}
\author{Soham}
\begin{document}
\maketitle


\section{Specification}
FLTK GUI lab

This lab shows how to create a basic GUI program using FLTK that has input
and output.

To illustrate the method, we will create an input textbox where the user can
enter data, then display that same data in an output box.



\section{Analysis/Design}

Need to use FLTK library for the GUI



\begin{itemize}
\item Creat main window to hold the controls
\item Create Widgets for input and output and button
\item Register a callback function to be called when button is pressed
\item Show window with its controls
\item When button is pressed, increase value by 10%, then copy input to output
\end{itemize}
\section{Implementation}



@o lab15.cpp
@{
@<Include files@>
@<Constants@>
@<Function callback@>
int main()
{

@<Create main window@>
@<Create Widgets for input and output and button@>
@<Register a callback function to be called when button is pressed@>
@<Show window with its controls@>
return(Fl::run());
 
}
@}
% Definitons of functions go here; each in their own macro

@d Create main...
@{
Fl_Window* w = new Fl_Window(width,height);
@}


Need to pass in XY coordinate (upper left corner) of box, and width, height, and label.
@d Create Widgets...
@{
Widgets widgets;
w->begin();

Fl_Button* button1 = new Fl_Button(300,400,50,30,"5 Credits");
Fl_Button* button2 = new Fl_Button(350,400,50,30,"10 Credits");
Fl_Button* button3 = new Fl_Button(400,400,50,30,"20 Credits");
w->end();
@}


@d Register...
@{
button->callback(button_clicked,&widgets);
@}




@d Show window with its controls
@{
w->show();
@}


These are the declarations of functions called in this program
@d Function callback
@{
void button_clicked(Fl_Widget* o, void* v)
{
Widgets* w = static_cast<Widgets*>(v);
w->out->value( w->in->value() );
}
@}

These are the include files needed for library function calls
@d Include files
@{
#include <iostream>
using namespace std;
#include<fl/fl.h>
#include<fl/fl_window.h>
#include<fl/fl_button.h>
#include<fl/fl_input.h>
#include<fl/fl_output.h>
@}

These are the values that will not change during program execution
@d Constants
@{

const int width = 640;
const int height = 480;
struct Widgets
{
Fl_Input* in;
Fl_Output* out;
};

@}
\section{Test}
%\includegraphics[scale=0.5]{lab.jpg}
\end{document}
