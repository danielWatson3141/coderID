#include <iostream>
#include <vector>
using namespace std;


vector<int> G[2000];
int iledzieci[2000];
int suma[2000];
int drzewowy[2000];

void dfs(int n, int ojciec);

int main()
{
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		int V, E;
		int tmpa, tmpb;
		cin>>V;
		E=V-1;
		for(int n=0; n<E; n++)
		{
			cin>>tmpa>>tmpb;
			tmpa--;
			tmpb--;
			iledzieci[tmpa]++; iledzieci[tmpb]++;
			G[tmpa].push_back(tmpb);
			G[tmpb].push_back(tmpa);
		}
		int wynik=2000;
		for(int korzen=0; korzen<V; korzen++)
		{
//			for(int n=0; n<V; n++)
//			{
//				drzewowy[n]=suma[n]=2001;
//			}
			dfs(korzen, korzen);
			wynik=min(wynik, drzewowy[korzen]);
			wynik=min(wynik, suma[korzen]);
		}
		cout<<"Case #"<<aa+1<<": "<<wynik<<endl;
		for(int n=0; n<V; n++)
		{
			G[n].clear();
			iledzieci[n]=suma[n]=drzewowy[n]=0;
		}
	}
}
void dfs(int n, int ojciec)
{
	suma[n]=drzewowy[n]=0;
	if(n==ojciec)
	{
		for(int a=0; a<G[n].size(); a++)
		{
			dfs(G[n][a], n);
			suma[n]+=suma[G[n][a]];
		}
		if(iledzieci[n]>=2)
		{
			int maks=0, maks2=0;
			for(int a=0; a<G[n].size(); a++)
			{
				int tmp=suma[G[n][a]]-drzewowy[G[n][a]];
				if(tmp>maks)
				{
					maks2=maks;
					maks=tmp;
				}
				else if(tmp>maks2)
				{
					maks2=tmp;
				}
			}
			drzewowy[n]=suma[n]-maks-maks2;
		}
		else
		{
			drzewowy[n]=suma[n];
		}
	}
	else
	{
		if(iledzieci[n]==1)
		{
			suma[n]=1;
			drzewowy[n]=0;
		}
		else 
		{
			for(int a=0; a<G[n].size(); a++)
			{
				if(G[n][a]==ojciec) continue;
				dfs(G[n][a], n);
				suma[n]+=suma[G[n][a]];
			}
			suma[n]++;
			if(iledzieci[n]==2)
			{
				drzewowy[n]=suma[n]-1;
			}
			else
			{
				int maks=0, maks2=0;
				for(int a=0; a<G[n].size(); a++)
				{
					if(G[n][a]==ojciec) continue;
					int tmp=suma[G[n][a]]-drzewowy[G[n][a]];
					if(tmp>maks)
					{
						maks2=maks;
						maks=tmp;
					}
					else if(tmp>maks2)
					{
						maks2=tmp;
					}
				}
				drzewowy[n]=suma[n]-maks-maks2-1;			//not sure 'bout -1
			}
		}
	}
}
