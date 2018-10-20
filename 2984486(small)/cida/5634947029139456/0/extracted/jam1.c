#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
long long  int i,j,k=0,l,y=0,n,t,s=0,x,v=0;
cin>>t;
int solve=0;
while(t--)
{
	cin>>n>>l;solve++;
	int ini[l];
	for(i=0;i<l;i++)
    ini[i]=0;
	vector<string>str,str1,strb,strc;
	string suraj;
	for(i=0;i<n;i++){
   		cin>>suraj;
		str.push_back(suraj);
	}
	for(j=0;j<n;j++){
   		cin>>suraj; 
   		strc.push_back(suraj);
   	}
		sort(str.begin(),str.end());
		sort(strc.begin(),strc.end());
		cout<<"Case #"<<solve<<": ";
		for(k=0;k<=l;k++){
			vector<string>c=str,d=strc;
			v=0;x=0;
			for(y=0;y<str.size();y++){
				for(j=0;j<strc.size();j++){s=0;
					for(i=0;i<l and d[j]!="";i++){
						if(c[y][i]!=d[j][i]){
						s++;
					}
				}
					if(s==k){
						c[y]="";d[j]="";x++;
						break;
					}	
				}
				if(s!=k){
					break;
				}
			}
			if(x==n)
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
