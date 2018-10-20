#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int comp(const void *a,const void *b)
{ return(strcmp((char *)a,(char *)b));
}
int main()
{
    int t,n,l,i,j,x,y,min,ans;
    char cur[150][41],cur2[150][41];
    char req[150][41],req2[150][41];
    scanf("%d",&t);
    for(x=1;x<=t;x++)
    { scanf("%d %d",&n,&l);
      for(i=0;i<n;i++)
      scanf("%s",cur[i]);
      for(i=0;i<n;i++)
      scanf("%s",req[i]);
      min=200;
      for(y=0;y<n;y++)
      { ans=0;
        for(i=0;i<n;i++)
         { strcpy(req2[i],req[i]);
           strcpy(cur2[i],cur[i]);
         }
         for(i=0;i<l;i++)
           if(cur2[0][i]!=req2[y][i])
             { for(j=0;j<n;j++)
                cur2[j][i]='1'-cur2[j][i]+'0';
                ans++;
             }
         qsort(cur2,n,41,comp);
         qsort(req2,n,41,comp);
         for(i=0;i<n;i++)
          if(strcmp(req2[i],cur2[i])) break;
         if(i==n) 
         { if(ans<min) min=ans;
         }
        }
        printf("case #%d: ",x);
        if(min>150) printf("NOT POSSIBLE\n");
        else printf("%d\n",min);
      }
      return 0;
    }
          
