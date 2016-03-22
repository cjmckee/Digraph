//Cody McKee

#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include <string>

using namespace std;

class Digraph
{
	public:
		Digraph();
		Digraph(string filename);
		bool isLetter(char letter);
		int getIndex(char letter);
		double getScore(char one, char two);
		double getScore(string & input);
		void clear();

	private:
		double array[26][26];
};

#endif
