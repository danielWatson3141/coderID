#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	int a[2000];
	ifstream fin("C-small-attempt0.in");
	ofstream fout("C.out");
	fin >> T;
	int N;
	for(int it = 1; it <= T; ++it)
	{
	//cout << it << endl;
		fin >> N;
		for(int i=0; i<N; ++i)
		{
			fin >> a[i];
		}
		
		int cnt = 0;
		//cout << it << endl;
		for(int i=0; i<N/2; ++i)
		{
			if (a[i] <= N/2)	
				++cnt;
			if (a[i] < a[N-1-i])
				++cnt;
		}
		string ans;
		if (cnt > (N/2)/2*2) 
			ans = "BAD";
		else 
			ans = "GOOD";
		fout << "Case #" << it << ": " << ans << endl;
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
