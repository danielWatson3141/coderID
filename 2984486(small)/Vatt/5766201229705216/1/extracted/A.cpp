#include <stdio.h>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> save[1005];
vector<int> save_all[1005];
vector<int> save_bi[1005];
int t,n,aa,bb;

int nub_all(int h1,int h2)
{
	//printf("ALL %d %d %d\n",h1,h2,save[h1][h2]);
	if(save_all[h1][h2]!=-1) return save_all[h1][h2];
	save_all[h1][h2]=1;
	int child = save[h1][h2];
	//printf("CHILD %d\n",child);
	for(int i=0;i<save[child].size();i++)
	{
		if(save[child][i]!=h1)
		{
			save_all[h1][h2]+=nub_all(child,i);
		}
	}
	//printf("SAVE_ALL %d %d %d\n",h1,child,save_all[h1][h2]);
	return save_all[h1][h2];
}

int nub_bi(int h1,int h2)
{
	//printf("BI %d %d %d ",h1,h2,save[h1][h2]);
	if(save_bi[h1][h2]!=-1) return save_bi[h1][h2];
	save_bi[h1][h2]=0;
	int child = save[h1][h2];
	int cnt = 0;
	for(int i=0;i<save[child].size();i++)
	{
		if(save[child][i]!=h1 && save[child][i]!=0)
		{
			cnt++;
		}
	}
	//printf("COUNT %d\n",cnt);
	if(cnt==0) return 0;
	if(cnt==1)
	{
		for(int i=0;i<save[child].size();i++)
		{
			if(save[child][i]!=h1)
			{
				save_bi[h1][h2]=nub_all(child,i);
			}
		}
		//printf("SAVE_BI %d %d %d\n",h1,child,save_bi[h1][h2]);
		return save_bi[h1][h2];
	}
	int maxx1 = -1;
	int maxx2 = -1;
	int summ=0;
	for(int i=0;i<save[child].size();i++)
	{
		if(save[child][i]!=h1)
		{
			int cal = nub_all(child,i);
			summ+=cal;
			cal -= nub_bi(child,i);

			if(cal>maxx1) 
			{
				maxx2=maxx1;
				maxx1=cal;
			}
			else if(cal>maxx2)
			{
				maxx2=cal;
			}
		}
	}
	save_bi[h1][h2]=summ-maxx1-maxx2;
	//printf("SAVE_BI %d %d %d\n",h1,child,save_bi[h1][h2]);
	return save_bi[h1][h2];
}
int main(int argc, char *argv[])
{
	scanf("%d",&t);
	for(int rr=1;rr<=t;rr++)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&aa,&bb);
			save[aa].push_back(bb);
			save[bb].push_back(aa);
			save_all[aa].push_back(-1);
			save_all[bb].push_back(-1);
			save_bi[aa].push_back(-1);
			save_bi[bb].push_back(-1);
		}
		for(int i=1;i<=n;i++)
		{
			save[0].push_back(i);
			save_bi[0].push_back(-1);
		}
		int ans=n+5;
		int p =-1;
		for(int i=0;i<save[0].size();i++)
		{
			/*if(nub_bi(0,i)<ans)
			{
				ans=nub_bi(0,i);
				p=save[0][i];
			}*/
			ans = min(ans,nub_bi(0,i));
		}
		//printf("%d\n",p);
		printf("Case #%d: %d\n",rr,ans);
		for(int i=0;i<=n;i++)
		{
			save[i].clear();
			save_all[i].clear();
			save_bi[i].clear();
		}
	}
	return 0;
}
