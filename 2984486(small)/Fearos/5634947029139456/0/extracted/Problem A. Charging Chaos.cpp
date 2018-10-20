#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    
    int n,m,i,j,k,a,b,t,x,l,v,ans,p;
    char in[15];
    int have[15],cur[15],want[15],now[1500];
    
    
    scanf("%d",&x);
    for(t=1;t<=x;t++)
       {
        scanf("%d%d",&n,&l);
        
        
        for(i=1;i<=n;i++)
           {
            scanf("%s",in);
            v = 0;
            m=1;
            for(j=0;j<l;j++,m*=2)
               v += (in[j]-'0') * m;
     //       printf("%d ",v);
            want[i] = v; 
           }
        
        for(i=1;i<=n;i++)
           {
            scanf("%s",in);
            v = 0;
            m=1;
            for(j=0;j<l;j++,m*=2)
               v += (in[j]-'0') * m;
    //        printf("%d ",v);
            have[i] = v; 
           }
        k = 1<<l;
        ans = l+1;
        for(i=0;i<k;i++)
           {
        //    printf("\ni = %d\n",i);
            j=i;
            p = 1;
            b=0;
            for(v=1;v<=n;v++) cur[v] = have[v];
            for(p=1;p<=l;p++)
               {
                
                a = j%2;
              //  printf("j = %d a = %d\n",j,a);
                j/=2;
                if(a)
                   {b++;
                    for(v=1;v<=n;v++)
                       cur[v]  = (cur[v]^(1<<(p-1)));
                   }
                //else cur[v] = have[v];
                
               }
         //   for(v=1;v<=n;v++) printf("cur[%d] = %d ",v,cur[v]);
              
        ///    printf("b = %d\n",b);
            bool ch=true;
            for(j=1;j<=n;j++)
               {
                for(v=1;v<=n;v++)
                   {
                    if(want[j] == cur[v]) break;
                   }
                if(v == n+1) 
                   {
                    ch = false;
                    break;
                   }
               }
            if(ch) ans = min(ans,b);
            
           }
        
        
        
        
        printf("Case #%d: ",t);
        if(ans == l+1) printf("NOT POSSIBLE");
        else printf("%d",ans);
        printf("\n");
       }
    
    
    
 scanf(" ");
 return 0;
}
