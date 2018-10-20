#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mk make_pair
#define all(x,n) x+0,x+n


template<class T>
int toInt(T t){stringstream ss;ss<<t;int r;ss>>r;return r;}
template<class T>
string toStr(T t){stringstream ss;ss<<t;string r;ss>>r;return r;}



int l,n;

int main(){
    int nn,nc=0;cin>>nn;
    while(nn--){
        cin>>n>>l;
        string tmp;
        vector<string> mat,goal,t;
        for(int i=0;i<n;i++){
            cin>>tmp;
            mat.pb(tmp);
        }
        for(int i=0;i<n;i++){
            cin>>tmp;
            goal.pb(tmp);
        }
        int sol = INT_MAX;
        sort(goal.begin(),goal.end());
        for(int mask = 0;mask<(1<<l);mask++){
            t = mat;
            vector<bool> mod;
            for(int j=0;j<l;j++){
                int m2 = 1<<j;
                if(mask&m2){
                    for(int k = 0;k<n;k++){
                        if(t[k][j]=='0'){t[k][j]='1';}
                        else{t[k][j]='0';}
                    }
                }
            }

            sort(t.begin(),t.end());
            if(t==goal){
                sol = min(sol,__builtin_popcount(mask));
            }
        }
        cout<<"Case #"<<++nc<<": ";
        if(sol!= INT_MAX){
            cout<<sol<<endl;
        }else{
            cout<<"NOT POSSIBLE"<<endl;
        }
    }

}
