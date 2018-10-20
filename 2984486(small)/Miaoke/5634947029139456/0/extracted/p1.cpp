#include<iostream>
#include<stdio.h> 
#include<stdlib.h>
#include<fstream>
#include<set>
using namespace std;
ifstream fin("A-small-attempt1 (1).in");
ofstream fout("A-small-attempt1.out");
int minCount;
string a[151];
string b[151];
int T,N,L,ifP,count;
int cmp(const void * a, const void * b)
{
	if( *(string*)a < *(string*)b ) return -1;
	if( *(string*)a == *(string*)b ) return 0;
	if( *(string*)a > *(string*)b ) return 1;
}
bool check() {
//	cout<<"-----"<<endl;
	qsort(a,N,sizeof(string),cmp);
	for(int i=0;i<N;i++) {
//		cout<<a[i]<<" "<<b[i]<<endl;
	}
	for(int i=0;i<N;i++) {
		if(a[i]!=b[i]) return false;
	}
	return true;
}



void dfs(int point) {
//	if(point==L) return;
//	cout<<"Point: "<<point<<endl;
	if(check()) {
		if(count < minCount) minCount = count;
		ifP = 1;
	}
	if(point==L) return;
	dfs(point+1);
	for(int i=0;i<N;i++) {
		if(a[i][point]=='0') a[i][point]='1';
		else a[i][point] = '0';
	}
	count++;
	dfs(point+1);
	for(int i=0;i<N;i++) {
		if(a[i][point]=='0') a[i][point]='1';
		else a[i][point] = '0';
	}
	count--;
}
int main() {
	int a0[50],a1[50],b0[50],b1[50];
	char temp;
	fin>>T;
	for(int i=0;i<T;i++) {
		fin>>N>>L;
		minCount = 1000000;
		count = 0;
		ifP = 0;
		for(int j=0;j<N;j++)fin>>a[j];
		for(int j=0;j<N;j++)fin>>b[j];
		qsort(b,N,sizeof(string),cmp);
		dfs(0);
		if(!ifP) fout<<"Case #"<<i+1<<": NOT POSSIBLE"<<endl;
		else fout<<"Case #"<<i+1<<": "<<minCount<<endl;
	}

}
