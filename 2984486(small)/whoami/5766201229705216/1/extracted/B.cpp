#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
#define min(a,b) ((a>b)?b:a)
vector<int> list[1001];
int n,print;
bool check[1001];
int pro(int k){
	int i,max1=-1,max2=-1,s;
	check[k]=1;
	for(i=0;i<list[k].size();i++){
		if(!check[list[k][i]]){
			s=pro(list[k][i]);
			if(max1<s){
				max2=max1;
				max1=s;
			}
			else if(max2<s)
				max2=s;
		}
	}
	if(max1==-1 && max2==-1)
		return 1;
	else if(max2==-1)
		return 1;
	else{
		return max1+max2+1;
	}
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt,test,i,a,b,s;
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%d",&n);
		for(i=0;i<n;i++)
			list[i].clear();
		for(i=0;i<n-1;i++){
			scanf("%d %d",&a,&b);
			a--;b--;
			list[a].push_back(b);
			list[b].push_back(a);
		}
		print=-1;
		for(i=0;i<n;i++){//root = i
			memset(check,0,sizeof(check));
			check[i]=1;
			s=pro(i);
			if(print<s)
				print=s;
		}
		printf("Case #%d: %d\n",test,n-print);
	}
	return 0;
}
