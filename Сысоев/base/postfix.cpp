#include "postfix.h"
#include "stack.h"
#include <math.h>
#include <stdlib.h>
using namespace std;
double clc(string st, double first, double second) {
	if (st == "+") {
		return first + second;
	}
	if (st == "-") {
		return first - second;
	}
	if (st == "*") {
		return first * second;
	}
	if (st == "/") {
		return first / second;
	}

};

int preor(string st) {
	if ((st == "+") || (st == "-")) {
		return 1;
	}
	if ((st == "*") || (st == "/")) {
		return 2;
	}
	if ((st == "sin") || (st == "cos") || (st == "ctg") || (st == "tg")) {
		return 3;
	}
	if (st == "(") {
		return -1;
	}

};
bool trig(string st) {
	if ((st == "sin") || (st == "cos") || (st == "ctg") || (st == "tg")) {
		return true;
	}
	else {
		return false;
	}
};

bool comparison(TSteck<string> st, string cr ) {
	if (preor(st.check()) < preor(cr)) {
		return true;
	}
	else {
		return false;
	}

};

string TPostfix::ToPostfix()
{
	string s, t;
	size_t i = 0;
	TSteck<string> zn(infix.length());
	while (i < infix.length()) {
		t = "";
		while (isdigit(infix[i])) {
			t = infix[i];
			i++;
			postfix += t;
		}
		if (t != "") {
			postfix += ",";
		}
		t = "";
		if (i != infix.length()) {


			while (!isdigit(infix[i])) {
				s = infix[i];
				
				if (((infix[i] != '+') && (infix[i] != '-') && (infix[i] != '*') && (infix[i] != '/') && (infix[i] != '(') && (infix[i] != '{') && (infix[i] != '}') && (infix[i] != ')') && (infix[i] != '.'))
					|| (infix[i] == '+' && infix[i+1]=='+') || (infix[i] == '-' && infix[i + 1] == '-')||(infix[i] == '*' && infix[i + 1] == '*')||(infix[i] == '/' && infix[i + 1] == '/')) {
					cout << infix[i] << endl;
					throw"uncorrect";
				}
				if (s == "}") {
					break;
				}
				if (s == "{") {
					if (t == "") {
						postfix += infix[i + 1];
						i++;
					}
					break;
				}

				if (s == "(" || s == ")") {

					if (t == "") {
						t = s;
						i++;

					}

					break;
				}

				t += infix[i];
				i++;
				if (t == " " || t == ",") {
					throw"space or ,";
				}
			}


			if (s == "}" || (s == "{" && t=="")) {
				if (s == "}") {
					postfix.pop_back();
				}
				i++;
				continue;
			}
			if (t == ".") {
				postfix.pop_back();
				postfix += t;
				continue;
			}

			if (zn.Empty() || zn.check() == "(") {
				zn.push(t);
				continue;
			}
			if (t == "(") {
				zn.push(t);
				continue;
			}
			if (t == ")") {
				while (zn.check() != "(") {
					postfix += zn.check();
					zn.top();
				}
				zn.top();
				continue;
			}
			if (comparison(zn, t)) {
				zn.push(t);
				continue;
			}
			else {
				while ((!zn.Empty()) && (!comparison(zn, t) || zn.check() != "(")) {
					postfix += zn.check();
					postfix += ",";
					zn.top();
				}
				zn.push(t);
				continue;
			}

		}

		else {
			break;
		}
	}
	

	while (!zn.Empty())
	{
		if (postfix[postfix.size() - 1] != ',') {
			postfix += ",";
		}
		postfix += zn.check();
		zn.top();
	}

	return postfix;
}


double TPostfix::Calculate()
{
	TSteck<string> res(postfix.length() / 2);
	string t="";
	char cur;
	double a;
	double b;
	int i = 0;
	while (true) {

		
		if(i<postfix.length()) {

			cur = postfix[i];
			while ((cur != ',') && (i!=postfix.length())) {
				t += postfix[i];
				i++;
				cur = postfix[i];
			}
			i++;
			if(t!=""){ res.push(t); }
			
			t = "";
			if (((postfix[i+1] == ',') && !isdigit(postfix[i]))||(i+1)==postfix.length())// уточнение тут не пройдет если постфиксная запись будет состоять из 1 числа
			{
				t = postfix[i];
				a = atof(res.check().c_str());
				res.top();
				b = atof(res.check().c_str());
				res.top();
				res.push(to_string(clc(t, b, a)));
				t = "";
				i++;
			}
		}
		else { break; }

	}
	return atof(res.check().c_str());
}
 