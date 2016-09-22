#include<iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<sstream>
using namespace std;

const int total_symbol = 9;
const int symbol=5;


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



int main()
{

string s="56789";
out_image(s);
}