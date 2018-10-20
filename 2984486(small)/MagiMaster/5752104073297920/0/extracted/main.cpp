#include <fstream>
using namespace std;

#include "Permutate.cpp"

int main() {
	ifstream infile("C-small-attempt2.in");
	ofstream outfile("results.out");
	Permutate p;
	p.go(infile, outfile);
}