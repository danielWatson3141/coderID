#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
vector<string> ori;
vector<string> fin;
int min(int a,int b){
	if(a<b) return a;
	else return b;
}
int n,l;
string flip(string a,string b){
	string x="";
	for(int i=0;i<l;i++){
		if(a[i]==b[i]) x+="0";
		else x+="1";
	}
	return x;
}
int onecount(string x){
	int cnt=0;
	for(int i=0;i<l;i++){
		if(x[i]=='1') cnt++;
	}
	return cnt;
}
vector<string> transform(vector<string> s,string x){
	vector<string> xx;
	for(int i=0;i<n;i++){
		xx.push_back("");
		for(int j=0;j<l;j++){
			if(s[i][j]==x[j]) xx[i]+="0";
			else xx[i]+="1";
		}
	}
	return xx;
}
bool same(vector<string> a,vector<string> b){
	for(int i=0;i<n;i++){
		bool flag=true;
		for(int j=0;j<n;j++){
			if(a[i]==b[j]){
				flag=false;
				break;
			}
		}
		if(flag) return false;
	}
	return true;
}
int main(){
	int t;
	freopen("ahard.data","rt",stdin);
	freopen("ahard.out","wt",stdout);
	scanf("%d",&t);
	for(int _=1;_<=t;_++){
		scanf("%d%d",&n,&l);
		ori.clear();
		fin.clear();
		for(int i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			ori.push_back(tmp);
		}
		for(int i=0;i<n;i++){
			string tmp;
			cin>>tmp;
			fin.push_back(tmp);
		}
		int qq=999;
		for(int i=0;i<n;i++){
			string x=flip(ori[0],fin[i]);
			if(same(transform(ori,x),fin)){
				qq=min(qq,onecount(x));
			}
		}
		printf("Case #%d: ",_);
		if(qq==999){
			printf("NOT POSSIBLE\n");
		}else{
			printf("%d\n",qq);
		}
	}
}