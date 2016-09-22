#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<time.h>
#include<sstream>
using namespace std;
 
const int total_symbol = 9;
const int symbol=5;
 
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
else if(s == "000") {c -= 3*bet;}
else if(e[0] == e[1] and e[1] == e[2]) {c += p*100000;}
else if((e[0] == '1' and e[1] == '1') or (e[0] == '1' and e[2] == '1') or (e[2] == '1' and e[1] == '1')) {c += 80;}
else if((e[0] == '2' and e[1] == '2') or (e[0] == '2' and e[2] == '2') or (e[2] == '2' and e[1] == '2')) {c += 75;}
else if((e[0] == '3' and e[1] == '3') or (e[0] == '3' and e[2] == '3') or (e[2] == '3' and e[1] == '3')) {c += 65;}
else if((e[0] == '4' and e[1] == '4') or (e[0] == '4' and e[2] == '4') or (e[2] == '4' and e[1] == '4')) {c += 55;}
else if((e[0] == '0' and e[1] == '0') or (e[0] == '0' and e[2] == '0') or (e[2] == '0' and e[1] == '0')) {c -= bet;}
else if(e[0] == e[2] or e[0] == e[1] or e[1] == e[2]) {c += 50;}
else if(e[0] == '1' or e[1] == '1' or e[2] == '1') {c += 25;}
else if(e[0] == '2' or e[1] == '2' or e[2] == '2') {c += 20;}
else if(e[0] == '3' or e[1] == '3' or e[2] == '3') {c += 15;}
else if(e[0] == '4' or e[1] == '4' or e[2] == '4') {c += 10;}
else {}
 
 
return c;
}
 
int main()
{
 
int credits=0;
int bet=10;
string s="777";
credits=credit_earned (credits,bet,s);
cout << credits;
return 0;
 
}