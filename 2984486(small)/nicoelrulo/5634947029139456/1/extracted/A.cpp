#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
string s1[256], s2[256];
int flip[64];

char rev(char c){
	if(c=='1')return '0';
	else return '1';
}
int main(){
	int t; cin>>t;
	forn(tc,t){
		int n, l;
		cin>>n>>l;
		forn(i,n)cin>>s1[i];
		forn(i,n)cin>>s2[i];
		int res = 1000;
		vector<string> v1;
		forn(i,n)v1.pb(s1[i]);
		sort(v1.begin(), v1.end());
		forn(i,n){
			int changes = 0;
			forn(j,l){
				if (s1[0][j]==s2[i][j])flip[j]=0;
				else {flip[j]=1; changes++;}
			}
			vector<string>v2;
			forn(j,n)v2.pb(s2[j]);
			forn(j,n)forn(k,l){
				if(flip[k]==1)v2[j][k]=rev(v2[j][k]);
			}
			sort(v2.begin(), v2.end());
			if(v1==v2)res=min(res,changes);
		}
		printf("Case #%d: ", tc+1);
		if(res==1000)printf("NOT POSSIBLE\n");
		else printf("%d\n", res);
	}
}
