#include <stdio.h>

long a[2000],b[2000];

int main(){
    long t,tt,i,j,k,n;
    double tot=0;
    freopen("C-small-attempt0.in.txt", "r",stdin);
    freopen("C-small-attempt0.out.txt", "w",stdout);

    scanf("%ld",&tt);
    for (t=1;t<=tt;t++){
        scanf("%ld",&n);
        for (i=0;i<n;i++){
            scanf("%ld",a+i);
            b[i]=i;
        }
        for (i=0;i<n;i++){
            for (j=i;j<n;j++){
                if (a[i]==b[j])
                    break;
            }
            k=b[i];
            b[i]=b[j];
            b[j]=k;
            tot+=((double)(j-i))/((double)(n-i));
        }
        tot/=n;
        printf("Case #%ld: ",t);
        if (tot<0.55&&tot>0.45)
            printf("GOOD\n");
        else
            printf("BAD\n");
    }
    return 0;
}

