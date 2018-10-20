#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include<vector>
#include<set>
using namespace std;
int countOne(int i){
	int cnt = 0;
	while(i!=0){
		cnt++;
		i = i&(i-1);
	}
	return cnt;
}
int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t;
	scanf("%d",&t);
	for(int casenum = 0; casenum<t;++casenum){
		int n,l;
		scanf("%d%d",&n, &l);
		char str[110];
		int a[1100],b[1100];
		for(int i = 0;i<n;i++){
			scanf("%s",str);
			int temp = 0;
			for(int j = 0;str[j];j++){
				temp = temp*2 + str[j]-'0';
			}
			a[i] = temp;
		}
		for(int i = 0;i<n;i++){
			scanf("%s",str);
			int temp = 0;
			for(int j = 0;str[j];j++){
				temp = temp*2 + str[j]-'0';
			}
			b[i] = temp;
		}
		sort(b,b+n);
		set<int>  s;
		int ans = -1;
		for(int i = 0;i<n;i++)
			for(int j = 0;j<n;j++){
				int and = a[i]^b[j];
				if(ans!=-1 && ans < countOne(and))continue;
				if(s.find(and)!=s.end())continue;
				s.insert(and);
				int atmp[200];
				
				for(int k = 0;k<n;k++){
					atmp[k] = a[k]^and;
					
				}
				sort(atmp, atmp+n);
				int u;
				for(u = 0;u<n;u++){
					if(atmp[u]!=b[u])break;
				}
				if(u==n){
					ans = countOne(and);
				}
			}
		if(ans!=-1)
			printf("Case #%d: %d\n",casenum+1, ans);
		else
			printf("Case #%d: NOT POSSIBLE\n",casenum+1);
		
	}
	getchar();
	return 0;
}