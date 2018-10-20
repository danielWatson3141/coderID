#include<set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include<stdio.h>
#include <string>
#include <iostream>
using namespace std;





int m;
set<string>str;
set<string>str2;
int n;
int fun1(int a,int s){
	if(a==m){if(str==str2)return s;
		else return INT_MAX;
	}
	string x;



	int ans=fun1(a+1,s);set<string>tt=str;
	str.clear();
	for(set<string>::iterator iter=tt.begin();iter!=tt.end();++iter){
		x=*iter;x[a]=49-x[a]+48;str.insert(x);
	}

	ans=min(ans,fun1(a+1,s+1));str=tt;return ans;
}
int main()
{

    FILE *fp;
    fp=fopen("a2.txt","w");
	int t,k=1;
	scanf("%d",&t);
	string s;
	while(t--){
		cin>>n>>m;
		str.clear();str2.clear();
		for(int i=0;i<n;++i){
			cin>>s;str.insert(s);
		}
		for(int i=0;i<n;++i){
			cin>>s;str2.insert(s);
		}
		fprintf(fp,"Case #%d: ",k++);


		if(str==str2)
			fprintf(fp,"0\n");
		else{
			int ans=fun1(0,0);
			if(ans==INT_MAX)
				fprintf(fp,"NOT POSSIBLE\n");else
				fprintf(fp,"%d\n",ans);
		}
	}

}
