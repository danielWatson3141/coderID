#include<iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<sstream>
#include<algorithm>
#include<map>
#include<complex>
#include<ctime>
#include<set>
using namespace std;


#define li			long long int
#define rep(i,to)	for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)	for(li i=(li)(start);i<((li)(to));i++)
#define pb			push_back
#define sz(v)		((li)(v).size())
#define bgn(v)		((v).begin())
#define eend(v)		((v).end())
#define allof(v)	(v).begin(), (v).end()
#define dodp(v,n)		memset(v,(li)n,sizeof(v))
#define bit(n)		(1ll<<(li)(n))
#define mp(a,b)		make_pair(a,b)
#define rin	rep(i,n)
#define EPS 1e-10
#define ETOL 1e-8
#define MOD 100000000
#define F first
#define S second
#define p2(a,b)		cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)		cout<<a<<"\t"<<b<<"\t"<<c<<endl


li n,l;
string s[300], sa[300];

li count(li x){
	li res=0;
	while(x>0){
		res+=x&1;
		x/=2;
	}
	return res;
}

vector<li> decode(li x){
	vector<li> res(50,0);
	rep(i,l)res[i]=x&bit(i);
	return res;
}

bool ok(li x){
	vector<li> hyo=decode(x);
	string ss[330];
	rep(i,n){
		ss[i]=s[i];
		rep(j,l){
			if(hyo[j]>0){
				if(ss[i][j]=='0')ss[i][j]='1';
				else ss[i][j]='0';
			}
		}
	}
	sort(ss, ss+n);
	/*
	rin{
		cout<<ss[i]<<" ";
	}puts("");
	*/

	bool res=true;
	rep(i,n){
		if(ss[i]!=sa[i])return false;
	}
	return res;
}

int main(){
	li cases;
	cin>>cases;
	rep(i,cases){
		cin>>n>>l;
		li res=l+1;
		rep(j,n){
			cin>>s[j];
		}
		rep(j,n){
			cin>>sa[j];
		}
		sort(sa,sa+n);

		rep(j,bit(l)){
			if(ok(j))res=min(res, count(j));
		}

		cout<<"Case #"<<i+1<<": ";
		if(res>l)puts("NOT POSSIBLE");
		else cout<<res<<endl;
	}

	return 0;
}