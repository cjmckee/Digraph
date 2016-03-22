//Cody McKee

#include <iostream>
#include <string>
#include <cmath>
#include "Wart.h"
using namespace std;

//Initial value constructor
Wart::Wart (string input)
{
	store = input;
}

//I did it this way to avoid actually creating another array structure and then printing that
void Wart::encode (int width)
{
	string encoded = "";
	int length = store.length();

	int height = ceil(length/width);

	//fills in the extra places in the string
	if (length % width != 0)
	{
		for (int i = length; i < length * width - 1; i++)
		{
			store += " ";
		}
		store += ".";
	}

	//iterates through and adds letters based on where they would be in the encoded array
	for (int j = 0; j < width; j++)
	{
		for (int k = 0; k < height; k++)
		{
			encoded += store[j + width*k];
		}
	}

	store = encoded;
}

//overloaded <<
ostream & operator<< (ostream & out, Wart wart)
{
	out << wart.store << endl;
	return out;
}

//takes whatever string is in the Wart object and checks its score at various sizes using unjumble()
void Wart::decode(Digraph & digraph)
{	
	string jumble = store;
	int length = jumble.length();
	double maxScore = 0;
	string decoded = "";
	string jScore;

	for (int i = 1; i <= length; i++)
	{
		if (length % i == 0)
		{
			jScore = unjumble(jumble, i);
			if (digraph.getScore(jScore) > maxScore)
			{
				maxScore = digraph.getScore(jScore);
				decoded = jScore;
			}
		}
	}
	store = decoded;		
}


string Wart::getString()
{
	return store;
}

//this is the method that does the actual decoding. works exactly opposite of the encode function
string Wart::unjumble(string input, int width)
{
	string decode = "";
	int length = input.length();

	int height = ceil(length/width);
	
	//just like encode, but switches the array indeces
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
		{
			decode += input[i + height*k];
		}
	}
	return decode;
}
