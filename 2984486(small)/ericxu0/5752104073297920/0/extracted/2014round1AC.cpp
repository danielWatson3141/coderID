#include <fstream>
using namespace std;

int main()
{
	ifstream in ("2014round1AC.in");
	ofstream out ("2014round1AC.out");

	int T;
	in >> T;

	for (int t = 1; t <= T; t++)
	{
		int N;
		in >> N;

		int num = 0;
		for (int i = 0; i < N; i++)
		{
			int a;
			in >> a;
			num += ((a >= i) ? 1 : -1);
		}

		out << "Case #" << t << ": " << ((num >= 0) ? "GOOD\n" : "BAD\n");
	}

	in.close();
	out.close();
	return 0;
}