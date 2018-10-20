#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

#define For(i,n) for(int i=0; i<(n); i++)
#define mp(a,b) make_pair((a),(b))
typedef long long ll;
typedef pair<int,int> pii;

int n=1000;
int A[1047][1047];
string O[1047];

void tabulka() {
    FILE* tab=fopen("tabulka","r");
    For(i,n) For(j,n) fscanf(tab," %d",&A[i][j]);
    fclose(tab);
}

void odpovede() {
    FILE* odp=fopen("odpoved","r");
    string s;
    char C[47];
    For(i,120) {fscanf(odp," %s",C); s=C; O[i]=s;}
    fclose(odp);
}

int main() {
    srand(time(NULL)*getpid());
    tabulka();
    //odpovede();
    vector<pair<int,string> > V;
    vector<pii> V1,V2;
    int t;
    scanf("%d",&t);
    For(i,t) {
        scanf("%d",&n);
        vector<int> P; P.resize(n);
        For(j,n) scanf("%d",&P[j]);
        int suma=0;
        For(j,n) suma+=A[j][P[j]];
        int poc=0;
        For(j,n) if(A[j][P[j]]>1000) poc++;
        V1.push_back(mp(suma,i));
        V2.push_back(mp(suma,i));
        //V.push_back(mp(suma,O[i]));
    }
    //sort(V.begin(),V.end());
    //For(i,V.size()) {printf("%9d %s\n",V[i].first,V[i].second.c_str()); if(i==59) printf("######################################\n");}
    sort(V1.begin(),V1.end());
    sort(V2.begin(),V2.end());
    vector<int> Vys; Vys.resize(t,0);
    For(i,V1.size()) if(i<60) Vys[V1[i].second]--; else Vys[V1[i].second]++;
    For(i,V2.size()) if(i<60) Vys[V2[i].second]--; else Vys[V2[i].second]++;
    For(i,t) {
        printf("Case #%d: ",i+1);
        if(Vys[i]<0) printf("GOOD\n");
        else if(Vys[i]>0) printf("BAD\n");
        else if(rand()%2==1) printf("GOOD\n");
        else printf("BAD\n");
    }
return 0;
}
