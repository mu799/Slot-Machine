#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<sstream>
#include<iomanip>
using namespace std;

const int total_symbol = 9;
const int symbol=3;

string fill ()
{
 int f;
 ostringstream ostr;	  
 srand((unsigned)time(0)); 
 f=rand()%1000;
 ostr << setw(3) << setfill('0') << f;
 string sequence=ostr.str();
 
 return sequence;
}



void select_image(char e)
{

     if (e == '0') {cout << "f0 ";}
else if (e == '1') {cout << "f1 ";}
else if (e == '2') {cout << "f2 ";}
else if (e == '3') {cout << "f3 ";}
else if (e == '4') {cout << "f4 ";}
else if (e == '5') {cout << "f5 ";}
else if (e == '6') {cout << "f6 ";}
else if (e == '7') {cout << "f7 ";}
else if (e == '8') {cout << "f8 ";}
else               {cout << "f9 ";}

}

void out_image( string s)
{
for (int i=0; i< symbol; i++)
{
select_image(s[i]);
}
}

int credit_earned (int c, int bet, string s)
{
char e[4];
double p;
strcpy(e,s.c_str());
 
s=s.c_str();

if (bet==5){p=0.25}
else if (bet==10){p=0.50}
else if (bet==25){p=0.75}
else if (bet==50){p=1}

 
if      (e[1] == e[2] && e[0] == e[1]) {c +=p*;}
else if (e[1] == e[2] ) {c +=P*;}
else if (e[0] == e[1] ) {c +=p*1000;}
else if (e[0] == e[2] ) {c +=p*1000;}
else if (s=="01234") {c +=7000;}
else if (s=="12345") {c +=7000;}
else if (s=="23456") {c +=7000;}
else if (s=="34567") {c +=7000;}
else if (s=="45678") {c +=7000;}
else if (s=="56789") {c +=7000;}
else if (s=="0") {c +=0;}
else if (s=="1") {c +=0;}
else           {c +=10000;}
 
 
return c;
}
 
 