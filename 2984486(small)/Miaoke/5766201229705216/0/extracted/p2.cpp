#include<iostream>
#include<stdio.h> 
#include<stdlib.h>
#include<fstream>
#include<set>
using namespace std;
ifstream fin("B-small-attempt1.in");
ofstream fout("B-small-attempt1.out");
int T,N;
bool graph[1001][1001];
int nodeMax[1001],max;
set<int> mySet; 

int cmp(const void * a, const void * b)
{
	if( *(int*)a < *(int*)b ) return 1;
	if( *(int*)a == *(int*)b ) return 0;
	if( *(int*)a > *(int*)b ) return -1;
}


int compute(int point) {
//	cout<<"Point "<<point<<endl;
	mySet.insert(point);
	int childNum = 0;
	int result[N],p = 0;
	for(int i=0;i<=N;i++) result[i] = 0;
	for(int i=1;i<=N;i++) {
		if(graph[point][i] && mySet.find(i)==mySet.end() ) {
			result[p++] = compute(i);// 还能优化 
			childNum++;
		}
	}
//	cout<<"Point:"<<point<<" "<<childNum<<" "<<1 + result[0] + result[1]<<endl;
	if(childNum == 0 || childNum == 1) return 1;
	else{
		qsort(result,p,sizeof(int),cmp);
		return 1 + result[0] + result[1];
	}
} 
int main() {
	int x,y,tt,max;
	fin>>T;
	for(int k=0;k<T;k++) {
		fin>>N;
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=N;j++) {
				graph[i][j] = false;
			}
		}
		for(int j=1;j<N;j++){
			fin>>x>>y;
			graph[x][y] = true;
			graph[y][x] = true;
		}
		max = 0;
		for(int j=1;j<=N;j++) {
			mySet.clear();
			tt= compute(j);
	//		cout<<tt<<endl;
			if(tt>max) max = tt;
		}
	//	cout<<"Final:"<<N-max;
	fout<<"Case #"<<k+1<<": "<<N-max<<endl;
	}
}
