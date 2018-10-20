#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <queue>
#include <stack>
#include <string> 
#include <string.h> 
#include <fstream> 
#include <map> 
#include <iomanip> 
#include <cstdio> 
#include <cstdlib>
#include <cmath>
#include <deque>
#include <list>
#include <set>

using namespace std; 

const int MAX = 0x7FFFFFFF; 
const int MIN = 0x80000000;

int main()
{
	freopen("A-small-attempt1.in", "r", stdin) ;
	ofstream fout("result.txt") ; 
	int testcase, N, L ;
	string s1, s2 ; 
	set<string> set1, set2 ;
	vector<string> vc1, vc2 ;
	cin >> testcase ; 
	for(int t = 1; t <= testcase; t++)
	{
		cin >> N >>  L ; 
		for(int i = 0; i < N; i++)
		{
			cin >> s1 ; 
			set1.insert(s1) ; 
			vc1.push_back(s1) ;
		}
		for(int i = 0; i < N; i++)
		{
			cin >> s2 ; 
			set2.insert(s2) ; 
			vc2.push_back(s2) ; 
		}
		int res = MAX ; 
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				int count = 0, mask[64];
				memset(mask, 0, sizeof(mask)) ; 
				for(int l = 0; l < L; l++)
					if(vc1[i][l] != vc2[j][l])
						mask[count++] = l;
				vector<string> vc1temp ;
				string s1temp ;
				for(int vc1_i = 0; vc1_i < N; vc1_i++)
				{
					s1temp = vc1[vc1_i] ; 
					for(int c = 0; c < count; c++)
					{
						if(s1temp[mask[c]] == '0')
							s1temp[mask[c]] = '1' ;
						else
							s1temp[mask[c]] = '0' ;
					}
					vc1temp.push_back(s1temp) ; 
				}
				int flag = 0 ; 
				for(int vc1_i = 0; vc1_i < N; vc1_i++)
				{
					 if(set2.find(vc1temp[vc1_i]) == set2.end())
					 {
						 flag = 1 ; 
						 break; 
					 }
				}
				vc1temp.clear() ; 
				if(flag == 0)
					res = min(res, count) ; 
			}
		}
		fout << "Case #" << t << ": " ;
		if(res == MAX)
			fout << "NOT POSSIBLE" << endl ;
		else
			fout << res << endl ;
		set1.clear() ;
		set2.clear() ;
		vc1.clear() ; 
		vc2.clear() ; 
	}
	fout.close() ; 
	return 0 ; 
}