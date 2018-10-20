#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    int N, L, T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++ ){
        scanf("%d %d", &N, &L );
        vector<string>X, Y;
        string x;
        for(int i = 0; i < N; i++){
            cin>>x;
            X.push_back(x);
        }
        for(int i = 0; i < N; i++){
            cin>>x;
            Y.push_back(x);
        }

        int ans = -1;
        for(int mask = 0; mask < (1<<L); mask++ ){
            vector<string>Z = X;
            int moves = 0;
            for(int i = 0; i < L; i++ ){
                if( mask & (1<<i)){
                    moves++;
                    for(int j = 0; j <N; j++ ){
                        if(Z[j][i] == '1')Z[j][i] = '0';
                        else Z[j][i] = '1';
                    }
                }
            }
/*
            for(int i=0;i<N;i++)cout<<X[i]<<" ";puts("");
            for(int i=0;i<N;i++)cout<<Z[i]<<" ";puts("");
            for(int i=0;i<N;i++)cout<<Y[i]<<" ";puts("");puts("");
*/
            int used[12] = {0}, ok = 1;
            for(int i = 0; i < N; i++ ){
                int found = 0;
                for(int j = 0; j< N; j++){
                    if(!used[j] && (Z[j] == Y[i])){
                        found = 1;
                        used[j] = 1;
                        break;
                    }
                }
                if(!found){
                    ok=0;
                    break;
                }
            }
            if(ok){
                if(ans == -1)ans = moves;
                else ans = min(ans, moves);
            }
        }
        printf("Case #%d: ", t);
        if(ans == -1)cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
