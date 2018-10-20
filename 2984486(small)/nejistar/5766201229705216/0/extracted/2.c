# include <stdio.h>

int min; int a[16][2],s[16]; int n;int set[17];
void recurse(int b,int c)
{
int count1=0,count2=0,count3=0,count0=0;int i;int r;int st[20];
for(i=0;i<n;i++){
if(s[i]==2)count2++;
if(s[i]==1)count1++;
if(s[i]==3)count3++;
if(s[i]==0)count0++;
}
//printf("%d %d %d %d\n",count1,count2,count3,count0);

if(count2==1){

if(count0<min)min=n-count1-count2-count3; }
if(b>=n)
return;
recurse(b+1,c);
for(i=0;i<n;i++)
st[i]=s[i];
for(i=0;i<n-1;i++)
{
if(a[i][0]==b)
{ if(set[s[a[i][1]]]==0)s[a[i][1]]--; }
if(a[i][1]==b)
{ if(set[s[a[i][0]]]==0)s[a[i][0]]--;
}
s[b]=0;
}
set[b]=1;
recurse(b+1,c+1);
set[b]=0;

for(i=0;i<n;i++)
s[i]=st[i];
}

int main()
{
FILE *fi=fopen("read.in","r");
FILE *fo=fopen("out.txt","w");
int t,k,i;
fscanf(fi,"%d",&t);
for(k=1;k<=t;k++)
{
fscanf(fi,"%d",&n);
for(i=0;i<n;i++)
{s[i]=0;set[i]=0;}
for(i=0;i<n-1;i++)
{ fscanf(fi,"%d%d",&a[i][0],&a[i][1]);
a[i][0]--; a[i][1]--;
s[a[i][0]]++;s[a[i][1]]++;
}
//for(i=0;i<n;i++)
//fprintf(fo,"%d\n",s[i]);
min=n-1;
recurse(0,0);
fprintf(fo,"Case #%d: %d\n",k,min);
}
return 0;
}
