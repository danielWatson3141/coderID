# include <stdio.h>
# include <string.h>
char s[11][11],final[11][11];int n;int min;int l;
void recurse(int b,int c)
{

int i,j,flag,fi=0;
int set[11]={0};
for(i=0;i<n;i++)
{
flag=0;fi=1;
for(j=0;j<n;j++)
{
if(strcmp(s[i],final[j])==0 && (set[j]==0))
{flag=1;  set[j]=1;
//if(c==0)
//printf("%d  %d %s %s\n",b,c,s[i],final[j]); 

 break;

}
}
//printf("flag %d\n",flag);
if(flag==0){fi=0;break; }
}
if(fi==1)
if(c<min)min=c;
if(b>=l)return;
recurse(b+1,c);
for(i=0;i<n;i++)
s[i][b]=(s[i][b]=='1')?'0':'1';
recurse(b+1,c+1);
for(i=0;i<n;i++)
s[i][b]=(s[i][b]=='1')?'0':'1';
}

int main()
{
FILE *fi=fopen("read.in","r");
FILE *fo=fopen("out.txt","w");
int t,i,k;
fscanf(fi,"%d",&t);
for(k=1;k<=t;k++)
{
fscanf(fi,"%d%d",&n,&l);
for(i=0;i<n;i++)
fscanf(fi,"%s",s[i]);
for(i=0;i<n;i++)
fscanf(fi,"%s",final[i]);
min=9999;
recurse(0,0);
if(min==9999)
fprintf(fo,"Case #%d: NOT POSSIBLE\n",k);
else
fprintf(fo,"Case #%d: %d\n",k,min);
}
return 0;
} 
