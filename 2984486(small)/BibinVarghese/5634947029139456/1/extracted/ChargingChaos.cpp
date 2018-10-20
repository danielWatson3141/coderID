#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

int main(int argc, char *argv[])
{
	int T, N, L, Cases = 0, i, j, k, res, min, count;
	vector<long long int> Init, Req;
	set<long long int> final;
	set<long long int>::iterator iter;
	vector< vector <long long int>> mat;
	int tmp;
	scanf("%d", &T);

    do
    {
		scanf("%d %d", &N, &L);
		Init.resize(N,0);
		Req.resize(N,0);
		mat.resize(N,vector<long long int>(N));
		for(i=N-1;i>=0;--i)
		{
			for(j=0; j<L; ++j)
			{
				scanf("%1d", &tmp);				
				Init[i] <<= 1;
				Init[i] |= tmp?1:0;
			}
		}
		for(i=N-1;i>=0;--i)
		{
			for(j=0; j<L; ++j)
			{
				scanf("%1d", &tmp);			
				Req[i] <<= 1;
				Req[i] |= tmp?1:0;
			}
			for(k=0;k<N;++k)
			{
				mat[i][k] = Req[i] ^ Init[k];
			}
		}
		final.insert(mat[0].begin(), mat[0].end());
		for(i=1;i<N;++i)
		{
			for(iter = final.begin(); iter != final.end(); )
			{
				if( find(mat[i].begin(), mat[i].end(), *iter) == mat[i].end() )
				{
					final.erase(iter);
					iter = final.begin();
				}
				else
				{
					++iter;
				}
			}
		}
		if(final.size())
		{
			min = INT_MAX;
			for(iter = final.begin(); iter != final.end(); ++iter)
			{
				bitset<64> bar (*iter);
				count = bar.count();
				if( count < min)
					min = count;
			}
			printf("Case #%d: %d\n", ++Cases, min);
		}
		else
		{
			printf("Case #%d: NOT POSSIBLE\n", ++Cases);
		}



		/*if( N == 1)
		{
			printf("Case #%d: %d %d\n", ++Cases, res, res );
		}
		else
		{
			printf("Case #%d: %d %d\n", ++Cases,  );
		}*/
		Init.clear();
		Req.clear();
		mat.clear();
		final.clear();
	}while(--T); 
}