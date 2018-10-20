#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

long long alat[200],kontak[200];
int kasus,N,panjang;
char kata[200];

int popcount(long long x) {
    int total = 0;
    while (x > 0) {
        ++total;
        x -= (x & -x);
    }
    return total;
}

int main() {
    scanf("%d",&kasus);
    for (int l=1;l<=kasus;++l) {
        scanf("%d %d",&N,&panjang);
        for (int i=0;i<N;++i) {
            scanf("%s",&kata);
            long long temp = 0;
            for (int j=0;j<panjang;++j) temp = 2*temp + (kata[j]-'0');
            kontak[i] = temp;
        }
        
        for (int i=0;i<N;++i) {
            scanf("%s",&kata);
            long long temp = 0;
            for (int j=0;j<panjang;++j) temp = 2*temp + (kata[j]-'0');
            alat[i] = temp;
        }
        sort(alat,alat+N);
        
        int jawab = panjang+1;
        for (int i=0;i<N;++i) {
            /*Pasangin kontak[0] dengan alat[i]*/
            long long press = kontak[0] xor alat[i];
            if (popcount(press) >= jawab) continue;
            bool flag = true;
            for (int j=1;j<N && flag;++j) {
                /*Cek kontak sisanya ada temennya kagak*/
                if (!binary_search(alat,alat+N,kontak[j] xor press)) {
                    flag = false;
                }
            }
            
            if (flag) jawab = popcount(press);
        }
        
        if (jawab <= panjang) printf("Case #%d: %d\n",l,jawab);
        else printf("Case #%d: NOT POSSIBLE\n",l);
    }
    return 0;
}
