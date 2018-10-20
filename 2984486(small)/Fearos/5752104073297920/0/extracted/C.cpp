#include<stdio.h>
#include<algorithm>
using namespace std;
int aa[1005];
int main(){
    
    int n,m,i,j,k,a,b,p,t,x;
     double sum,cur=0;
    
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    
    
    scanf("%d",&x);
    for(t=1;t<=x;t++)
       {
        scanf("%d",&n);
        for(i=0;i<n;i++)
           scanf("%d",&aa[i]);
        
        sum=0;
        for(i=0;i<1000;i++)
           {
            a = 0;
            for(j=0;j<i;j++)
               {
                if(aa[i] < aa[j]) a++;
               }
            b = 0;
            for(j=i+1;j<i;j++)
               if(aa[i] > aa[j]) b++;
            
            sum += abs(a-b);
            
           }
        
        
        
        printf("Case #%d: ",t);
        if(sum > 245000) printf("BAD");
        else printf("GOOD");
        printf("\n");
       }
    
    
    
 scanf(" ");
 return 0;
}
