#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<map>
#include<string>
#include<set>

#define lson L,M,now<<1
#define rson M+1,R,now<<1|1
using namespace std;


int N;
int T;
int L;
struct XD{
	char s[100];
};

vector<XD> v;
vector<XD> ans;
int res;

bool comp( XD a, XD b)
{

	return strncmp(a.s,b.s,L)<0;
}

int solve(long long S)
{
	vector<XD> tmp;
	for( int i = 0; i < N; i++ ){
		XD temp = v[i];
		for( int j = 0; j < L; j++ ){
			if( (S&((1LL)<<j)) > 0 ){
				temp.s[j] = (temp.s[j]=='0'?'1':'0');
			}
		}
		tmp.push_back(temp);
	}
	sort(tmp.begin(),tmp.end(),comp);
	for( int i = 0; i < N; i++ )
		if( strncmp(tmp[i].s,ans[i].s,L) != 0 )
			return 0;
	return 1;
}

int main()
{
	scanf(" %d",&T);

	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %d %d",&N,&L);
		ans.clear();v.clear();
		for( int i = 0; i < N; i++ ){
			XD tmp;
			scanf(" %s",tmp.s);
			v.push_back(tmp);
		}

		for( int i = 0; i < N; i++ ){
			XD tmp;
			scanf(" %s",tmp.s);
			ans.push_back(tmp);
		}
		sort(ans.begin(),ans.end(),comp);

		res = -1;
		for( int i = 0; i < N; i++ ){
			for( int j = 0; j < N; j++ ){
				long long S=0;
				int cnt=0;
				for( int k = 0; k < L; k++ ){
					if( v[i].s[k] != ans[j].s[k] ){
						cnt++;
						S |= ((1LL)<<k);
					}
				}
				if( solve(S) == 1 ){
					if( res == -1 || res > cnt )res = cnt;
				}
			}
		}

		printf("Case #%d: ",cas);
		if( res == -1 )puts("NOT POSSIBLE");
		else	printf("%d\n",res);
	}	

	return 0;
}