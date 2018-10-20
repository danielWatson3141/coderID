#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

#define MAXN 1005

using namespace std;

int vis[MAXN][MAXN];
int DP[MAXN][MAXN];
vector <int> aristas[MAXN];
int cont;

int busca(int nodo, int padre){
    if(vis[nodo][padre] == cont)
        return DP[nodo][padre];
    vis[nodo][padre] = cont;
    if(aristas[nodo].size() == 1)
        return DP[nodo][padre] = 0;
    if(padre != 0 && aristas[nodo].size() == 2)
        return DP[nodo][padre] = 0;
    int resp = 0;
    for(int i = 0; i < aristas[nodo].size(); i++){
        if(aristas[nodo][i] != padre){
            for(int j = i + 1; j < aristas[nodo].size(); j++){
                if(aristas[nodo][j] != padre)
                    resp = max(resp, busca(aristas[nodo][i], nodo) + busca(aristas[nodo][j], nodo) );
            }
        }
    }
    return DP[nodo][padre] = resp + 2;

}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        cont++;
        printf("Case #%d: ", t);
        int N;
        scanf("%d", &N);
        for(int i = 1; i < N; i++){
            int a, b;
            scanf("%d%d", &a, &b);
            aristas[a].push_back(b);
            aristas[b].push_back(a);
        }
        int answer = 0;
        for(int i = 1; i <= N; i++)
            answer = max(answer, busca(i, 0));
        printf("%d\n", N - answer - 1);
        cont++;
        for(int i = 0; i <= N; i++)
            aristas[i].clear();
    }
    return 0;
}
