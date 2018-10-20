#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int h[1001];
int d[2000];
int p[2000];
int v[2000];
int u[2000];
int m;

int compare(int i,int j){
	return (v[i]<v[j])-(v[i]>v[j]);
}
int compare2(int i,int j){
	return (u[i]<u[j])-(u[i]>u[j]);
}
void dfs(int parent,int x){
	//cerr<<x<<endl;
	//cerr<<h[x]<<p[h[x]]<<endl;
	vector<int> s;
	for(int i=h[x];i!=-1;i=p[i]) if(d[i]!=parent){
		s.push_back(d[i]);
		dfs(x,d[i]);
	}
	if(s.size()==0){
		v[x]=1;
		u[x]=-1;
		return;
	}
	if(s.size()>=2){
		nth_element(s.begin(),s.begin()+2,s.end(),compare);
		v[x] = v[s[0]]+v[s[1]]+1;
		//cerr<<v[s[0]]<<" "<<v[s[1]]<<endl;
		int y=*min_element(s.begin()+1,s.end(),compare2);
		u[x] = v[s[0]]+1;
		if(u[y]!=-1)
			u[x] = u[y]+v[s[0]]+1;
		if(u[s[0]]!=-1 && u[s[0]]+v[s[1]] > u[x])
			u[x] = u[s[0]]+v[s[1]]+1;
		if(s.size()>=3){
			int z=*min_element(s.begin()+2,s.end(),compare2);
			if(u[z]!=-1)
				m=max(m, u[z]+v[s[0]]+v[s[1]]+1);
			int w=*min_element(s.begin()+2,s.end(),compare);
			if(u[s[0]]!=-1)
				m=max(m, u[s[0]]+v[s[1]]+v[w]+1);
			if(u[s[1]]!=-1)
				m=max(m, v[s[0]]+u[s[1]]+v[w]+1);
		}
	}
	else{
		v[x]=1;
		u[x]=v[s[0]]+1;
	}
	//cerr<<"xx"<<v[x]<<" "<<u[x]<<" "<<s.size()<<" "<<x<<endl;
	//for(int i=0;i<s.size();i++)cerr<<s[i]<<endl;
	if(v[x]>m)
		m=v[x];
	if(u[x]+1>m && parent!=-1)
		m=u[x]+1;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		memset(h,255,sizeof h);
		for(int j=0;j<n-1;j++){
			int x,y;
			cin>>x>>y;
			d[j*2]=y;
			p[j*2]=h[x];
			h[x]=j*2;
			d[j*2+1]=x;
			p[j*2+1]=h[y];
			h[y]=j*2+1;
		}
		m=1;
		dfs(-1,1);
		cout<<"Case #"<<i<<": "<<(n-m)<<endl;
	}
	return 0;
}
