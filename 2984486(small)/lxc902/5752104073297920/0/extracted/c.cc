#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;

const int N = 1100;

int a[N];
int n;
char ans[2][999]={"GOOD","BAD"};

int main()
{
	int T; scanf("%d",&T);
    int cnt=0;
	for(int ka=1;ka<=T;ka++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);

        int s=0;
        for(int i=0;i<n;i++) s+=abs(a[i]-i);

        int bad=s>=n*(n-1)/3.199;
        printf("Case #%d: %s\n",ka,ans[bad]);
        cnt+=bad;
	}
    cerr<<cnt<<'/'<<T<<endl;

    return 0;
}
