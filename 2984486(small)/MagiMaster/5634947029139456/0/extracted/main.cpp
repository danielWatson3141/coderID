#include <fstream>
using namespace std;

#include "Chaos.cpp"

int main() {
	ifstream infile("A-small-attempt0.in");
	ofstream outfile("results.out");
	Chaos c;
	c.go(infile, outfile);
}