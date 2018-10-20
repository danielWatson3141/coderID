#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int possible[150][150];
int u[40];
int N,L;
vector<string> orig, tar;
int DEBUG;

int doit2(int idx) {
	if(idx==L) return 0;
	if(u[idx]) return doit2(idx+1);
	int possibleCopy[150][150];
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) possibleCopy[i][j]=possible[i][j];
	int ret=1000;
	bool ok=true;
	for(int i=0;i<N;i++) {
		int anyPossible=0;
		for(int j=0;j<N;j++) {
			if(orig[i][idx]!=tar[j][idx]) possible[i][j]=0;
			if(possible[i][j]) anyPossible=1;
		}
		if(!anyPossible) {
			ok=false;
			break;
		}
	}
	if(ok) ret=min(ret,doit2(idx+1));
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) possible[i][j]=possibleCopy[i][j];
	ok=true;
	for(int i=0;i<N;i++) {
		int anyPossible=0;
		for(int j=0;j<N;j++) {
			if(orig[i][idx]==tar[j][idx]) possible[i][j]=0;
			if(possible[i][j]) anyPossible=1;
		}
		if(!anyPossible) {
			ok=false;
			break;
		}
	}
	if(ok) ret=min(ret,1+doit2(idx+1));
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) possible[i][j]=possibleCopy[i][j];
	return ret;
}

int doit(vector<string> original, vector<string> target) {
	orig=original;
	tar=target;
	N=original.size();
	L=original[0].size();
	for(int i=0;i<N;i++) for(int j=0;j<N;j++) possible[i][j]=1;
	for(int i=0;i<L;i++) u[i]=0;
	int ret=0;
	for(int i=0;i<L;i++) {
		int ct=0,ct2=0;
		for(int j=0;j<N;j++) if(original[j][i]=='1') ct++;
		for(int j=0;j<N;j++) if(target[j][i]=='1') ct2++;
		if(ct+ct!=L) {
			u[i]=1;
			if(ct==ct2) {
				for(int i2=0;i2<N;i2++) for(int j2=0;j2<N;j2++) if(original[i2][i]!=target[j2][i]) possible[i2][j2]=0;
			}
			else if(ct==N-ct2) {
				for(int i2=0;i2<N;i2++) for(int j2=0;j2<N;j2++) if(original[i2][i]==target[j2][i]) possible[i2][j2]=0;
				ret++;
			}
			else {
				return -1;
			}
		}
		else if(ct!=ct2) return -1;
	}
	if(DEBUG) cout<<"HERE"<<endl;
	if(DEBUG) {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) { 
				cout<<possible[i][j];
			}
			cout<<endl;
		}
	}
	ret+=doit2(0);
	if(ret>=1000) ret=-1;
	return ret;
}

int dumb2(vector<string> original, vector<string> target, int idx) {
	if(idx==original[0].size()) {
		sort(original.begin(),original.end());
		sort(target.begin(),target.end());
		if(original==target) return 0;
		return 1000;
	}
	int ret=1000;
	ret=min(ret,dumb2(original,target,idx+1));
	for(int i=0;i<original.size();i++) {
		if(original[i][idx]=='1') original[i][idx]='0';
		else original[i][idx]='1';
	}
	ret=min(ret,1+dumb2(original,target,idx+1));
	return ret;
}

int dumb(vector<string> original, vector<string> target) {
	int ret=dumb2(original,target,0);
	if(ret>=1000) ret=-1;
	return ret;
}

int main()
{
	ifstream infile;
	string prefix = "A-small-attempt3";
	//string prefix = "practice";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		int M,N;
		infile>>M>>N;
		vector<string> original,target;
		for(int j=0;j<M;j++) {
			string s;
			infile>>s;
			original.push_back(s);
		}
		for(int j=0;j<M;j++) {
			string s;
			infile>>s;
			target.push_back(s);
		}
		if(i==12) {
			for(int i=0;i<original.size();i++) cout<<original[i]<<endl;
			cout<<endl;
			for(int i=0;i<target.size();i++) cout<<target[i]<<endl;
			DEBUG=1;
		}
		else DEBUG=0;
		int ret=dumb(original,target);
		if(ret==-1) outfile << "Case #" << (i+1) << ": " << "NOT POSSIBLE" << endl; 
		else outfile << "Case #" << (i+1) << ": " << ret << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}