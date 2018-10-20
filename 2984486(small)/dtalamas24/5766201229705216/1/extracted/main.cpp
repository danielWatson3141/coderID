#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

bool Z[1005];
int casos, ctos, a, b, cuenta, mejor, m;
vector <int> L[1005];

int aslo(int dnde){
    Z[dnde]=true;
    ++cuenta;
    int g=cuenta, gra1=0, gra2=0, son=0, tiene=0;
    for(int i=0; i<L[dnde].size(); i++){
        if(!Z[L[dnde][i]]){
            ++son;
            int s=cuenta;
            m=aslo(L[dnde][i]);
            s=cuenta-s;
            if(s-m>gra1){
                gra2=gra1;
                gra1=s-m;
            }
            else if(s-m>gra2)
                gra2=s-m;
            tiene+=s;
        }
    }
    if(son<2){
        return tiene;
    }
    return tiene-gra1-gra2;
}

int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&casos);
    for(int v=1; v<=casos; v++){
        scanf("%d",&ctos);
        mejor=-1;
        for(int i=1; i<ctos; i++){
            scanf("%d%d",&a,&b);
            L[a].push_back(b);
            L[b].push_back(a);
        }
        for(int i=1; i<=ctos; i++){
            for(int e=1; e<=ctos; e++)
                Z[e]=false;
            cuenta=0;
            m=aslo(i);
            if(mejor==-1 or m<mejor)
                mejor=m;
        }
        printf("Case #%d: %d\n",v,mejor);
        for(int i=1; i<=ctos; i++)
            L[i].clear();
    }
    return 0;
}
