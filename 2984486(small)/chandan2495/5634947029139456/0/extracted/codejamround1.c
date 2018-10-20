#include<stdio.h>
#include<math.h>
#include<string.h>

typedef long long ll;
int main()
{
int t,n,l,ca=1,count=0,i,j,k,temp,temp1,p,min,flag=0;
char c[11][11],b[11][11],a[11][11];
scanf("%d",&t);
while(t--)
{
min=(1<<31)-1;
flag=0;
 scanf("%d%d\n",&n,&l);
 for(i=0;i<n;i++)
 {
 scanf("%s",a[i]);
 }
  for(i=0;i<n;i++)
  {
  scanf("%s",b[i]);
  }
  
  
temp=pow(2,l);
for(i=0;i<temp;i++)
{
temp1=0; count=0;
for(j=0;j<n;j++)
strcpy(c[j],a[j]);
 for(p=l-1,k=i;k>0;p--,k=(k>>1)){
 if(k&1){
 for(j=0;j<n;j++)
 {
   if(c[j][p]=='0')
   c[j][p]='1';
   else
   c[j][p]='0';
 }
 count++;
 }
}
//for(k=0;k<n;k++)
//printf("%d %s %s\n",i,c[k],b[k]);
for(k=0;k<n;k++){
for(j=0;j<n;j++)
{
 if(!strcmp(c[k],b[j]))
 break;
}
if(j==n)
break;
}
if(k==n){
flag=1;
 if(min>count)
  min=count;
}
}
if(flag==0)
printf("Case #%d: NOT POSSIBLE\n",ca);
else
printf("Case #%d: %d\n",ca,min);
ca++;
}
return 0;
}
