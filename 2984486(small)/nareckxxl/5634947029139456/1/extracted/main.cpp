#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin>>t;
    for(int i=0; i<t; ++i){
        int n, l;
        cin>>n>>l;
        unsigned long long A[150], B[150];
        string T;
        for(int j=0; j<n; ++j){
            cin>>T;
            A[j]=0;
            for(int k=0; k<l; ++k){
                A[j] = 2*A[j]+(T[k]-'0');
            }
        }
        for(int j=0; j<n; ++j){
            cin>>T;
            B[j]=0;
            for(int k=0; k<l; ++k){
                B[j] = 2*B[j]+(T[k]-'0');
            }
        }
        int result = 50;
        set<unsigned long long> s1;
        for(int j=0; j<n; ++j){
            s1.insert(A[j]);
        }
        for(int j=0; j<n; ++j){
            unsigned long long delta= B[j]^A[0];
            set<unsigned long long> s2;
            for(int k=0; k<n; ++k){
                s2.insert(B[k]^delta);
            }
            if(s1==s2){
                int ans = 0;
                while(delta!=0){
                    ans+=delta%2;
                    delta/=2;
                }
                result = min(result, ans);
            }
        }
        cout<<"Case #"<<i+1<<": ";
        if(result == 50){
            cout<<"NOT POSSIBLE\n";
        } else{
            cout<<result<<"\n";
        }
    }
    return 0;
}
