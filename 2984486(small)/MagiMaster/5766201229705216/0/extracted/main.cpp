#include <fstream>
using namespace std;

#include "Tree.cpp"

int main() {
	ifstream infile("B-small-attempt1.in");
	ofstream outfile("results.out");
	TreeTest t;
	t.go(infile, outfile);
}