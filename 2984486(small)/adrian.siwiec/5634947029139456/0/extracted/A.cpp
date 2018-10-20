#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> in[200];
vector<int> out[200];
vector<int> tmp[200];
int zmiana[200];

bool porownajVector(vector<int> a, vector<int> b)
{
	int k=0;
	while(k<a.size() && a[k]==b[k])
	{
		k++;
	}
	if(k==a.size()) return 0;
	if(a[k]<b[k]) return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	int ilez;
	cin>>ilez;
	for(int aa=0; aa<ilez; aa++)
	{
		int ile; int dlugosc;
		string s;
		int wynik=1001;
		int licznik=0;
		cin>>ile>>dlugosc;
		for(int n=0; n<ile; n++)
		{
			cin>>s;
			for(int a=0; a<dlugosc; a++)
			{
				in[n].push_back(s[a]-'0');
			}
		}
		for(int n=0; n<ile; n++)
		{
			cin>>s;
			for(int a=0; a<dlugosc; a++)
			{
				out[n].push_back(s[a]-'0');
			}
		}
		
		sort(out, out+ile, porownajVector);
		
		for(int n=0; n<ile; n++)
		{
			for(int a=0; a<ile; a++)
			{
				licznik=0;
				for(int k=0; k<dlugosc; k++)
				{
					if(in[n][k]==out[a][k])
					{
						zmiana[k]=0;
					}
					else
					{
						zmiana[k]=1;
					}
				}
				
				for(int a=0; a<ile; a++)
				{
					tmp[a]=in[a];
					for(int k=0; k<dlugosc; k++)
					{
						if(zmiana[k]==1)
						{
							tmp[a][k]+=1;
							tmp[a][k]%=2;
						}
					}
				}
			
				sort(tmp, tmp+ile, porownajVector);
				int czyok=1;
				for(int a=0; a<ile; a++)
				{
					if(tmp[a]!=out[a])
						czyok=0;
				}
				if(czyok)
				{
					for(int a=0; a<dlugosc; a++)
					{
						if(zmiana[a]==1)
						{
						licznik++;
						}
					}
					wynik=min(wynik, licznik);
				}
			}			
		}
		cout<<"Case #"<<aa+1<<": ";
		if(wynik==1001)
		{
			cout<<"NOT POSSIBLE"<<endl;
		}
		else
		{
			cout<<wynik<<endl;
		}
		for(int n=0; n<ile; n++)
		{
			in[n].clear(); out[n].clear(); tmp[n].clear();
		}
	}
}
