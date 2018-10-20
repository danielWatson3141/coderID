#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cctype>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define mp make_pair
int geti(){int y=0,s=1;char c=getchar();while(!isdigit(c)&&c!='-')c=getchar();if(c=='-')s=-1,c=getchar();while(isdigit(c))y=y*10+(c-'0'),c=getchar();return s*y;}
int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int n,m;
set<string>list;
set<string>list2;
int rec(int a,int s){
	if(a==m){

		if(list==list2)
			return s;
		else
			return INT_MAX;
	}
	string x;
	int res=rec(a+1,s);
	set<string>test=list;
	list.clear();
	for(set<string>::iterator it=test.begin();it!=test.end();++it){
		x=*it;
		x[a]=49-x[a]+48;
		list.insert(x);
	}

	res=min(res,rec(a+1,s+1));
	list=test;
	return res;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.in","w",stdout);

	int t,k=1;
	scanf("%d",&t);
	string s;
	while(t--){
		scanf("%d%d",&n,&m);
		list.clear();
		list2.clear();
		for(int i=0;i<n;++i){
			cin>>s;
			list.insert(s);
		}
		for(int i=0;i<n;++i){
			cin>>s;
			list2.insert(s);
		}
		printf("Case #%d: ",k++);
		if(list==list2)
			printf("0\n");
		else{
			int res=rec(0,0);

			if(res==INT_MAX)
				printf("NOT POSSIBLE\n");
			else
				printf("%d\n",res);
		}
	}
	return 0;
}
