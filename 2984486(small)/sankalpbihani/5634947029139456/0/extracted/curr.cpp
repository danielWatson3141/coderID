#include<bits/stdc++.h>

using namespace std;

typedef long long L;

int T, n, l;
vector<int> n1, n2;

int check(vector<string> s1, vector<string> s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0; i<n; i++) {
        if(s1[i].compare(s2[i])!=0) {
            return -1;
        }
    }

    return 0;
}

int func(vector<string> s1, vector<string> s2, int k=0) {
    if (k==l) {
        return check(s1,s2);
    } else {
        int x,tmp;

        if(n1[k]==n2[k]) {
            x = func(s1,s2,k+1);
            if((n1[k]==(n/2)) and ((n%2)==0)) {

                for(int i=0; i<n; i++) {
                    s1[i][k] = '0' + '1' - s1[i][k];
                }
                tmp = func(s1,s2,k+1);

                if(tmp>=0 and x>=0)   x=min(tmp+1,x);
                else if(tmp>=0 and x<0)    x = tmp+1;
            }
        } else if(n1[k]+n2[k]==n) {
            x=-1;
            for(int i=0; i<n; i++) {
                s1[i][k] = '0' + '1' - s1[i][k];
            }
            tmp = func(s1,s2,k+1);
            if(tmp>=0)   x=tmp+1;
        } else {
            x=-1;
        }

        return x;
    }
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("int.txt","r",stdin);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);



    cin>>T;

    for(int t=1; t<=T; t++) {
        cin>>n>>l;

        vector<string> s1,s2;

        s1.clear();
        s2.clear();
        n1.clear();
        n2.clear();

        s1.resize(n);
        s2.resize(n);

        for(int i=0; i<n; i++)  cin>>s1[i];
        for(int i=0; i<n; i++)  cin>>s2[i];

        n1.resize(l);
        n2.resize(l);

        for(int j=0; j<l; j++) {
            n1[j]=0;
            n2[j]=0;
            for(int i=0; i<n; i++) {
                n1[j] += s1[i][j] - '0';
                n2[j] += s2[i][j] - '0';
            }
        }

        int ans = func(s1,s2);

        if(ans<0) {
            cout<<"Case #"<<t<<": NOT POSSIBLE"<<endl;
        } else {
            cout<<"Case #"<<t<<": "<<ans<<endl;
        }
    }

    return 0;
}
