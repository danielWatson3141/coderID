#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#define     Z       305
using namespace std;
char str[Z];
string a[Z],b[Z],tmp[Z];
int L,filip[Z];
void match(int j){
    // match ai, bj
    int k;
    memset(filip,0,sizeof(filip));
    //cout<<a[0]<<" "<<b[j]<<endl;
    for(k = 0; k < L; k++){
        if(a[0][k] != b[j][k]) filip[k] = 1;
    }
    return;
}
int main(){

    int t,tc,N,i,j,flag,nbits,ans;

    freopen("A-large.in","r",stdin);
    freopen("Alargeans.out","w",stdout);
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

        int k;
         sort(b,b+N);
        for(k = 0; k < N; k++){

            match(k);
            nbits = 0;

            for(j = 0; j<L; j++){
                nbits+=filip[j];
                //printf("%d ",filip[j]);
            }


            for(i = 0; i < N ; i++){
                tmp[i] = a[i];
                for(j = 0; j < L; j++){
                    if(filip[j] == 1){
                        if(a[i][j]=='0') tmp[i][j] = '1';
                        else tmp[i][j] = '0';
                    }
                }
            }


            flag = 0;
            sort(tmp,tmp+N);

            for(i = 0; i < N; i++){
                //cout<<tmp[i]<<" "<<b[i]<<endl;
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

