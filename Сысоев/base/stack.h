#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;
#include <iostream>
#include <algorithm>
using namespace	std;

template <typename T >
class TSteck
{
private:
	
	T* steck;
	int marker;
	int len_steck;

public:
	TSteck(){
		marker = -1;
		this->steck = new T[1];
		len_steck = 0;
	}
	TSteck(int len) {
		if ((len < 1) || (len > MaxStackSize))
			throw "Len_steck";
		marker = -1;
		steck = new T[len];
		len_steck = len;
	}


	TSteck(TSteck& TS) {
		marker = TS.marker;
		this->steck = new T[TS.len_steck];
		for (int i = 0; i < marker; i++) {
			this->steck[i] = TS.steck[i];
		}
		if (marker == 0) {
			this->steck[0] = TS.steck[0];
		}
	}
	~TSteck() {
		delete[] steck;
		steck = nullptr;
	}
	int Len() {
		return marker;
	}
	TSteck& operator=(TSteck& TS) {
		if (TS.Empty()) {
			throw"TS is empty";
		}
		else {
			TSteck res(TS);
			return res;
		}
	}
	bool operator ==(TSteck& TS) {
		if (marker == TS.marker) {
			for (int i = marker; i > -1; i--) {
				if (this->steck[i] != TS.steck[i]) {
					return false;
				}
			}
		}
		else {
			return false;
		}
	
	}

	void push( T Elem) {
		if (this->Full()) {
			cout << "steck is full can`t push elem" << endl;
			T* temp = steck;
			
			delete[] steck;
			steck = new T[len_steck * 2];
			steck = temp;
			marker++;
			steck[marker] = Elem;

		}
		else {
			marker++;
			steck[marker] = Elem;
		}
	}
	void top() {
		if (this->Empty()) {
			cout << "steck is empty can`t top elem" << endl;
			throw "steck is empty";
		}
		else {
			marker--;
		}
	}
	T check() {
		if (this->Empty()) {
			throw"steck is empty";
		}
		else {
			T res = steck[marker];
			return res;
		}
	}
	T check(int i) {
		if ((this->Empty())|| (i < 0)) {
			throw"steck is empty";
		}
		else {
			T res = steck[i];
			return res;
		}
	}
	bool Full() {
		if (marker == len_steck) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Empty() {
		if (marker == -1) {
			return true;
		}
		else {
			return false;
		}
	}


};

#endif


/*class TStack
{
  T *pMem;
  int size;
  int top;
public:
  TStack(int _size)
  {
    size = _size;
    top = -1;
    if ((size < 1) || (size > MaxStackSize))
      throw size;
    pMem = new T[size];
  }
  ~TStack()
  {
    delete [] pMem;
  }
};
*/