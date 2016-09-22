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


int main()
{

string f=fill();
cout << f;
}