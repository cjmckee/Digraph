//Cody McKee

#include <iostream>
#include <string>
#include <fstream>
#include "Digraph.h"

using namespace std;

//sets the proportions for the given digraphs, rest to 0
Digraph::Digraph()
{
	clear();
	array['t'-'a']['h'-'a'] = 0.1;
	array['h'-'a']['e'-'a'] = 0.1;
	array['i'-'a']['n'-'a'] = 0.1;
	array['e'-'a']['r'-'a'] = 0.1;
	array['a'-'a']['n'-'a'] = 0.1;
	array['r'-'a']['e'-'a'] = 0.1;
	array['n'-'a']['d'-'a'] = 0.1;
	array['a'-'a']['t'-'a'] = 0.1;
	array['o'-'a']['n'-'a'] = 0.1;
	array['n'-'a']['t'-'a'] = 0.1;
}

Digraph::Digraph(string filename)
{
	string line;
	int  count = 0;
	double max = 0;
	int findex = 0;
	int sindex = 0;

	std::ifstream infile(filename);

	clear();

	//while there are lines to read, iterate through the line and count occurrences of digraphs
	while(getline (infile, line))
	{
		for(int i = 0; i < (int)line.length() - 1; i++)
		{
			if(isLetter(line[i]) && isLetter(line[i+1]))
			{
				count ++;
				array[getIndex(line[i])][getIndex(line[i+1])] ++;
			}
		}
	}

	
	//divides all indexes by total number of digraphs to make all proportions add to 1
	for (int j = 0; j < 26; j++)
	{
		for(int k = 0; k < 26; k++)
		{	
			array[j][k] /= count;
	
			//finds the highest proportion and saves that and the index for printing
			if (array[j][k] > max)
			{
				max = array[j][k];
				findex = j;
				sindex = k;
			}
		}
	}
	cout << "Most common was: " << (char)(findex + 'a') << (char)(sindex + 'a') << " (proportion: " << max << ")";
}

//checks that the digraph is made up of two letters
bool Digraph::isLetter(char letter)
{
	if ((letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z'))
		return true;
	else
		return false;
}

//this is how I dealt with capital letters vs lowercase so that they return the same index
int Digraph::getIndex(char letter)
{
	 if ((letter >= 'A' && letter <= 'Z'))
		return letter - 'A';
	 else if(letter >= 'a' && letter <= 'z')
		return letter - 'a';
	 else 
		return 0;
}

//this will allow you to find the score given a digraph of two characters
double Digraph::getScore(char one, char two)
{
	return array[getIndex(one)][getIndex(two)];
}

//this adds up the digraph scores to give an overall string score (used for decoding)
double Digraph::getScore(string & input)
{
	double score = 0;
	for(int i = 0; i < (int)input.length() -1; i++)
	{
		if(isLetter(input[i]) && isLetter(input[i+1]))
		{
			score += array[getIndex(input[i])][getIndex(input[i+1])];
		}
	}
	return score;
}

//this just sets all the values in the array to 0 because C++ is kinda weird
void Digraph::clear()
{
	for (int k = 0; k < 26; k++)
	{
		for (int f = 0; f < 26; f++)
		{
			array[k][f] = 0;
		}
	}
}
