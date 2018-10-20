#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Permutation
{
	vector<int> list;
	int n;
	int result;
public:
	void ReadInput(fstream &f)
	{
		f >> n;
		list.resize(n);
		for (int i = 0; i < n; i++)
			f >> list[i];
	}
	void Solve()
	{
		for (int i = 0; i < n; i++)
			if (list[i] == i)
			{
				result = 0;
				break;
			}
		result = 1;
	}
	void WriteOutput(int nTestCase, fstream &f)
	{
		f << "Case #" << nTestCase << ": " ;
		if (result == 0)
			f << "BAD";
		else
			f << "GOOD";
		f << endl;

	}
};
int main(int argc, char **argv)
{
	fstream input, output;
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::out);
	int nTestCase;
	input >> nTestCase;
	Permutation OL;
	for (int i = 0; i < nTestCase; i++)
	{
		OL.ReadInput(input);
		OL.Solve();
		OL.WriteOutput(i + 1, output);
	}
	input.close();
	output.close();
	return 0;
}