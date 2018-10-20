// codejam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
int cmp(const void *p1, const void *p2) {
	long long a = *(long long *)p1;
	long long b = *(long long *)p2;
	if (a<b) return -1;
	if (a>b) return 1;
	return 0;
}
int count;
//按位不断更改
void findBit(long long src[], long long des[], int n,int l, int start, int move) {
	if (start == l) {
		qsort(src, n, sizeof(src[0]),cmp);
		bool find = true;
		for (int i=0; i<n; i++) {
			if (src[i] != des[i]) find = false;
		}
		if (find) count = count<move?count:move;
		return ;
	}
	for (int i=start; i<l; i++) {
		//第i位改动或者不改
		findBit(src, des, n,l, i+1, move);
		//改
		for (int j=0; j<n; j++) {
			src[j] = ( src[j] ^ (1<<i) );
		}
		findBit(src, des, n,l, i+1, move+1);
		for (int j=0; j<n; j++) {
			src[j] = ( src[j] ^ (1<<i) );
		}
	}
}
void q1() {
	int testCases;
	long long des[151];
	long long src[151];
	cin>>testCases;
	for (int cases=1; cases <= testCases; cases++) {
		count = 0x7fffffff;
		//直接循环
		int n;//n个
		int l;//l长
		cin>>n>>l;
		char c[42];
		for (int i=0; i<n; i++) {
			cin >> c;
			src[i] = 0;
			for (int k=0; k<l; k++) {
				src[i] += ((c[k]-'0')<<(l-1-k));
			}
		}
		for (int i=0; i<n; i++) {
			cin >> c;
			des[i] = 0;
			for (int k=0; k<l; k++) {
				des[i] += ((c[k]-'0')<<(l-1-k));
			}
		}
		qsort(des,n,sizeof(des[0]),cmp);
		findBit(src,des,n,l,0,0);
		if (count < 0x7fffffff) cout<<"Case #"<<cases<<": "<<count<<endl;
		else cout<<"Case #"<<cases<<": NOT POSSIBLE"<<endl;
	}
}



int main() {
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	q1();

	fclose(stdin);
	fclose(stdout);
	return 0;
}



