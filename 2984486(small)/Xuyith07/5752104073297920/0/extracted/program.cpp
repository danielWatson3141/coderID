#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<stdint.h>
#include<map>
using namespace std;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

/*
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("test.txt");
	out.open("out.txt");
	in>>CaseNum;
	for(int Case=0;Case<CaseNum;Case++){



	out<<"Case #"<<Case+1<<":";
	}
	return 0;
}
*/
int main(){
	int CaseNum;
	ifstream in;
	ofstream out;
	in.open("C-small-attempt0.in");
	out.open("out.txt");
	in>>CaseNum;
	int N;
	for(int Case=0;Case<CaseNum;Case++){
		in>>N;
		int sum=0;
		int t;
		for(int i=0;i<N;i++){
			in>>t;
			if(t==i+1)sum++;
		}
		if(sum<2)
		out<<"Case #"<<Case+1<<": "<<"GOOD"<<endl;
		else
		out<<"Case #"<<Case+1<<": "<<"BAD"<<endl;
	}
	return 0;
}