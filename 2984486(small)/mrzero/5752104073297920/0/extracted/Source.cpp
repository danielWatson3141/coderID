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
int a[1001];
int main(){
	int t;
	freopen("in.in","r",stdin);freopen("out.out","w",stdout);
	int n;
	R(t);
	int cc=0;
	while(t--){
		R(n);
		++cc;
		printf("Case #%d: ",cc);
		int s=0;
		for(int i=0;i<n;++i)
			if(a[i]<=i)++s;
		if(s>777)printf("BAD\n");
		else printf("GOOD\n");
	}
}