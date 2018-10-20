
#include <stdio.h>

int L,N,_2_L;

int minBits;
int outlets[1024];
int plugs[1024];


int readbit(void) {
    static char buf[20];
    int b=0;
    char *s=buf;
    scanf("%s",buf);
    while (*s) {
        b=2*b+*s++ -'0';
    }
    return b;
}

int bitcount(int b) {
    int c=0;
    while (b) {
        c++;
        b=b & (b-1);
    }
    return c;
}

void readcounts(int *a) {
    int i,b;
    for (i=0;i<_2_L;i++) a[i]=0;
    for (i=0;i<N;i++) {
        b=readbit();
        a[b]++;
    }
}

int samexor(int *a, int *b,int x) {
    int i;
    for (i=0;i<_2_L;i++) {
        if (a[i ^ x] != b[i]) return 0;
    }
    return 1;
}

void farm(void) {
    int b;
    minBits=1000;
    scanf("%d %d",&N,&L);
    _2_L=1<<L;
    readcounts(outlets);
    readcounts(plugs);
    for (b=0;b<_2_L;b++) {
        if (samexor(outlets,plugs,b) && bitcount(b)<minBits)
            minBits=bitcount(b);
    }
    if (minBits==1000) printf("NOT POSSIBLE\n");
    else printf("%d\n",minBits);
}

int main(int argc, char **argv) {
    int tc,i;
    scanf("%d",&tc);
    for (i=1;i<=tc;i++) {
        printf("Case #%d: ",i);
        farm();
    }
    return 0;
}