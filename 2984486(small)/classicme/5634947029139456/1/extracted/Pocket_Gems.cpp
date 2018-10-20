#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int main() {
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t;
    int ka=0;
    cin>>t;
    while(ka!=t) {
        ka++;
        int N,L;
        cin>>N>>L;
        string from[N],to[N];
        for(int i=0; i<N; i++)
            cin>>from[i];
        for(int j=0; j<N; j++)
            cin>>to[j];
        map<string,int> calc;
        for(int i=0; i<N; i++) {
            if(calc[to[i]]==0)
                calc[to[i]]=1;
            else
                calc[to[i]]+=1;
        }
        int ans=1000000;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                bool trans[L];
                memset(trans,0,sizeof(trans));
                map<string,int> vala;
                vala.insert(calc.begin(),calc.end());
                int count=0;
                for(int m=0; m<L; m++)
                    if(from[i][m]!=to[j][m]) {
                        trans[m]=1;
                        count++;
                    }
                //cout<<trans[0]<<" "<<trans[1]<<" "<<N<<endl;
                bool ya=true;
                for(int k=0; k<N; k++) {
                    string val="";
                    for(int f=0; f<L; f++) {
                        if(trans[f]==1) {
                            if(from[k][f]=='0')
                                val+="1";
                            else
                                val+="0";
                        } else {
                            val+=from[k][f];
                        }
                    }
                    //cout<<val<<" ";
                    if(vala[val]!=0)
                        vala[val]-=1;
                    else if(vala[val]==0) {
                        ya=false;
                        break;
                    }
                }
               // cout<<count<<" "<<endl;
                if(ya)
                    ans=min(ans,count);
            }
            //cout<<endl;
        }
        if(ans==1000000) {
            cout<<"Case #"<<ka<<": NOT POSSIBLE"<<endl;
        } else
            cout<<"Case #"<<ka<<": "<<ans<<endl;
    }
}
