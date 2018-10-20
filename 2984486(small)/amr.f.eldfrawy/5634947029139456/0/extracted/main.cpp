/*
ID: amr.f.eldfrawy
LANG: C++
*/
#include <fstream>
#include <string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<math.h>
#define INF 1000000
#define MOD  1000000007
#define MAX 100000
using namespace std;
vector<string> arr1,arr2;
string str;
bool same(vector<string>t)
{
    for (int i=0;i<t.size();i++)
        if(t[i]!=arr2[i])
            return 0;
    return 1;
}
int main()
{
    freopen("S.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t;
    int  g= 1;
    scanf("%d",&t);
    while(t--)
    {
        int n , l ;
        int ans =INF;
        scanf("%d %d",&n,&l);
        for (int i=0; i<n; i++)
        {
            cin >> str;
            arr1.push_back(str);
        }
        for (int i=0; i<n; i++)
        {
            cin >> str;
            arr2.push_back(str);
        }
        sort(arr2.begin(),arr2.end());
        for (int i=0; i<(1<<l); i++)
        {
            vector<string>temp =arr1;
            int cost=0;
            for (int j=0; j<l; j++)
            {
                if(i &(1<<j))
                {
                    cost++;
                    for (int k=0; k<n; k++)
                    {
                        if(temp[k][j]=='1')
                            temp[k][j]='0';
                                else
                                temp[k][j]='1';
                    }
                }
            }
            sort(temp.begin(),temp.end());
            if(same(temp))
               ans = min(ans , cost);


        }
        printf("Case #%d: ",g++);
        if(ans==INF)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",ans);

            arr1.clear();
            arr2.clear();

    }
}
