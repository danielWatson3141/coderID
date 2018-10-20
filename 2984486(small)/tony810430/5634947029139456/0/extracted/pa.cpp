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

int solve(int S)
{
	vector<XD> tmp;
	for( int i = 0; i < N; i++ ){
		XD temp = v[i];
		for( int j = 0; j < L; j++ ){
			if( (S&(1<<j)) > 0 ){
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
		for( int S = 0; S < (1<<L); S++ ){
			int tmp = S;
			int cnt = 0; 
			while( tmp > 0 ){
				cnt += (tmp%2);
				tmp /= 2;
				//puts("--");
			}
			if( solve(S) == 1 ){
				if( res == -1 || res > cnt ){
					res = cnt;
				}
			}
		//	puts("dd");
		}

		printf("Case #%d: ",cas);
		if( res == -1 )puts("NOT POSSIBLE");
		else	printf("%d\n",res);
	}	

	return 0;
}