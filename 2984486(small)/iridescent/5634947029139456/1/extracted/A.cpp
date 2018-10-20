#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int INF = 123123123;

int N, L;
string bits0[155];
string bits[155];
string matches[155];

#define FLIP(c) ((c) == '0' ? '1' : '0')

int main2()
{
	cin >> N >> L;
	for(int i = 0; i < N; i++) cin >> bits0[i];
	for(int i = 0; i < N; i++) cin >> matches[i];
	int best = INF;
	for(int m0 = 0; m0 < N; m0++)
	{
		for(int i = 0; i < N; i++) bits[i] = bits0[i];

		int cur = 0;
		for(int i = 0; i < L; i++)
		{
			if(bits[m0][i] != matches[0][i])
			{
				for(int j = 0; j < N; j++) bits[j][i] = FLIP(bits[j][i]);
				cur++;
			}
		}

		bool valid = true;
		set<string> S;
		for(int i = 0; i < N; i++) S.insert(bits[i]);
		for(int i = 0; i < N; i++) if(S.find(matches[i]) == S.end()) valid = false;

		if(valid) best = min(best, cur);
	}
	if(best == INF) cout << "NOT POSSIBLE\n";
	else cout << best << endl;
	return 0;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		main2();
	}
}
