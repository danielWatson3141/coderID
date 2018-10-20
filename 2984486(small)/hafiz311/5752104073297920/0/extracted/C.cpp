#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <time.h>

#define SZ 1007
#define Thres 40
using namespace std;

int c[SZ+7];
int a[SZ+7],n;

int main()
{
    freopen("C.in","rt",stdin);
    freopen("C.out","wt",stdout);
    srand(time(NULL));
    //cout<<rand()<<endl;
    int tst,cas;
    scanf("%d",&tst);
    for(cas=1;cas<=tst;cas++) {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&c[i]);

        int tot = 10000;
        int bd = 0;

        while(tot--) {
            for(int i=0;i<n;i++) {
                a[i] = i;
            }
            for(int i=0;i<n;i++) {
                int p = rand()%n;
                p = (p+n)%n;
                swap(a[p],a[i]);
            }
            int cnt = 0;
            for(int i=0;i<n;i++) {
                if(a[i]==c[i]) cnt++;
            }
            if(cnt>=Thres) bd++;
        }
        if(bd>=Thres/2) {
            printf("Case #%d: BAD\n",cas);
        }
        else printf("Case #%d: GOOD\n",cas);

    }
    return 0;
}
