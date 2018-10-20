#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

char data[2][155][45];
int N, L;
int cmp(const void* p_1, const void* p_2){
    char* p1 = (char*)p_1;
    char* p2 = (char*)p_2;
    return strcmp(p1, p2);
}

int judge(int b){
    int error = 0;
    for(int i = 0; i < N; i++){
        if(data[0][i][b] != data[1][i][b]){
            error = 1;
            break;
        }
    }
    return error;
}

int reverse(int b){
    for(int i = 0; i < N; i++){
        data[0][i][b] = '0' + '1' - data[0][i][b];
        //cout << data[0][i] << " ";
    }
    //cout << endl;
}

int _min = 1000;
int dfs(int cur, int n, int cnt){
    if(cur == n){
        _min = min(_min, cnt);
    }
    else{
        if(judge(cur) == 0){
            if(cnt < _min){
                dfs(cur + 1, n, cnt);
            }
            reverse(cur);
            qsort(data[0], N, sizeof(data[0][0]), cmp);
            if(judge(cur) == 0 && cnt + 1 < _min){
                dfs(cur + 1, n, cnt + 1);
            }
            reverse(cur);
            qsort(data[0], N, sizeof(data[0][0]), cmp);
        }
        else{
            reverse(cur);
            qsort(data[0], N, sizeof(data[0][0]), cmp);
            if(judge(cur) == 0 && cnt + 1 < _min){
                dfs(cur + 1, n, cnt + 1);
            }
            reverse(cur);
            qsort(data[0], N, sizeof(data[0][0]), cmp);
        }
    }
    return cnt;
}
int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T, cas = 0;
    scanf("%d", &T);
    while(T--){
        _min = 1000;
        memset(data, 0, sizeof(data));
        if(cas){
            cout << endl;
        }
        printf("Case #%d: ", ++ cas);
        scanf("%d%d", &N, &L);
        for(int i = 0; i < N; i++){
            scanf("%s", data[0][i]);
            //cout << data[0][i] << " ";
        }
        //cout << endl;
        for(int i = 0; i < N; i++){
            scanf("%s", data[1][i]);
            //cout << data[1][i] << " ";
        }
        //cout << endl;
        qsort(data[0], N, sizeof(data[0][0]), cmp);
        qsort(data[1], N, sizeof(data[1][0]), cmp);

        //cout << endl;
        dfs(0, L, 0);
        if( _min != 1000){
            cout << _min;
        }
        else{
            cout << "NOT POSSIBLE";
        }
    }
    return 0;
}
