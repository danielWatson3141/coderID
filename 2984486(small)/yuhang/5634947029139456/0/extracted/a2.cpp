#include<iostream>
#include<cstring>
using namespace std;

int n,l;
int s[150];
int v[1024];
int current;

int readbin(){
	int r=0;
	char ch;
	do
		cin.get(ch);
	while(ch!='0' && ch!='1');
	while(ch=='0' || ch=='1'){
		r=r*2+(ch-'0');
		cin.get(ch);
	}
	return r;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		memset(v,0,sizeof v);
		current=1;
		cin>>n>>l;
		for(int i=0;i<n;i++)
			s[i]=readbin();
		for(int i=0;i<n;i++)
			v[readbin()]=current;
		
		int m=100000;
		for(int i=0,b=0;i<(1<<l);i++){
			if(i!=0)
				b += 1-__builtin_ctz(i);
			if(b>=m)
				continue;
			bool f=true;
			for(int j=0;j<n;j++)
				if(! v[s[j] ^ i]){
					f=false;
					break;
				}
			if(f)
				m=b;
		}
		cout<<"Case #"<<i<<": ";
		if(m==100000)
			cout<<"NOT POSSIBLE"<<endl;
		else
			cout<<m<<endl;
	}
	return 0;
}
