//prob A | wiragotama@gmail.com
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>
#include <utility>
#include <stack>
#include <queue>
using namespace std ;
typedef long long int LL ;

//for sorting
bool asc (int i,int j) { 
	return (i<j);
}

bool dsc (int i,int j) { 
	return (i>j);
}


string arr[151], device[151];
int jawaban=300;


int beda(int total, int idx, string *arr) {
	int c =0;
	for (int p=0; p<total; p++) {
		if (arr[p][idx]!=device[p][idx]) {
			c++;
		}
	}
	return c;
}

void tukar(int total, int idx, string *arr) {
	for (int p=0; p<total; p++) {
		if (arr[p][idx]=='0') {
			arr[p][idx]='1';
		}
		else arr[p][idx]='0';
	}
}

void permutation(int now, int l, int n, int count, string *arr) {
	if (now==l) {
		//cout << "per " << count << endl;
		sort(arr,arr+n);
		/*for (int x=0; x<n; x++) {
			cout << arr[x] << " " << device[x] << endl;
		}*/
		bool stop=false;
		for (int x=0; x<l && !stop; x++) {
			if (beda(n,x,arr)>0) {
				stop=true;
			}
		}
		if (!stop) {
			if (count<jawaban) {
				jawaban = count;
			}
		}
	}
	else {
		string tempA[151];
		for (int i=0; i<n; i++)
			tempA[i] = arr[i];
		
		permutation(now+1,l,n,count,arr); //0
		tukar(n,now,tempA);
		permutation(now+1,l,n,count+1,tempA); //1
	}
}

//main program
int main () {
	int n, l, t;
	
	scanf("%d",&t);
	for (int z=1; z<=t; z++) {
		scanf("%d %d",&n,&l);
		
		
		bool flag[n];
		for (int i=0; i<n; i++) {
			flag[i] = false;
		}
		int count = 0, bisa = 0;
		
		for (int i=0; i<n; i++) {
			cin>>arr[i];
		}
		
		for (int i=0; i<n; i++) {
			cin>>device[i];
		}
		sort(device,device+n);
		permutation(0,l,n,0,arr);
		
		if (jawaban<l)
			printf("Case #%d: %d",z,jawaban);
		else 
			printf("Case #%d: NOT POSSIBLE",z);
		if (z<t) printf("\n");
		jawaban=300;
	}
	return 0;
}
