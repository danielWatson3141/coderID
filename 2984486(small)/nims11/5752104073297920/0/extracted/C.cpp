/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<stack>
#include<set>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int N;
int arr[1100];
vector<pair<int, int> > res;
int main()
{
    int z = 0;
    in_T{
        z++;
        in_I(N);
        int x = 0;
        for(int i = 0;i<N;i++)
        {
            in_I(arr[i]);
            x += (arr[i]<i);
        }
        res.push_back(make_pair(x, z));
    }
    sort(res.begin(), res.end());
    int ans[res.size()+1];
    for(int i = 0;i<res.size()/2;i++){
        ans[res[i].second] = '0';
    }
    for(int i = res.size()/2;i<res.size();i++){
        ans[res[i].second] = '1';
    }
    for(int i = 1;i<=res.size();i++)
    {
        cout<<"Case #"<<i<<": "<<(ans[i]=='1'?"GOOD":"BAD")<<endl;
    }
}
