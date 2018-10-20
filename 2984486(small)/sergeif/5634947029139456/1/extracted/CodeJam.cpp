#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

bool cmpSize(const VI& a, const VI& b)
{
	if (a.size() < b.size())
		return true;
	if (a.size() == b.size())
	{
		int asize = a.size();
		for (int i=1; i<asize; ++i)
		{
			if (a[i] < b[i])
				return true;
		}
	}
	return false;
}
int main()
{
	int T;
	cin >> T;
	REP(t,T)
	{
		cout << "Case #" << (t+1) <<": ";
		
		int N,L;
		cin >> N >> L;
		VS outl(N, ""), dev(N, "");
		REP(i,N)
			cin >> outl[i];
		REP(i,N)
			cin >> dev[i];
		VI K(L, 0), D(L, 0), F(L, 0);
		bool bOk = true;
		int sw = 0;
		REP(j,L)
		{
			int kk = 0, dd = 0;
			REP(i,N)
			{
				if (outl[i][j] == '1') kk++;
				if (dev[i][j] == '1') dd++;
			}
			K[j] = kk;
			D[j] = dd;
			if (kk != dd && N - kk != dd)
				bOk = false;
			if (bOk && (N - kk) == dd && (N % 2 == 1 || kk != N / 2))
			{
				REP(i,N)
				{
					if (outl[i][j] == '1') outl[i][j] = '0';
					else outl[i][j] = '1';
				}
				sw++;
			}
			if (bOk && kk == N / 2 && N % 2 == 0)
				F[j] = 1;
		}
		
		vector< VI > matrix; 
		REP(i,N)
		{
			int msize = matrix.size();
			REP(j,N)
			{
				bool bCan = true;
				VI tmp;
				tmp.push_back(i);
				REP(l, L)
				{
					if (outl[j][l] != dev[i][l] && F[l] == 0)
					{
						bCan = false;
						break;
					}
					if (outl[j][l] != dev[i][l] && F[l] == 1)
						tmp.push_back(l);
				}
				if (bCan)
					matrix.push_back(tmp);
			}
			if (matrix.size() == msize)
			{
				bOk = false;
				break;
			}
		}

		if (bOk)
		{
			//cout << endl << "sw: " << sw << endl;
			bOk = false;
			std::sort(matrix.begin(), matrix.end(), cmpSize);
			
			int msize = matrix.size();
			/*REP(i,msize)
			{
				cout << matrix[i].size() << ": ";
				REP(j,matrix[i].size())
					cout << matrix[i][j] << " ";
				cout << endl;
			}*/
			REP(i,msize)
			{
				set<int> sss;
				sss.insert(matrix[i][0]);
				bool bCan = true;
				int slen = 0;
				for (int j=i+1; j<msize && bCan; ++j)
				{
					if (matrix[i].size() != matrix[j].size())
					{
						bCan = false;
						break;
					}
					int nn = matrix[i].size();
					bool bEq = true;
					for (int l=1; l<nn && bEq; l++)
						bEq = matrix[i][l] == matrix[j][l];
					if (! bEq){
						continue;
					}
					else{
						sss.insert(matrix[j][0]);
					}
				}
				if (sss.size() == N){
					sw += matrix[i].size() - 1;
					bOk = true;
					break;
				}
			}
		}
		if (bOk)
		{
			cout << sw << endl;
		}else
			cout << "NOT POSSIBLE" << endl;
	}
	
	return 0;
}

