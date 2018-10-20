#include <vector>
#include <list>
#include <map>
#include <set>
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
#include <queue>

using namespace::std;

int n;
int a[1005];
double cnt;
int cnt1;
pair<pair<int,double>,int> caa[1005];
bool ans[1005];

void input(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	cnt=1.0;
	cnt1=0;
	for(int i=0;i<n;i++){
		cnt*=abs(i-a[i])+1;
		if(cnt>10000000){
			cnt/=10000000;
			cnt1++;
		}
	}
	/*
	n=4;
	for(int i=0;i<n;i++) a[i]=i;
	for(int i=0;i<n;i++){
		swap(a[0],a[i]);
		for(int j=0;j<n;j++){
			swap(a[1],a[j]);
			for(int k=0;k<n;k++){
		swap(a[2],a[k]);
		for(int l=0;l<n;l++){
			swap(a[3],a[l]);
		c[a[0]][a[1]][a[2]][a[3]]++;
		cnt++;
		}
			}
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			for(int l=0;l<n;l++)
				if(i!=j && j!=k && k!=i && l!=i && l!=j && l!=k)
					cnt1++;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
			for(int l=0;l<n;l++)
				if(i!=j && j!=k && k!=i && l!=i && l!=j && l!=k)
				printf("%d %d %d %d : %d  %.1lf\n",i,j,k,l,c[i][j][k][l],(double)cnt/cnt1);*/
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ca=0,t;
	scanf("%d",&t);
	while(t--){
		input();
		caa[++ca]=make_pair(make_pair(cnt1,cnt),ca);
	}
	sort(caa+1,caa+ca+1);
	for(int i=1;i<=ca/2;i++) ans[caa[i].second]=true;
	for(int i=1;i<=ca;i++){
		printf("Case #%d: ",i);
		if(ans[i]) printf("BAD\n");
		else printf("GOOD\n");
	}
	return 0;
}