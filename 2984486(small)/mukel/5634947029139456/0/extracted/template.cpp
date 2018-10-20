#include <bits/stdc++.h>
using namespace std;



int main()
{
	int T; cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		printf( "Case #%d: ", test );
		int N, L;
		cin >> N >> L;
		
		vector< int > outlet(N), device(N);
		
		for (int i = 0; i < N; ++i)
		{
			string s; cin >> s;
			for (int j = 0; j < L; ++j)
				outlet[i] = (outlet[i] << 1) + (s[j] == '1');
		}
		
		for (int i = 0; i < N; ++i)
		{
			string s; cin >> s;
			for (int j = 0; j < L; ++j)
				device[i] = (device[i] << 1) + (s[j] == '1');
		}
		
		sort(device.begin(), device.end());
		
		int ans = L + 1;
		for (int mask = 0; mask < (1 << L); ++mask)
		{
			auto t = outlet;
			for (int i = 0; i < N; ++i)
				t[i] ^= mask;
				
			sort(t.begin(), t.end());
			
			int bc = mask ? __builtin_popcount(mask) : 0;
			if (t == device)
				ans = min(ans, bc);
		}
		
		if (ans > L) printf( "NOT POSSIBLE\n");
		else printf( "%d\n", ans );
	}

	return 0;
}
