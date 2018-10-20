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
        for(int i = 0; i < N; i++ ){
            vector<string> Z = X;
            int moves = 0;
            for(int j = 0; j < L ; j++){
                if( Y[0][j] == Z[i][j] )continue;
                moves++;
                for(int k = 0; k < N; k++ ){
                    if(Z[k][j] == '1')Z[k][j] = '0';
                    else Z[k][j] = '1';
                }
            }

            //puts("");for(int i=0;i<N;i++)cout<<Z[i]<<" ";puts("");for(int i=0;i<N;i++)cout<<Y[i]<<" ";puts("");

            int ok = 1, used[152] = {0};
            for(int j = 0; j < N; j++){
                int found = 0;
                for(int k = 0; k < N; k++){
                    if(!used[k] && (Z[k] == Y[j])  ){
                        found = 1;
                        used[k] = 1;
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
                else ans = min (ans, moves);
            }
        }
        printf("Case #%d: ", t);
        if(ans == -1)printf("NOT POSSIBLE\n");
        else printf("%d\n", ans);
    }
    return 0;
}
