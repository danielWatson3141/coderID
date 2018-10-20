#include <bits/stdc++.h>

using namespace std;

int N, L;
bitset<40> A[200], B[200];
unordered_map<bitset<40>, int> possible;

void solve()
{
    possible.clear();
    cin>>N>>L;
    string s;
    for(int i=0; i<N; i++)
    {
        cin>>s;
        A[i].reset();
        for(int j=0; j<L; j++)
            A[i][j]=s[j]-'0';
    }
    for(int i=0; i<N; i++)
    {
        cin>>s;
        B[i].reset();
        for(int j=0; j<L; j++)
            B[i][j]=s[j]-'0';
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            possible[A[i]^B[j]]++;
    int ans=0x3f3f3f3f;
    for(auto& it: possible)
        if(it.second==N)
            ans=min(ans, (int)it.first.count());
    if(ans==0x3f3f3f3f)
        printf(" NOT POSSIBLE\n");
    else
        printf(" %d\n", ans);
}

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d:", i);
        solve();
    }
    return 0;
}
