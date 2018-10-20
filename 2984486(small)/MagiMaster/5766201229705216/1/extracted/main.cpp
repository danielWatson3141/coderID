#include <fstream>
using namespace std;

#include "Tree.cpp"

int main() {
	ifstream infile("B-large.in");
	ofstream outfile("results.out");
	TreeTest t;
	t.go(infile, outfile);
}