#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
long long t,n,used[151],l;
string s[151],so[151];
int main()
{
    ifstream cin;
	cin.open("A-large.in");
	freopen("output.txt","w",stdout);
	cin>>t;
	for(int o=1; o<=t; o++)
	{
		printf("Case #%d: ",o);
		cin>>n>>l;
		int min1=41;
		for(int i=1; i<=n; i++)
        {
            cin>>s[i];
        }
        string initial="";
        for(int i=1; i<=n; i++)
        {
            cin>>so[i];
        }
        int sout=0;
        int minans=l;
        for(int i=1; i<=n; i++)
        {
            string turn="";
            for(int j=0; j<=l-1; j++)
            {
                if(s[1][j]==so[i][j]) turn+="0";
                else turn+="1";
            }
            for(int j=1; j<=n; j++) used[j]=0;
            used[i]=1;
            int u=0;
            for(int j=2; j<=n; j++)
            {
                int e=0;
                for(int p=1; p<=n; p++)
                {
                    int f=0;
                    if(used[p]==1) continue;
                    for(int q=0; q<=l-1; q++)
                    {
                        if(turn[q]=='0'&&s[j][q]!=so[p][q]) {f=1; break;}
                        if(turn[q]=='1'&&s[j][q]-'0'!=((so[p][q]-'0')^1)) {f=1; break;}
                    }
                    if(f==0) {e=1; used[p]=1; break;}
                }
                if(e==0) {u=1; break;}   //e=0 -> no solution found
            }
            if(u==0)   //all solutions found
            {
                int ans=0;
                for(int j=0; j<=l-1; j++)
                    if(turn[j]=='1') ans++;
                minans=min(minans,ans);
                sout=1;
            }
        }
        if(sout==0) printf("NOT POSSIBLE\n");
        else printf("%d\n",minans);
	}
	cin.close();
	return 0;
}
