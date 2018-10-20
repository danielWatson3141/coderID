#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int N;
		cin >> N;
		int values[1000];
		for (int i = 0; i < N; ++i)
			cin >> values[i];

		int unusual = 0;
		for (int i = 0; i < N; ++i)
		{
			if ((values[i] >= (i - 1)) && (values[i] <= (i + 299)))
				++unusual;
		}

		cout << "Case #" << case_num << ": ";
		int expected = 255;
		if (unusual > (expected + 32))
			cout << "BAD";
		else
			cout << "GOOD";
		cout << endl;
	}
	return 0;
}