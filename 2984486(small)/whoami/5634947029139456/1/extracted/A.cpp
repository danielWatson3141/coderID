#include <stdio.h>
#include <algorithm>
#include <string.h>
int m,n;
bool flip[51];
struct q{
	char mun[51];
	bool operator() (q a,q b){
		return strcmp(a.mun,b.mun)>0;
	}
}dev[201],code[201],save[201];
bool check(){
	int i,j;
	for(i=0;i<n;i++){
		strcpy(save[i].mun,code[i].mun);
		for(j=0;j<m;j++){
			if(flip[j])
				save[i].mun[j]=1-(code[i].mun[j]-'0')+'0';
		}
	}
	std::sort(save,save+n,q());
	for(i=0;i<n;i++){
		if(strcmp(save[i].mun,dev[i].mun)!=0)
			return false;
	}
	return true;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt,test,i,print,j,cnt;
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		print=0x7fffffff;
		scanf("%d %d",&n,&m);
		for(i=0;i<n;i++)
			scanf("%s",&code[i].mun);
		for(i=0;i<n;i++)
			scanf("%s",&dev[i].mun);
		std::sort(dev,dev+n,q());
		for(i=0;i<n;i++){
			cnt=0;
			for(j=0;j<m;j++){
				if(code[i].mun[j]!=dev[0].mun[j]){
					flip[j]=1;
					cnt++;
				}
				else
					flip[j]=0;
			}
			if(print>cnt && check()){
				print=cnt;
			}
		}
		printf("Case #%d: ",test);
		if(print==0x7fffffff)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n",print);
	}
	return 0;
}
