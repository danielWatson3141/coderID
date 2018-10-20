#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<map>
#include<cstdlib>
#include<stdio.h>
#include<set>
#include<cmath>
#include<cstring>
#include<utility>
#include<string>
#include<iomanip>
using namespace std;
void R( int &x ) {
x = 0;
char temp;
temp = getchar();
while( ! isdigit( temp ) && temp != '-' ) {
temp = getchar();
}
bool neg = 0;
if( temp == '-' ) {
neg = 1;
}
else if( isdigit( temp ) ) {
x = ( temp - '0' );
}
temp = getchar();
while( isdigit( temp ) ) {
x *= 10;
x += ( temp - '0' );
temp = getchar();
}
if( neg )
x *= - 1;
}
void R( long long &x ) {
x = 0;
char temp;
temp = getchar();
while( ! isdigit( temp ) && temp != '-' ) {
temp = getchar();
}
bool neg = 0;
if( temp == '-' ) {
neg = 1;
}
else if( isdigit( temp ) ) {
x = ( temp - '0' );
}
temp = getchar();
while( isdigit( temp ) ) {
x *= 10;
x += ( temp - '0' );
temp = getchar();
}
if( neg )
x *= - 1;
}
#define MAX 100005
int a1[11],a2[11],atmp[11];
bool nk7ed[11];
int main(){
	int t;
	freopen("in.in","r",stdin);freopen("out.out","w",stdout);
	int n,l;
	R(t);
	int cc=0;

	while(t--){
		R(n),R(l);++cc;
		int best=n+1;
		char tmp[11];
		for(int i=0;i<n;++i)
		{
			a1[i]=0;
			scanf("%s",tmp);
			for(int j=0;j<l;++j)
				if(tmp[j]=='1')
					a1[i]|=(1<<j);
		}
		for(int i=0;i<n;++i)
			{
			a2[i]=0;
			scanf("%s",tmp);
			for(int j=0;j<l;++j)
				if(tmp[j]=='1')
					a2[i]|=(1<<j);
		}
		for(int msk=0;msk<(1<<l);++msk){

			for(int i=0;i<n;++i){
				atmp[i]=a1[i];
				atmp[i]^=msk;
				nk7ed[i]=0;
			}
			int cost=0;
			for(int i=0;i<l;++i)
				if(((1<<i)&msk))++cost;
			int nt=0;
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j){
					if(nk7ed[j])continue;
					if(atmp[j]==a2[i]){++nt;
					nk7ed[j]=1;
					break;
					}
				}
			if(nt==n)best=min(best,cost);
		}
		printf("Case #%d: ",cc);
		if(best>n)printf("NOT POSSIBLE\n");
		else printf("%d\n",best);
	}}