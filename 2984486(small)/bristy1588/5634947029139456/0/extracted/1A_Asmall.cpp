#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#define     Z       305
using namespace std;
char str[Z];
string a[Z],b[Z],tmp[Z];

int main(){

    int t,tc,N,L,i,j,flag,nbits,ans;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("Asmall.out","w",stdout);
    scanf("%d",&t);
    tc = 0;
    while(tc < t){


        tc++;
        cin >> N >> L;

        for(i = 0; i < N; i++){
            scanf("%s",str);
            a[i] = str;
        }
        for(i = 0; i < N; i++){
            scanf("%s",str);
            b[i] = str;
        }

        ans = L+L;

        int mask;

        for(mask = 0; mask < (1<<L) ; mask++){
            for(i= 0; i < N; i++)
               tmp[i] = a[i];

            nbits = 0;
            for(i = 0; i < L; i++){
                if(mask & (1<<i)){
                    nbits++;
                    for(j = 0; j < N; j++){
                        if(a[j][i] == '0') tmp[j][i] = '1';
                        else tmp[j][i] ='0';
                    }
                }
            }

            flag = 0;
            sort(b,b+N);
            sort(tmp,tmp+N);

            for(i = 0; i < N; i++){
                if(tmp[i] != b[i]) flag = 1;
            }

            if(flag == 0){
                ans = min(ans, nbits);
            }
        }

        printf("Case #%d: ",tc);
        if(ans > L) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);


    }

    return 0;
}

