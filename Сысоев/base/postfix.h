#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include "stack.h"
#include <math.h>
#include <stdlib.h>
using namespace std;

class TPostfix
{
 
  string infix;
  string postfix;
public:
  TPostfix()
  {
    infix = "a + b";
  }
  TPostfix(const char* b) {
      infix = b;
  
  }
  TPostfix(string st) {
      infix = st;
  }
  string GetInfix() { return infix; }
  string GetPostfix() { return postfix; }
  string ToPostfix();
  double Calculate(); // Ввод переменных, вычисление по постфиксной форме
};

#endif
