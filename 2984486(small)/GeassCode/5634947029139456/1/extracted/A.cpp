#include<stdio.h>
#include<string.h>
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm> 
using namespace std;
#define maxn 160
#define maxm 45
#define LL long long 
map<LL,int>mp1,mp2;

string nb1[maxn],nb2[maxn];
LL a[maxn],b[maxn];
int cnt1[maxm],cnt2[maxm];
int n,m;
LL get_nb(string s)
{
	LL sum=0;
	for(int i=0;i<s.length();i++){
		sum=sum*2+(s[i]-'0');
	}
	return sum;
}
int check(LL k,int dep)
{
//	cout<<k<<" "<<dep<<endl;
	int i;
	LL j=(1<<(dep+1))-1;
	mp1.clear();mp2.clear();
	for(i=1;i<=n;i++){
		mp1[b[i]&j]++;
		mp2[(a[i]&j)^k]++;
	}
	for(i=1;i<=n;i++){
	//	cout<<i<<" "<<(b[i]&j)<<" "<<mp1[b[i]&j]<<" "<<mp2[b[i]&j]<<endl;
		if(mp1[b[i]&j]==mp2[b[i]&j])continue;
		return 0;
	}
	return 1;
}
int main()
{
	freopen("A-large4.in","r",stdin);
	freopen("A-large4.out","w",stdout);
	int t,cas;
	int i,j,k;
	vector<LL>opt;
	scanf("%d",&t);
	for(cas=1;cas<=t;cas++){
		//printf("cas%d:\n",cas);
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			cin>>nb1[i];
			a[i]=get_nb(nb1[i]);
		}
		for(i=1;i<=n;i++){
			cin>>nb2[i];
			b[i]=get_nb(nb2[i]);
		}
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(i=1;i<=n;i++){
			for(j=m-1;j>=0;j--){
				cnt1[m-j-1]+=nb1[i][j]-'0';
				cnt2[m-j-1]+=nb2[i][j]-'0';
			}
		}
		opt.clear();
	/*	for(i=0;i<m;i++){
			if(cnt1[i]!=cnt2[i]&&(n-cnt1[i])==cnt2[i])k+=1<<i;
			else if(cnt1[i]==cnt2[i]&&(n-cnt1[i])!=cnt2[i])k+=1<<i;
		}
		opt.push_back(k);*/
		int dep=0;
		vector<int>ad,opt2;
		opt.push_back(0);
		while(dep<m){
	//		printf("&&&&%d:\n",dep);
			if(cnt1[dep]==cnt2[dep]&&(cnt1[dep]==0||cnt1[dep]==n)){
				dep++;
				continue;
			}
			ad.clear();
			if(cnt1[dep]==cnt2[dep])ad.push_back(0);
			if(n-cnt1[dep]==cnt2[dep])ad.push_back(1);
	//		printf("&&&&%d:\n",dep);
			if(ad.size()==0)break;
	/*		printf("%d: ",dep);
			for(i=0;i<opt.size();i++){
				printf("%d ",opt[i]);
			}
			printf("\n");*/
			opt2.clear();
		
			for(i=0;i<opt.size();i++){
				for(j=0;j<ad.size();j++){
					if(check(opt[i]+(1<<dep)*ad[j],dep))
						opt2.push_back(opt[i]+(1<<dep)*ad[j]);
				}
			}
			opt.clear();
			for(i=0;i<opt2.size();i++){
				opt.push_back(opt2[i]);
			}
			if(opt.size()==0)break;
			dep++;
		}
		int res=-1;
		if(dep>=m){
			res=m;
			if(opt.size()==0)res=0;
			for(j=0;j<opt.size()&&res>0;j++){
				k=0;
	//			printf("****%d\n",opt[j]);
				for(i=0;i<m;i++){
					if(opt[j]&(1<<i))k++;
				}
				res=min(res,k);
			}
		}
		if(res>=0)
			printf("Case #%d: %d\n",cas,res);
		else printf("Case #%d: NOT POSSIBLE\n",cas);
	}
	return 0;
}
			
			
