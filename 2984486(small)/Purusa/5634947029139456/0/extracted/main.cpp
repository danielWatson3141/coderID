#include <bits/stdc++.h>

using namespace std;

int N, L;
bitset<40> A[200], B[200];

void solve()
{
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
    auto comp=[](bitset<40> a, bitset<40> b){
         for(int i=0; i<40; i++)
            if(a[i]!=b[i])
                return a[i]<b[i];
         return false;
         };
    sort(A, A+N, comp);
    int ans=0x3f3f3f3f;
    do
    {
        bitset<40> x=A[0]^B[0];
        for(int i=1; i<N; i++)
            if((A[i]^B[i])!=x)
                goto next;
        ans=min(ans, (int)x.count());
        next:;
    }
    while(next_permutation(A, A+N, comp));
    if(ans==0x3f3f3f3f)
        printf(" NOT POSSIBLE\n");
    else
        printf(" %d\n", ans);
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    //freopen("A-large.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d:", i);
        solve();
    }
    return 0;
}
