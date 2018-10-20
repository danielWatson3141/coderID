#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cctype>
#include <fstream>
using namespace std;

#define lowbit(x) ((x)&(-(x)))
#define sqr(x) ((x)*(x))
#define PB push_back
#define MP make_pair

int n=1000;

vector<int> gengood(){
	vector<int> a;a.resize(n);
	for (int i=0;i<n;i++) a[i]=i;
	for (int i=0;i<n;i++)
		swap(a[i],a[rand()%(n-i)+i]);
	return a;
}

vector<int> genbad(){
	vector<int> a;a.resize(n);
	for (int i=0;i<n;i++) a[i]=i;
	for (int i=0;i<n;i++)
		swap(a[i],a[rand()%n]);
	return a;
}

int f[1100];

double test(vector<int> a){
	double s=0;
	for (int i=0;i<1000;i++)
		if (a[i]<i+8) s+=1;
	return s;
	// memset(f,0,sizeof(f));
	// for (int i=0;i<1000;i++)if (!f[i]){
	// 	s+=1;
	// 	int cnt=0;
	// 	for (int j=i;f[j]==0;j=a[j]){
	// 		f[j]=true;
	// 		cnt++;
	// 	}
	// 	s+=exp(log(cnt)*4);
	// }
	// return s;

	// for (int i=0;i<a.size();i++){
	// 	f[i]=1;
	// 	for (int j=0;j<i;j++)
	// 		if (a[j]>a[i]) f[i]=max(f[j]+1,f[i]);
	// }
	// return f[a.size()-1];

	for (int i=0;i<1000;i++) s-=exp(log(a[i]+100)*5+log(i+1)*.5);
		int t=0;
		for (int i=0;i<1000;i++)
			for (int j=i+1;j<1000;j++)
				t+=a[j]<a[i];

	return s/t;
}

void local(){
	vector<vector<int> >t;t.clear();
	vector<double> k;k.clear();
	vector<int> res;res.clear();
	for (int i=0;i<1200;i++){
		int type=rand()%2;
		vector<int> a;
		if (type) a=gengood();
		else a=genbad();
		t.PB(a);
		k.PB(test(a));
		res.PB(type);
	}
	vector<double> q;q=k;
	sort(q.begin(),q.end());
	double thres=q[q.size()/2];
	int hit=0;
	int qq=0;
	for (int i=0;i<q.size();i++){
		//cout<<k[i]<<' '<<(k[i]>thres)<<' '<<i%2<<endl;
		int tres=k[i]>=thres;
		hit+=(tres==res[i]);
		qq+=tres;
	}
	cout<<qq<<"##"<<endl;
	cout<<thres<<endl;
	cout<<hit<<endl;
}

void submit(){
	int T;
	scanf("%d",&T);
	int n;
	vector<long long> s;s.clear();
	for (int i=0;i<T;i++){
		scanf("%d",&n);
		vector<int> a;a.clear();
		for (int i=0;i<n;i++){
			int k;
			scanf("%d",&k);
			a.PB(k);
		}
		s.PB(test(a));
	}
	vector<long long> q=s;
	sort(q.begin(),q.end());
	long long thres=q[T/2];
	for (int i=0;i<T;i++){
		printf("Case #%d: ",i+1);
		if (s[i]>=thres) printf("GOOD\n");
		else printf("BAD\n");
	}
}

int main(int argc,char** argv){
	srand(time(0));
	// int cnt=0;
	// int k=100;
	// vector<int> sum;sum.resize(1000);
	// for (int z=0;z<1000;z++){
	// 	vector<int> a=genbad();
	// 	for (int i=0;i<k;i++) sum[i]+=a[i];
	// }
	// int t=0;
	// for (int i=0;i<k;i++) {t+=sum[i];printf("%.2f ",sum[i]/1000.);}
	// 	puts("");
	// cout<<t/1000./k<<endl;
	
	//return 0;
	//local();return 0;
	submit();
	return 0;
}