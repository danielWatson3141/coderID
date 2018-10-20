#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 1<<30
using namespace std;
const int MAXN=205;
char corg[MAXN],ctar[MAXN];
int org[MAXN],tar[MAXN],tlis[MAXN];
struct Dat{
	int bit,var;
	Dat(){
		bit=500;
		var=0;}
}dat[2048];
int cobit(int inp){
	int cot=0;
	while(inp){
		if(inp&1)cot++;
		inp>>=1;
	}
	return cot;
}
int trans(char inp[],int len){
	int tmp=0;
	for(int i=0;i<len;i++){
		tmp<<=1;
		if(inp[i]=='1')tmp|=1;
	}	
	return tmp;
}
bool cmp(Dat a,Dat b){
	if(a.bit==b.bit)return a.var<b.var;
	return a.bit<b.bit;
}
bool chk(int tot){
	sort(tlis,tlis+tot);
	for(int i=0;i<tot;i++){
	//	cout<<"Cmp "<<tlis[i]<<" "<<tar[i]<<endl;
		if(tlis[i]!=tar[i])return 0;}
	return 1;
}
bool chg(int inp[],int tot,int var){
	for(int i=0;i<tot;i++){
	//	cout<<inp[i]<<" "<<var<<" "<<(inp[i]^var)<<endl;
		tlis[i]=inp[i]^var;
	}
	return chk(tot);
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	for(int i=0;i<1025;i++){
		dat[i].var=i;
		dat[i].bit=cobit(i);
	}
	sort(dat,dat+1025,cmp);
	int cas,tcas;
	while(cin>>tcas){
		for(cas=0;cas<tcas;cas++){
			int n,l,flag;
			cin>>n>>l;
			for(int i=0;i<n;i++){
				cin>>corg;
				org[i]=trans(corg,l);}
			for(int i=0;i<n;i++){
				cin>>ctar;
				tar[i]=trans(ctar,l);} 
			sort(tar,tar+n);
			for(int i=0;i<1025;i++){
				flag=i;
				if(chg(org,n,dat[i].var))break;
				flag=1025;
			}
			cout<<"Case #"<<cas+1<<": ";
			if(dat[flag].bit<500)cout<<dat[flag].bit<<endl;
			else cout<<"NOT POSSIBLE"<<endl;
		} 
	}
	return 0;
}
/*

Input:
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01

Output:
Case #1: 1
Case #2: NOT POSSIBLE
Case #3: 0
*/