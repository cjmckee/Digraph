//Cody McKee

#include "Wart.h"
#include "Digraph.h"
using namespace std;

int main (	)
{
	string file;
	string sentence;
	cout << "Enter file name for digraph: ";
	cin >> file;
	
	Digraph D(file);
	cout << endl;

	cin.get();
	cout << "Enter sentence terminated by <ENTER>: "; 
	getline(cin, sentence);
	
	cout << "This gets a score of: " << D.getScore(sentence) << endl;
	
	cout << "The decoded sentence is: " << endl;

	Wart W(sentence);
	W.decode(D);

	cout << W;
}
