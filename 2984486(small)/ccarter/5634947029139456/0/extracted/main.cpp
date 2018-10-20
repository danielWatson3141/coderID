#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <strstream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR0(i,n) for(i=0;i<(n);++i)
#define FOR1(i,n) for(i=1;i<=(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define DEBUG(x) cout << #x << "=" << x << endl
#define CLR(x) memset((x),0,sizeof((x)))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

void RD(int &x){scanf("%d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(int &x,int &y,int &z){scanf("%d%d%d",&x,&y,&z);}
void RD(double &x,double &y,double &z){scanf("%lf%lf%lf",&x,&y,&z);}
void RD(char *s){scanf("%s",s);}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(double x) {printf("%.6lf\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char x[]) {printf("%s\n",x);}
void PRI(char x[]) {printf("%s",x);}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tt,tc;
	RD(tt);

	FOR1(tc,tt)
	{
		int n,l;
		RD(n,l);
		int per[10];
		int i,j;
		FOR0(i,n)
			per[i]=i;
		char ori[10][15];
		char to[10][15];

		FOR0(i,n)
			RD(ori[i]);
		FOR0(i,n)
			RD(to[i]);
		int diff[15];
		int mi=10000;
		do {
			FOR0(i,l)
				if (ori[0][i]==to[per[0]][i])
					diff[i]=0;
				else
					diff[i]=1;
			int flag=1;
			FOR1(i,n-1)
			{
				FOR0(j,l)
				{
					if ((ori[i][j]==to[per[i]][j] && diff[j]==0) ||
							(ori[i][j]!=to[per[i]][j] && diff[j]==1))
						;
					else
						flag=0;
				}
				if (flag==0) break;
			}
			if (flag)
			{
				int cnt=0;
				FOR0(i,l)
					cnt+=diff[i];
				if (cnt<mi) mi=cnt;
			}
		} while(next_permutation(per,per+n));
		printf("Case #%d: ",tc);
		if (mi==10000)
			printf("NOT POSSIBLE");
		else printf("%d",mi);
		printf("\n");



	}
	return 0;
}
