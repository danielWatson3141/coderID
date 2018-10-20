#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
long long  int i,j,k=0,l,m=0,n,t,s=0,k1,k2=0;
cin>>t;
int ca=0;
while(t--)
{
	cin>>n>>l;ca++;
	int see[l];
	for(i=0;i<l;i++)
    see[i]=0;
	vector<string>a,a1,b1,b;
	string z;
	for(i=0;i<n;i++){
   		cin>>z;
		a.push_back(z);
	}
	for(j=0;j<n;j++){
   		cin>>z; 
   		b.push_back(z);
   	}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		cout<<"Case #"<<ca<<": ";
		for(k=0;k<=l;k++){
			vector<string>c=a,d=b;
			k2=0;k1=0;
			for(m=0;m<a.size();m++){
				for(j=0;j<b.size();j++){s=0;
					for(i=0;i<l and d[j]!="";i++){
						if(c[m][i]!=d[j][i]){
						s++;
					}
				}
					if(s==k){
						c[m]="";d[j]="";k1++;
						break;
					}	
				}
				if(s!=k){
					break;
				}
			}
			if(k1==n)
      		break;
		}   
		if(k>l){
			cout<<"NOT POSSIBLE\n";
		}
		else{
			cout<<k<<'\n';
		}
	}
	return 0;
}
