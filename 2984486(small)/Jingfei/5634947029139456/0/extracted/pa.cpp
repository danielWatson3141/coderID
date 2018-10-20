#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string ar[160];
string ar2[160];
string cor[160];
int L,N,Ans;
bool Find;
bool s[50];
void dfs(int);
/*
bool CmpChar(char *a,char *b){
	int Len=strlen(a);
	for(int i=0; i<Len; ++i)
		if(a[i]!=b[i]) return a[i]<b[i];
	return 1;
}
*/
bool cmp(){
	for(int i=0; i<N; ++i){
//		cout << ar2[i] << ' ' << cor[i] << endl;
		if(ar2[i]!=cor[i]){
//			cout << "false" << endl;
			return false;
		}
	}
	return true;
}

int main(){
    int T; scanf("%d",&T);
    for(int Case=1; Case<=T; ++Case){
        scanf("%d%d",&N,&L); getchar();
        for(int i=0; i<N; ++i){
        //    scanf("%s",ar[i]);
			cin >> ar[i];
//            getchar();
        }
        for(int i=0; i<N; ++i){
        //    scanf("%s",cor[i]);
			cin >> cor[i];
//            getchar();
        }
//		for(int i=0; i<N; ++i)
//			printf("%s %s\n",ar[i],cor[i]);
//			cout << ar[i] << ' ' << cor[i] << endl;
        sort(cor,cor+N);
        //
		Find=false;
		memset(s,false,sizeof(s));
		dfs(0);
        printf("Case #%d: ",Case);
        if(!Find) printf("NOT POSSIBLE\n");
        else printf("%d\n",Ans);
    }
    return 0;
}

void dfs(int dep){
	if(Find) return;
	if(dep==L){
		Ans=0;
		bool First=true;
		for(int i=0; i<N; ++i){
			ar2[i]="";
			for(int j=0; j<L; ++j){
				if(s[j]){ 
					ar2[i]+=(ar[i][j]=='1'?'0':'1'); 
					if(First) ++Ans; 
				}
				else ar2[i]+=ar[i][j];
			}
			if(First) First=false;
//			ar2[i]+='\0';
		}
		sort(ar2,ar2+N);
		if(cmp()) Find=true;
//		printf("Ans: %d\n",Ans/N);
		return;
	}
	s[dep]=0;
	dfs(dep+1);
	s[dep]=1;
	dfs(dep+1);
}

