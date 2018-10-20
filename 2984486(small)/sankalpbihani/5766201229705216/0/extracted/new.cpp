#include<bits/stdc++.h>

using namespace std;

typedef long long L;

int check(vector<vector<int> > g,int n) {
    int cnt, cnt2=0, cnt3=0, cnt4=0;

    for(int i=1; i<=n; i++) {
        cnt=0;
        for(int j=1; j<=n; j++) {
            cnt += g[i][j];
        }

        if(!(cnt==2 || cnt==3 || cnt==0 || cnt==4|| cnt==1)) return -1;

        if(cnt>0) {
            cnt2++;
            if(cnt==2) {
                cnt3++;
            }
            if(cnt==1)
                cnt4++;
        }
    }

    if(cnt2==1 and cnt4==1) return 0;
    if(cnt2==0) return 0;

    if(cnt2%2==0)   return -1;

    if((cnt2+1)/2 == cnt3 and cnt4==0)  return 0;

    return -1;
}

int func(vector<vector<int> > g,int n, int k=1) {
    if(k>n) return check(g, n);
    else {
        int x, tmp;

        x = func(g, n, k+1);

        for(int i=1; i<=n; i++) {
            g[i][k] = g[k][i] = 0;
        }

        tmp = func(g, n, k+1);

        if(x>=0 and tmp>=0) x=min(x,tmp+1);
        else if(x<0 and tmp>=0) x=tmp+1;

        return x;
    }
}

int main()
{
/*
    #ifndef ONLINE_JUDGE
        freopen("int.txt","r",stdin);
    #endif // ONLINE_JUDGE
*/
    ios_base::sync_with_stdio(false);

    int T;
    int n;

    vector<vector<int> > g;

    cin>>T;

    for(int t=1; t<=T; t++) {
        g.clear();
        cin>>n;

        g.resize(n+1);

        for(int i=0; i<=n; i++) {
            g[i].resize(n+1);
            for(int j=0; j<=n; j++) {
                g[i][j]=0;
            }
            g[i][i] = 1;
        }

        int t1,t2;

        for(int i=0; i<n-1; i++) {
            cin>>t1>>t2;
            g[t1][t2] = g[t2][t1] = 1;
        }
/*
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
*/
        int ans=func(g,n);

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }

    return 0;
}
