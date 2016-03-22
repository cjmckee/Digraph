//Cody McKee

#include "Digraph.h"
#include "Wart.h"
using namespace std;

int main (	)
{
	Digraph D("kafka.txt");
	Wart W("Ogurela enrs");
	W.unjumble("Ogurela enrs", 4);
	cout << W.getString();

	Wart f("Fucking finally");
	f.encode(3);
	cout << f.getString();
	//woo
}
