#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;
string str1[200],str2[200];
int main(){
	int tt;
	int i,j,k;
	int N,M;
	scanf("%d",&tt);
	for (int tcas = 1; tcas<=tt; tcas++){
		scanf("%d%d",&N,&M);
		for (i = 0;i<N; i++)
			cin>>str1[i];
		for (i = 0;i<N;i++)
			cin>>str2[i];
		map<long long,int> Hash;
		for (i = 0;i<N;i++)
			for (j = 0;j<N;j++){
				long long tmp = 0;
				for (k = 0;k<M;k++)
				{
					tmp= tmp*2+((str1[i][k]-'0')^(str2[j][k]-'0'));
				}
				//printf("%lld\n",tmp);
				Hash[tmp] = Hash[tmp]+1;
			}
		int ans = M+1;
		for (map<long long,int>::iterator p = Hash.begin(); p!=Hash.end(); p++){
			if (p->second==N){
				//printf("%lld %d\n",p->first, p->second);
				ans = min(ans, __builtin_popcount(p->first));
			}
		}
		printf("Case #%d: ", tcas);
		if (ans==M+1) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
}
