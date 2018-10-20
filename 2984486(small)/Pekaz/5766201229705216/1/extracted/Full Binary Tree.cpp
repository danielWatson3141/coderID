#include <stdio.h>
#include <algorithm>

using namespace std;

struct treeinfo
{
	int x;
	int y;
};

struct treecntinfo
{
	int sonCnt;
	int sumCnt;
};

treecntinfo treeCnt[1002],cntempty;
treeinfo tree[2002],empty;
int pl[1002][2],chk[1002];

struct queueinfo
{
	int x;
};

queueinfo queue[1000002],temp,tempin;
int incnt,outcnt;

void push(queueinfo x)
{
	queue[incnt++]=x;
	if(incnt >= 1000002)
		incnt=0;
}
queueinfo pop()
{
	queueinfo x = queue[outcnt++];
	if(outcnt >= 1000002)
		outcnt=0;
	return x;
}


bool treeslt(treeinfo a,treeinfo b)
{
	if(a.x <= b.x)
	{
		if(a.x==b.x)
		{
			if(a.y < b.y)
				return 1;
			else
				return 0;
		}
		else return 1;
	}
	else return 0;
}

int goback(int x)
{
	chk[x]=1;
	treeCnt[x].sonCnt=0;
	treeCnt[x].sumCnt=0;
	for(int i=pl[x][0];i<pl[x][1];i++)
	{
		if(chk[tree[i].y]==0)
		{
			treeCnt[x].sonCnt++;
			treeCnt[x].sumCnt+=goback(tree[i].y);
		}
	}
	treeCnt[x].sumCnt++;
	return treeCnt[x].sumCnt;
}

int main()
{
	int n,m,tcase;
	int result;

	FILE *in,*out;
	in=fopen("B-large.in","r");
	out=fopen("output2.txt","w");

	fscanf(in,"%d",&tcase);
	for(int t=0;t<tcase;t++)
	{
		for(int i=0;i<1002;i++)
		{
			chk[i]=0;
			pl[i][0]=pl[i][1]=0;
		}

		fscanf(in,"%d",&n);
		for(int i=0;i<n-1;i++)
		{
			fscanf(in,"%d",&tree[i].x);
			fscanf(in,"%d",&tree[i].y);
			tree[n+i-1].x=tree[i].y;
			tree[n+i-1].y=tree[i].x;
		}
		m=(n-1)*2;
		result=n-1;
		sort(&tree[0],&tree[m],treeslt);

		for(int i=1;i<m;i++)
		{
			if(tree[i-1].x!=tree[i].x)
			{
				pl[tree[i-1].x][1]=i;
				pl[tree[i].x][0]=i;
			}
		}
		pl[tree[m-1].x][1]=m;

		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				chk[j]=0;
				treeCnt[j] = cntempty;
			}
			incnt=outcnt=0;

			goback(i);

			for(int j=0;j<=n;j++)
				chk[j]=0;

			temp.x=i;
			push(temp);
			chk[temp.x]=1;
			
			int nodeCnt=1;
			while(1)
			{
				if(incnt==outcnt)
					break;
				temp=pop();
				if(treeCnt[temp.x].sonCnt==2)
				{
					nodeCnt+=2;
					for(int j=pl[temp.x][0];j<pl[temp.x][1];j++)
					{
						tempin.x=tree[j].y;
						if(chk[tempin.x]==0)
						{
							chk[tempin.x]=1;
							push(tempin);
						}
					}
				}
				else if(treeCnt[temp.x].sonCnt>2)
				{
					int maxx,max=0;
					for(int j=pl[temp.x][0];j<pl[temp.x][1];j++)
					{
						if(chk[tree[j].y]==0 && max<treeCnt[tree[j].y].sumCnt)
						{
							max=treeCnt[tree[j].y].sumCnt;
							maxx=tree[j].y;
						}
					}
					tempin.x=maxx;
					chk[tempin.x]=1;
					push(tempin);

					max=0;
					for(int j=pl[temp.x][0];j<pl[temp.x][1];j++)
					{
						if(chk[tree[j].y]==0 && max<treeCnt[tree[j].y].sumCnt)
						{
							max=treeCnt[tree[j].y].sumCnt;
							maxx=tree[j].y;
						}
					}
					tempin.x=maxx;
					chk[tempin.x]=1;
					push(tempin);

					nodeCnt+=2;
				}
			}
			if(result>n-nodeCnt)
				result=n-nodeCnt;
		}
		fprintf(out,"Case #%d: %d\n",t+1,result);
	}
	return 0;
}