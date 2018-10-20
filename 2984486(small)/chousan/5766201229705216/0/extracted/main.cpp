#include <iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
const int INF=0x3f3f3f3f;
using namespace std;
int n,m;
int s,t,k;
struct hh
{
    int from,to,w,next;
}edges[200000],qq[210000];
struct node1
{
    int id;
    int dis;
    bool operator<(const node1 &p)const
    {
        return p.dis<dis;
    }
};
struct node2
{
    int id;
    int dis;
    int len;
    bool operator<(const node2 &p)const
    {
        return p.dis+p.len<dis+len;
    }
};
int box[1010],box1[1010];
void add(int from,int to,int w,int cnt)
{
    edges[cnt].from=from;
    edges[cnt].to=to;
    edges[cnt].w=w;
    edges[cnt].next=box[from];
    box[from]=cnt;
}
void add1(int from,int to,int w,int cnt)
{
    qq[cnt].from=from;
    qq[cnt].to=to;
    qq[cnt].w=w;
    qq[cnt].next=box1[from];
    box1[from]=cnt;
}
int visit[2010];
int dis[2010];
priority_queue<node1>que1;
 priority_queue<node2>que;
void dijskra()
{
    memset(visit,0,sizeof(visit));
    while(!que1.empty())que1.pop();
    node1 ima,chigi;
    ima.id=t;
    ima.dis=0;
    que1.push(ima);
    for(int i=1;i<=n;++i)dis[i]=INF;
    dis[t]=0;
    while(!que1.empty())
    {
        ima=que1.top();
        que1.pop();
        if(visit[ima.id])continue;
        visit[ima.id]=1;
        dis[ima.id]=ima.dis;
        for(int i=box1[ima.id];i!=-1;i=qq[i].next)
        {
            int to=edges[i].to;
            if(!visit[to]&&dis[to]>qq[i].w+dis[ima.id])
            {
                chigi.id=to;
                chigi.dis=qq[i].w+dis[ima.id];
                que1.push(chigi);
            }
        }
    }


}
int num[1100];
int a_star()
{
   while(!que.empty())que.pop();
    node2 ima,chigi;
    memset(num,0,sizeof(num));
    ima.id=s;
    ima.dis=dis[s];
    ima.len=0;
    que.push(ima);
    while(!que.empty())
    {
        ima=que.top();
        que.pop();
       // cout<<ima.id<<' '<<ima.dis<<' '<<ima.len<<endl;
        num[ima.id]++;
        if(num[t]==k)return ima.len;
        if(num[ima.id]>k)continue;
        for(int i=box[ima.id];i!=-1;i=edges[i].next)
        {
            int to =edges[i].to;
            chigi.id=to;
            chigi.len=ima.len+edges[i].w;
            chigi.dis=dis[to];
            que.push(chigi);
        }

    }
    return -1;

}


int main()
{
   freopen("in.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int x,y,z,cnt=0;
        memset(box,-1,sizeof(box));
        memset(box1,-1,sizeof(box));
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z,cnt++);
            add1(y,x,z,cnt++);
        }
        scanf("%d%d%d",&s,&t,&k);
        if(s==t)k++;
        dijskra();
        printf("%d\n",a_star());
    }
    return 0;
}





