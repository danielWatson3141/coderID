#include <bits/stdc++.h>
#define N 1111
using namespace std;

string start[N] , goal[N] , copia[N];
int main(){
    freopen("in.c","r",stdin);
    freopen("salida.cpp","w",stdout);


    int tc , n , L , nc = 1;
    cin >> tc;

    while(tc--){

        cin >> n >> L;

        for(int i = 0; i <  n; ++i)
            cin >> start[i];
        for(int i = 0; i < n; ++i)
            cin >> goal[i];

        int ans = -1;
        for(int i = 0; i < n; ++i){
            for(int k = 0; k < n; ++k)
                copia[k] = start[k];

            int costo = 0;
            for(int k = 0; k < L; ++k)
            {   if(goal[0][k] == start[i][k]) continue;

                costo++;
                for(int c = 0; c < n; ++c)
                {   if(copia[c][k] == '0') copia[c][k] = '1';
                    else copia[c][k] = '0';
                }
            }

            set<string> s;
            for(int k = 0; k < n; ++k) s.insert(copia[k]);

            bool valid = 1;
            for(int k = 0; k < n; ++k)
                if(s.find(goal[k]) == s.end()) valid = 0;


            if(valid)
            if(ans == -1 || costo < ans)
            ans = costo;
        }

        printf("Case #%d: ",nc++);
        if(ans == -1) puts("NOT POSSIBLE");
        else cout<<ans<<endl;

    }







    return 0;
}
