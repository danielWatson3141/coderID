#include <cstdio>
#include <cstring>
using namespace std;

char a[200][50],c[200][50],o[200][50];
bool b[200];

void change(int n,int t)
{
  int i1;
  for(i1=1;i1<=n;i1++)
  {
    if(a[i1][t]=='0') a[i1][t]='1';
	else a[i1][t]='0';
  }
  return;
}

int main()
{
  FILE *fr,*fw;
  fr=fopen("a.in","r");
  fw=fopen("a.out","w");
  
  int t,i;
  fscanf(fr,"%d",&t);
  for(i=1;i<=t;i++)
  {
    fprintf(fw,"Case #%d: ",i);
	int n,l;
	fscanf(fr,"%d%d",&n,&l);
	int i1,len=l,min=888;
	for(i1=1;i1<=n;i1++)
	{
	  fscanf(fr,"%s",a[i1]);
	  strcpy(o[i1],a[i1]);
	}
	for(i1=1;i1<=n;i1++)
	  fscanf(fr,"%s",c[i1]);
	for(i1=1;i1<=n;i1++)
	{
	  //printf("---\ni1=%d\n",i1);
	  int t1,t2,cnum=0;
	  //更改
	  for(t1=0;t1<l;t1++)
	    if(a[1][t1]!=c[i1][t1])
		{
		  change(n,t1);
		  cnum++;
		  //printf("%s %s\n",a[1],c[i1]);
		}
	  //比较
	  for(t1=1;t1<=n;t1++)
	    b[t1]=false;
	  for(t1=1;t1<=n;t1++)
	    for(t2=1;t2<=n;t2++)
		  if(strcmp(a[t1],c[t2])==0) b[t2]=true;
	  bool flag=true;
	  for(t1=1;t1<=n;t1++)
	    if(!b[t1]) flag=false;
	  //printf("flag=%d\n",flag);
	  if(flag&&cnum<min) min=cnum;
	  //复原
	  for(t1=0;t1<l;t1++)
	    if(a[1][t1]!=o[1][t1])
		  change(n,t1);
	}
    if(min==888) fprintf(fw,"NOT POSSIBLE");
	else fprintf(fw,"%d",min);
	if(i<t) fprintf(fw,"\n");
	//getchar();
  }
  
  //while(1);
  return 0;
}

