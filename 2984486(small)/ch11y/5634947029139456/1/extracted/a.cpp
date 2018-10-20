#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <vector> 
#include <cstdio>
#include <stack>
#include <cassert>
#include <sstream>
using namespace std;  


int main (){
    freopen("a.in","r", stdin); 
    freopen("a.out","w",stdout); 
    int T ; 
    cin >> T; 
    for(int Cas = 1; Cas <= T ; ++Cas){ 
        int N, L;
        cin >> N >> L; 
        vector< string > x(N),y(N);  
        for(int i = 0 ; i < N; ++i)
            cin >> x[i]; 
        for(int i = 0 ; i < N; ++i)
            cin >> y[i];
        sort(y.begin(), y.end());  
        int ans = 0x3f3f3f3f; 
        for(int i = 0 ; i < N; ++i){ 
            vector< string > z(N); 
            for(int j = 0 ; j < N ; ++j){
                string cur = ""; 
                for(int k =  0 ; k < L ; ++k){ 
                    if(y[0][k] == x[i][k]){
                        cur += x[j][k];
                    }else{
                        if(x[j][k]=='0') cur += '1';
                        else cur +='0'; 
                    }
                }
                z[j]=cur;
            } 
            sort(z.begin(),z.end()); 
            int cnt = 0 ; 
            for(int j  = 0 ; j < L ; ++j)
                cnt += (y[0][j] != x[i][j]);  
            for(int j = 0 ; j < N ; ++j)
                if(z[j] != y[j])
                    cnt = 0x3f3f3f3f;
            ans = min(ans,cnt); 
        }
        cout <<"Case #"<<Cas<<": "; 
        if( ans==0x3f3f3f3f) cout << "NOT POSSIBLE"<<endl;
        else cout <<ans<<endl; 
    }
    return 0;
}

            

