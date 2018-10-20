#include<stdio.h>
char a[152][41], b[152][41];
int fun(int n ,int l, int i,int count)
{
    int j;
    if(i == l)
       return -1;
    int k,m,min,min1, flag;
    for(j=0;j<n;j++){  
        if (a[j][i] == '0')
            a[j][i]='1';
        else
            a[j][i]='0';
    }
    
    for(j=0;j<n;j++){  
        flag=0;
    for(k=0;k<n;k++) {
        for(m=0;m<l;m++) {
            if(a[j][m]!=b[k][m])
               break;
         }
         if(m==l){
                  flag = 1;
                  break;
         }
     }
     if(flag==0)
         break;
   }
  
   if(flag==1) 
      return count;
   min=n+1;
   
   for(j=i+1;j<n;j++) {
       m=fun(n,l,j,count+1);
      if(m < min && m != -1)
         min=m;
   }

   for(j=0;j<n;j++){  
      if(a[j][i]=='0')
           a[j][i]='1';
      else
          a[j][i]='0';
   }
   
   min1=n+1;
   for(j=i+1;j<n;j++) {
      m = fun(n,l,j , count);
      if(m<min1 && m!=-1)
      
         min1=m;
    }


   if(min1>n && min>n)
     return -1;
   else if( min<min1)
      return min;
   else
       return min1;



 }

int main()
{
    int t,n,l,i,j,min=-1,m,k,count,flag,x;
    
    
    
    scanf("%d",&t);
    
    for(x=1;x<=t;x++) {
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            scanf("%s",a[i]);
        for(i=0;i<n;i++)
            scanf("%s",b[i]);
        min=n+1;
        for(j=0;j<n;j++){  
            flag=0;
            for(k=0;k<n;k++) {
                 for(m=0;m<l;m++)
                     if(a[j][m]!=b[k][m])
                         break;
                 if(m==l){
                      flag=1;
                      break;
                 }
            }
            if(flag==0)
               break;
        }
        if(flag==1){  
           printf("Case #%d: %d\n",x,0);
        }
        else {
              m=fun(n,l,0,1);
              if(m != -1)
                  printf("Case #%d: %d\n",x,m);
              else
                  printf("Case #%d: NOT POSSIBLE\n",x);
               }
         }
return 0;
}
