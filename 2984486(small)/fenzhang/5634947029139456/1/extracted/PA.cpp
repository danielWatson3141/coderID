#include<stdio.h>
#include<algorithm>

typedef long long int lnt;
typedef double dou;

using namespace std;

int n,l;
char s[200][200];
#include<string>

string a[200],b[200];
#include<vector>
//short sks[151][1<<21],ske[151][1<<21],top[200];
vector<short> sks[151],ske[151];
int dfs(int k){
	if(k==l){
		return 0;
	}
	int flag;
	int ans=7122;
	int sus;
	/*not push*/
	flag=1;
	//top[k+1]=0;
	sus=0;
	for(int i=0;i<sks[k].size();i++){
		int cnt1=0;
		int cnt2=0;
		int tn=ske[k][i]-sks[k][i];
		for(int j=0;j<tn;j++){
			if(b[j+      sus][k]=='0')cnt1++;
			if(a[j+sks[k][i]][k]=='0')cnt2++;
		}
		sus+=tn;
		if(cnt1!=cnt2){
			flag=0;
			break;
		}
		else{
			if(cnt1){
				sks[k+1].push_back(sks[k][i]);
				ske[k+1].push_back(sks[k][i]+cnt1);
				/*
				sks[k+1][top[k+1]]=sks[k][i];
				ske[k+1][top[k+1]]=sks[k][i]+cnt1;
				top[k+1]++;
				*/
			}
			if(tn-cnt1){
				sks[k+1].push_back(sks[k][i]+cnt1);
				ske[k+1].push_back(ske[k][i]);
				/*
				sks[k+1][top[k+1]]=sks[k][i]+cnt1;
				ske[k+1][top[k+1]]=ske[k][i];
				top[k+1]++;
				*/
			}
		}
	}
	if(flag){
		ans=min(ans,dfs(k+1));
	}
	sks[k+1].clear();
	ske[k+1].clear();
	/*push*/
	flag=1;
	//top[k+1]=0;
	sus=0;
	for(int i=0;i<sks[k].size();i++){
		int cnt1=0;
		int cnt2=0;
		int tn=ske[k][i]-sks[k][i];
		for(int j=0;j<tn;j++){
			if(b[j+      sus][k]=='0')cnt1++;
			if(a[j+sks[k][i]][k]=='0')cnt2++;
		}
		sus+=tn;
		if(cnt1!=tn-cnt2){
			flag=0;
			break;
		}
		else{
			if(tn-cnt2){
				sks[k+1].push_back(sks[k][i]+cnt2);
				ske[k+1].push_back(ske[k][i]);
				/*
				sks[k+1][top[k+1]]=sks[k][i]+cnt2;
				ske[k+1][top[k+1]]=ske[k][i];
				top[k+1]++;
				*/
			}
			if(cnt2){
				sks[k+1].push_back(sks[k][i]);
				ske[k+1].push_back(sks[k][i]+cnt2);
				/*
				sks[k+1][top[k+1]]=sks[k][i];
				ske[k+1][top[k+1]]=sks[k][i]+cnt2;
				top[k+1]++;
				*/
			}
		}
	}
	if(flag){
		ans=min(ans,dfs(k+1)+1);
	}
	sks[k+1].clear();
	ske[k+1].clear();
	return ans;
}
#include<iostream>
string c[200];
void sol(int uuu){
	scanf("%d %d",&n,&l);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		a[i]=s[i];
	}
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
		b[i]=s[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	sks[0].clear();
	ske[0].clear();
	sks[0].push_back(0);
	ske[0].push_back(n);
	/*
	top[0]=0;
	sks[0][top[0]]=0;
	ske[0][top[0]]=n;
	top[0]++;
	*/
	int ans=dfs(0);
	printf("Case #%d: ",uuu);
	if(ans==7122){
		puts("NOT POSSIBLE");
	}
	else{
		printf("%d\n",ans);
	}
	//for(int i=0;i<n;i++){
	//	cout<<a[i]<<' ';
	//}cout<<endl;
	//for(int i=0;i<n;i++){
	//	cout<<b[i]<<' ';
	//}cout<<endl;
	/*
	int aaa=7122;
	for(int bt=0;bt<(1<<l);bt++){
		int bitt=0;
		for(int j=0;j<l;j++){
			if(bt&(1<<j)){
				bitt++;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<l;j++){
				if(bt&(1<<j)){
					a[i][j]^=1;
				}
			}
			c[i]=a[i];
		}
		sort(c,c+n);
		int flag=1;
		for(int i=0;i<n;i++){
			if(b[i]!=c[i]){
				flag=0;
				break;
			}
		}
		if(flag){
			aaa=min(aaa,bitt);
		}
	}
	printf("Case #%d: ",uuu);
	if(aaa==7122){
		puts("NOT POSSIBLE");
	}
	else{
		printf("%d\n",aaa);
	}*/
}
/*
4 8
01101011 10100010 01011101 10010100
01101010 10100011 01011100 10010101
4 7
1010100 0101011 1011101 0100010
1011101 1010100 0100010 0101011
100
3 9
000001011 111101111 010011001
011110001 100010101 001100011
3 10
0100110110 0000101001 0011001011
0111011001 0011000110 0000100100
*/
int main(){
	
	freopen("A-large.in","r",stdin);
	freopen("a_l.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int ti=1;ti<=t;ti++){
		sol(ti);
	}
	return 0;
}
