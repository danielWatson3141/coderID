#include<stdio.h>
int fun(char str[152][41] , char dev[152][41] , int n ,int l, int i,int count)
 {
 int j;

   if(i==l)
     return -1;
     int k,m,f,min1,min2;
  for(j=0;j<n;j++){  //flip ith bit
       //printf("helllo  %d %c\n",j,str[j][i]);
     if(str[j][i]=='0')
       str[j][i]='1';
      else
        str[j][i]='0';
     }
  /*  for(j=0;j<n;j++)
        printf("%s\n",str[j]);
     printf("helllo  %d %d \n",i,count+1);*/


  for(j=0;j<n;j++){  // check for match
      f=0;
    for(k=0;k<n;k++)
     {
         for(m=0;m<l;m++)
            if(str[j][m]!=dev[k][m])
               break;
        if(m==l){
         f=1;
         break;
        }
     }
     if(f==0)
         break;
   }

  if(f==1) { // if match
  for(j=0;j<n;j++){  //flip ith bit
       //printf("helllo  %d %c\n",j,str[j][i]);
     if(str[j][i]=='0')
       str[j][i]='1';
      else
        str[j][i]='0';
     }

    return count+1;
  }
  //min1=fun(str,dev,n,l,i+1,count+1);
 //  printf("helllo  %d\n",i);
  min1=l+1;
  for(j=i+1;j<l;j++)
    {
       m=fun(str,dev,n,l,j , count+1);
      if(m<min1 && m!=-1)
         min1=m;
    }

     for(j=0;j<n;j++){  //flip ith bit
     if(str[j][i]=='0')
       str[j][i]='1';
      else
        str[j][i]='0';
     }
    min2=l+1;
  for(j=i+1;j<l;j++)
    {
       m=fun(str,dev,n,l,j , count);
      if(m<min2 && m!=-1)
         min2=m;
    }

//printf("%d %d\n",min1,min2);
   if(min2>l && min1>l)
     return -1;
     else if( min1<min2)
      return min1;
      else
       return min2;



 }

int main()
{
    int t,n,z,l,i,j,min=-1,m,k,count,f;
    char str[152][41],dev[152][41];
    scanf("%d",&t);
    for(z=0;z<t;z++)
    {
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
      scanf("%s",str[i]);
    /*  for(i=0;i<n;i++)
        printf("%s\n",str[i]);*/
    for(i=0;i<n;i++)
      scanf("%s",dev[i]);
         /*for(i=0;i<n;i++)
        printf("%s\n",dev[i]);*/
    min=l+1;
   // f=0;
      for(j=0;j<n;j++){  // check for match
      f=0;
    for(k=0;k<n;k++)
     {
         for(m=0;m<l;m++)
            if(str[j][m]!=dev[k][m])
               break;
        if(m==l){
         f=1;
        break;
        }
     }
     if(f==0)
         break;
   }
  if(f==1){  // if match
           printf("Case #%d: %d\n",z+1,0);
    // count;
  }
 else{

 //printf("helllo  1\n");
      m=fun(str,dev,n,l,0 , 0);

      if(m!=-1)
        printf("Case #%d: %d\n",z+1,m);
     else
       printf("Case #%d: NOT POSSIBLE\n",z+1)     ;
    }
  }

}

