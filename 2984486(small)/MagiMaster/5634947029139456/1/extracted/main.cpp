#include <fstream>
using namespace std;

#include "Chaos.cpp"

int main() {
	ifstream infile("A-large.in");
	ofstream outfile("results.out");
	Chaos c;
	c.go(infile, outfile);
}