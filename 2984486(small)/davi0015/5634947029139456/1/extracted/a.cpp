#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B; I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main() {
	int T;
	cin >> T;
	
	forn (i, T)
	{
		int N, L;
		cin >> N >> L;
		
		vector <string> init(N);
		vector <string> req(N);
		forn (j, N)
			cin >> init[j];
		forn (j, N)
			cin >> req[j];
		
		sort (req.begin(), req.end());
		vector <string> copy;
		int ans = -1;
		forn (j, N)
		{
			int temp = 0;
			forn (k, L)
			{
				if (req[0][k] != init[j][k])
					temp++;
			}
			
			if (ans==-1 || ans > temp)
			{
				copy = init;
				forn (k, L)
				{
					if (req[0][k] != init[j][k])
					{
						forn (l, N)
						{
							copy[l][k] = '0' + '1' - copy[l][k];
						}
					}
				}
				
				sort(copy.begin(), copy.end());
				
				bool possible = true;
				forn (k, N)
				{
					if (copy[k] != req[k])
					{
						possible = false;
						break;
					}
				}
				
				if (possible)
				{
					ans = temp;
				}
			}
		}
		
		cout << "Case #" << i+1 << ": ";
		if (ans == -1)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	
	return 0;
}