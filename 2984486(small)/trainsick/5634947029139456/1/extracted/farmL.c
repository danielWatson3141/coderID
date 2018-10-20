
#include <stdio.h>

int L,N,_2_L;

int minBits;
long long  outlets[200];
long long plugs[200];


long long readbit(void) {
    static char buf[50];
    long long b=0;
    char *s=buf;
    scanf("%s",buf);
    while (*s) {
        b=2*b+*s++ -'0';
    }
    return b;
}

int bitcount(long long b) {
    int c=0;
    while (b) {
        c++;
        b=b & (b-1);
    }
    return c;
}

void readcounts(long long *a) {
    int i,b;
    for (i=0;i<N;i++) {
        b=readbit();
        a[i]=b;
    }
}

//shell sort
void mysort(long long *a, int N) {
    int i,j,h;
    long long t;
    h=1;
    while (h<N) h=3*h+1;
    while (h) {
        for (i=h;i<N;i++) {
            j=i-h;
            while (j>=0 && a[j]>a[j+h]) {
                t=a[j];a[j]=a[j+h];a[j+h]=t;
                j-=h;
            }
        }
        h=h/3;
    }
}

int samexor(long long *aa, long long *b,int x) {
    int i;
    static long long a[200];
    for (i=0;i<N;i++) a[i]=aa[i]^x;
    mysort(a,N);
    for (i=0;i<N;i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void farm(void) {
    int b,i;
    minBits=1000;
    scanf("%d %d",&N,&L);
    _2_L=1<<L;
    readcounts(outlets);
    readcounts(plugs);
    mysort(plugs,N);
    mysort(outlets,N);
    
    for (i=0;i<N;i++) {
        b=outlets[0] ^ plugs[i];
        if (samexor( plugs, outlets, b) && bitcount(b)<minBits)
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