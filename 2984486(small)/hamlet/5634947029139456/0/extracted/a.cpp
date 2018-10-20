#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int tc;
    cin>>tc;
    
    for(int caso=1;caso<=tc;caso++){
        cout<<"Case #"<<caso<<": ";
        int N,L;
        cin>>N>>L;
        string a[N];
        for(int i=0;i<N;i++)cin>>a[i];
        string b[N];
        for(int i=0;i<N;i++)cin>>b[i];
        sort(b,b+N);
        int mini=1<<30;
        
        for(int i=0;i<N;i++){
            string a2[N];
            for(int j=0;j<N;j++)a2[j]=a[j];
            int cont=0;
            for(int j=0;j<L;j++){
                if(a2[0][j]!=b[i][j]){
                    cont++;
                    for(int k=0;k<N;k++){
                        if(a2[k][j]=='0')a2[k][j]='1';
                        else a2[k][j]='0';
                    }        
                }    
            }
            
            sort(a2,a2+N);
            
            bool ok=1;
            for(int j=0;j<N;j++)
                if(a2[j]!=b[j]){
                    ok=0;
                    break;
                }
                
            if(ok)mini=min(mini,cont);
        }
        
        if(mini==(1<<30))cout<<"NOT POSSIBLE"<<endl;
        else cout<<mini<<endl;
    }
    
    
    return 0;
}
