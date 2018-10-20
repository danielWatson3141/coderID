#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#define MAXN 1005

using namespace std;

char cadena[10000];
int contador[10000];
int contador2[10000];
int vis[10000];
char entrada1[1000][1000];
char entrada2[1000][1000];
int N, M;
map<long long int, long long int> cubeta;
bool checa(int x){
    for(int i = 1; i <= N; i++){
        long long int num = 0;
        for(int j = 0; j <= x; j++){
            long long int a = entrada1[i][j] - '0';
            if(vis[j])
                a ^= 1ll;
            num *= 2ll;
            num += a;
        }
        cubeta[num]++;
    }
    for(int i = 1; i <= N; i++){
        long long int num = 0;
        for(int j = 0; j <=x ; j++){
            long long int a = entrada2[i][j] - '0';
            num *= 2ll;
            num += a;
        }
        //printf("%lld %lld\n", cubeta[num], num);
        if(cubeta[num] == 0)
            return false;
        cubeta[num]--;
    }
    return true;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        scanf("%d%d", &N, &M);
        for(int i = 1; i <= N; i++){
            scanf(" %s", entrada1[i]);
            for(int j = 0; entrada1[i][j]; j++){
                if(entrada1[i][j] == '1')
                    contador[j]++;
            }
        }
        for(int i = 1; i <= N; i++){
            scanf("%s", entrada2[i]);
            for(int j = 0; entrada2[i][j]; j++){
                if(entrada2[i][j] == '1')
                    contador2[j]++;
            }
        }
        bool chosto = true;
        int answer = 0;
        for(int i = 0; i < M; i++){
            if(!checa(i)){
                answer++;
                vis[i] = 1;
                cubeta.clear();
                if(!checa(i)) chosto = false;
            }
            cubeta.clear();
        }
        if(chosto)
        printf("%d\n", answer);
        else puts("NOT POSSIBLE");
        for(int i = 0; i <= M; i++)
            contador[i] = contador2[i] = vis[i] = 0;
        for(int i = 0; i <= N; i++)
            for(int j = 0; j <= M; j++)
                entrada1[i][j] = entrada2[i][j] = 0;
        cubeta.clear();
    }
    return 0;
}
