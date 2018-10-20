#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<int(n); i++)
int a[1003], n;
bool gao(){
	int cnt=0;
	REP(i,n)
		if(a[i]-i>0 && a[i]-i<200)cnt++;
	return cnt<197;
}
int main(){
	int T;
	scanf("%d", &T);
	REP(tt, T){
		scanf("%d", &n);
		REP(i,n) scanf("%d",a+i);
		printf("Case #%d: %s\n", tt+1, gao()?"GOOD":"BAD");
	}
}
