#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int casos;
    cin >> casos;
    for(int caso = 1 ; caso <= casos ; caso++){

        int n, l;
        cin >> n >> l ;
        string out[n];
        for(int i = 0 ; i < n ; i++){
            cin >> out[i];
        }

        string flow[n];
        for(int i = 0 ; i < n ; i++){
            cin >> flow[i];
        }

        int a[n];
        for(int i = 0 ; i < n ; i++){
            a[i] = i;
        }
        bool can;
        int ans = INF;
        do {
            int cont = 0;
            for(int j = 0 ; j < l ; j++){
                int match = 0;
                //compare out[i] with flow[a[i]]
                for(int i = 0 ; i < n ; i++){
                    if(out[i][j] == flow[a[i]][j]){
                        match++;
                    }
                }
                if(match == 0){
                    cont++;
                } else if(match != n){
                    cont = INF;
                    break;
                }
            }
            ans = min(ans,cont);
        } while(next_permutation(a,a+n));
        cout << "Case #"<<caso<<": " ;
        if(ans == INF){
            cout << "NOT POSSIBLE" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
