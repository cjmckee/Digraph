//Cody McKee

#ifndef WART_H
#define WART_H

#include <iostream>
#include <string>
#include "Digraph.h"
using namespace std;

class Wart
{
	public:
		Wart(string input);
		void encode(int);
		friend ostream & operator<< (ostream & out, Wart wart);
		void decode(Digraph & digraph);
		string getString();
		string unjumble(string input, int width);

	private:
		string store;

};



#endif
