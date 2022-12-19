#include <iostream>
#include <string>
#include "postfix.h"
#include <math.h>
#include <stdlib.h>
using namespace std;
void f(string st) {
	TPostfix Post(st);
	cout << Post.GetInfix() << endl;
	Post.ToPostfix();
	cout << Post.GetPostfix() << endl;
	cout << Post.Calculate() << endl;
}


int main()
{
 
  TPostfix postfix;

  string h = "5*6+(2-9)";
  f(h);
  string p = "6+3*{-4}";
  f(p);
  h = "1/(1/2)";
  f(h);
  h = "16*7-52+3.1*9.12";
  f(h);

  
      p = "5*6+(2-9)";
      TPostfix a(p);
      double b = 23;
	  a.ToPostfix();
	  if (a.Calculate() == 23) {
		  cout << "=" << endl;
	  }
	  
      
  

  }


