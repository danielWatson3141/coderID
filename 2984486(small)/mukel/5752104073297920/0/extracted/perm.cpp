#include <bits/stdc++.h>
using namespace std;

const int
	MAXN = 1 << 10;

int N;
int p[MAXN];
pair< long long, int > score[MAXN];
bool good[150];

int dp[MAXN];

int getScore()
{
	long long score = 0;
	for (int i = 0; i < N; ++i)
	{
		dp[i] = 1;
		for (int j = 0; j < i; ++j)
			if (p[i] > p[j])
				dp[i] = max(dp[i], dp[j] + 1);
				
		score += dp[i];// * dp[i];
	}
	return score;
}

int main()
{
	/*
	int N = 5;
	int LIMIT = 1000000;
	
	vector< int > a(N);
	map< vector< int >, int > cnt;
	for (int t = 0; t < LIMIT; ++t)
	{
		for (int i = 0; i < N; ++i)
			a[i] = i;

		for (int j = 0; j < 1; ++j)
		for (int k = 0; k < N; ++k)
		{
	  		int p = rand()%N; // k + rand() % (N - k); //
	  		swap(a[k], a[p]);
	  	}
	  	
	  	cnt[a]++;
	}
	
	for (auto p : cnt)
	{
		for (int i = 0; i < N; ++i)
			cout << p.first[i] << " ";
		cout << "-> ";
		cout << p.second / (double)LIMIT << endl;
	}

	cout << cnt.size() << endl;

	return 0;
	*/

	int T; cin >> T;
	for (int test = 1; test <= T; ++test)
	{
		//printf( "Case #%d: ", test );
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> p[i];
			
		long long s = getScore();
		reverse(p, p + N);
		s += getScore();
		
		score[test - 1] = make_pair(s, test);
	}
	
	sort(score, score + T);
	
	for (int i = 0; i < T / 2; ++i)
		good[ score[i].second ] = true;
	
	for (int test = 1; test <= T; ++test)
	{
		printf( "Case #%d: ", test );
		if (good[test]) printf( "GOOD\n");
		else printf("BAD\n");
	}

	return 0;
}
