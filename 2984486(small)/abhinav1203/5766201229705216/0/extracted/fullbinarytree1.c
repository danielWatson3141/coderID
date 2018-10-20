#include<stdio.h>
int vis[1005],edge[1005][1005],numEdges[1005],root[1005];
int dfs(int node)
{
  int non_visited=0,i,count,answer;
  vis[node]=1;
  for(i=0;i<numEdges[node];i++)
    if(!vis[edge[node][i]])
      non_visited++;
  if(non_visited==0)
    return 0;
  else if(non_visited==1)
    return 1;
  else
    {
      count=0;
      answer=0;
      for(i=0;i<numEdges[node];i++)
	{
	  if(!vis[edge[node][i]])
	    {
	      answer+=dfs(edge[node][i]);
	      count++;
	    }
	  if(count==2)
	    break;
	}
      return answer+non_visited-2;
    }
  /*
  int edges,min,second_min,i,x;
  edges=(root[node]==1)?numEdges[node]:numEdges[node]-1;
  if(edges<2)
    return edges;
  min=1e9;second_min=2e9;
  vis[node]=1;
  for(i=0;i<numEdges[node];i++)
    {
      if(!vis[edge[node][i]])
	{
	  x=dfs(edge[node][i]);
	  if(x<=min)
	    {
	      second_min=min;
	      min=x;
	    }
	  else if(x>min && x<=second_min)
	    second_min=x;
	}
    }
  if(min+second_min+edges-2<edges)
    return min+second_min+edges-2;
  else
    return edges;
  */
}
int main()
{
  int T,t,i,N,x,y,min,j,count;
  scanf("%d",&T);
  for(t=1;t<=T;t++)
    {
      scanf("%d",&N);
      for(i=0;i<N;i++)numEdges[i]=0;
      for(i=0;i<(N-1);i++)
	{
	  scanf("%d %d",&x,&y);
	  x--;y--;
	  edge[x][numEdges[x]++]=y;
	  edge[y][numEdges[y]++]=x;
	}
      /*
      min=1e9;
      for(i=0;i<N;i++)
	{
	  if(numEdges[i]<2)continue;
	  for(j=0;j<N;j++)
	    {
	      vis[j]=0;
	      root[j]=0;
	    }
	  root[i]=1;
	  x=dfs(i);
	  printf("%d %d\n",i,x);
	  if(x<min)
	    min=x;
	}
      */
      for(i=0;i<N;i++)
	vis[i]=0;
      count=0;
      for(i=0;i<N;i++)
	{
	  if(numEdges[i]>=2 && vis[i]==0)
	    count+=dfs(i);
	  //count++;
	}
      printf("Case #%d: %d\n",t,count);
      //printf("%d\n",min);
    }
  return 0;
}
