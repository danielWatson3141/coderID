/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int n,l;
char ol[160][50],dv[160][50],ol2[160][50];

int solve(int cc){
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++)
    {
        scanf("%s",ol[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",dv[i]);
    }
    vector<long long> vdv;
    for(int i=0;i<n;i++)
    {
        long long ll=0;
        for(int j=0;j<l;j++)
        {
            if(dv[i][j]=='1')
                ll+=(1LL<<j);
        }
        vdv.push_back(ll);
    }
    sort(vdv.begin(),vdv.end());
    int sol=l+1;
    for(int i=0;i<n;i++)
    {
        int tmpsol=0;
        for(int j=0;j<n;j++)
            strcpy(ol2[j],ol[j]);
        for(int j=0;j<l;j++)
        {
            if(ol[0][j]!=dv[i][j])
            {
                for(int k=0;k<n;k++)
                {
                    if(ol2[k][j]=='1') ol2[k][j]='0';
                    else ol2[k][j]='1';
                }
                tmpsol++;
            }
        }
        vector<long long> vol;
        for(int i=0;i<n;i++)
        {
            long long ll=0;
            for(int j=0;j<l;j++)
            {
                if(ol2[i][j]=='1')
                    ll+=(1LL<<j);
            }
            vol.push_back(ll);
        }
        sort(vol.begin(),vol.end());
        for(int j=0;j<n;j++)
        {
            if(vdv[j]!=vol[j]) break;
            if(j==n-1)
            {
                sol=min(sol,tmpsol);
//                printf("%d - %d\n",i,tmpsol);
            }
        }
    }
    printf("Case #%d: ",cc);
    if(sol==l+1) printf("NOT POSSIBLE\n");
    else printf("%d\n",sol);
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        solve(i);

	return 0;
}
