
#include <iostream>
#include <algorithm>

using namespace std;

struct pts
{
	int points;
	int index;
};

bool operator < (const pts &a, const pts &b)
{
	return a.points < b.points;
}

int main()
{
	int N, T;
	cin >> T;

	pts data[T];

	for (int t = 0; t < T; t++)
	{
		cin >> N;

		int x, points = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> x;
			if (x > i) points++;
			else if (x < i) points--;
		}

		data[t].points = points;
		data[t].index = t;
	}

	sort(data, data + T);

	bool results[T];

	for (int i = 0; i < T; i++)
	{
		results[data[i].index] = (i <= T/2);
	}

	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << (i+1) << ": " << (results[i] ? "GOOD" : "BAD") << endl;
	}

	return 0;
}


