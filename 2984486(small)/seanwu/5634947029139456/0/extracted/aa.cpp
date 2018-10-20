#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char sa[200][50];
char sb[200][50];
char s[50];
int w[50];
int n,m;
string ca[200];
string cb[200];

int check(int a,int b){
    int dd = 0;
    for( int i=0; i<m; i++ ){
        if(sa[a][i]!=sb[b][i]){
            w[i] = 1;
            dd++;
        }else{
            w[i] = 0;
        }
    }
    s[m] = 0;
    for( int i=0; i<n; i++ ){
        for( int j=0; j<m; j++ ){
            if(w[j]){
                s[j] = '0'+(1-(sa[i][j]-'0'));
            }else{
                s[j] = sa[i][j];
            }
        }
        ca[i] = s;
        cb[i] = sb[i];
    }
    sort(ca,ca+n);
    sort(cb,cb+n);
    for( int i=0; i<n; i++ ){
        if(ca[i]!=cb[i]) return 1000000;
    }
    return dd;
}

int main(){
    int tt,TT,d;
    scanf("%d",&TT);
    for( int tt=0; tt<TT; tt++ ){
        scanf("%d %d",&n,&m);
        for( int i=0; i<n; i++ ){
            scanf("%s",sa[i]);
        }
        for( int i=0; i<n; i++ ){
            scanf("%s",sb[i]);
        }
        int md = 1000000;
        for( int i=0; i<n; i++ ){
            for( int j=0; j<n; j++ ){
                d = check(i,j);
                if(d<md) md = d;
            }
        }
        printf("Case #%d: ",tt+1);
        if(md<10000){
            printf("%d\n",md);
        }else{
            puts("NOT POSSIBLE");
        }

    }
    return 0;
}
