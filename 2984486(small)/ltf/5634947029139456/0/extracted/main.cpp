#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn=150+10;
const int maxl=50;
const int inf=20000;

int N,L;
struct One
{
    char s[maxl];
};
vector<One> str;

struct Node
{
    Node *l,*r;
    int num;
    vector<int> has;
    Node()
    {
        l=0;
        r=0;
        num=0;
    }
    void clear()
    {
        if(l)
        {
            l->clear();
            delete l;
            l=0;
        }
        if(r)
        {
            r->clear();
            delete r;
            r=0;
        }
        has.clear();
        num=0;
    }
};
Node root;


void insert(char *s)
{
    Node *now=&root;
    while(s[0])
    {
        now->num++;
        switch(s[0])
        {
        case '0':
            if(!now->l)
                now->l=new Node();
            now=now->l;
            break;
        case '1':
            if(!now->r)
                now->r=new Node();
            now=now->r;
            break;
        }
        s++;
    }
}

bool find(char *s)
{
    Node *now=&root;
    while(s[0])
    {
        now->num++;
        switch(s[0])
        {
        case '0':
            if(!now->l)
                return false;
            now=now->l;
            break;
        case '1':
            if(!now->r)
                return false;
            now=now->r;
            break;
        }
        s++;
    }
    return true;
}


int dfs(vector<One> a,int dep,int need)
{
    int res=inf;
    if(dep==L)
    {
        for(int i=0;i<a.size();i++)
        {
            if(!find(a[i].s))
                return inf;
        }
        return need;
    }
    res=min(res,dfs(a,dep+1,need));
    for(int i=0;i<a.size();i++)
    {
        if(a[i].s[dep]=='0')
            a[i].s[dep]='1';
        else a[i].s[dep]='0';
    }
    res=min(res,dfs(a,dep+1,need+1));
    return res;
}

void input()
{
    scanf("%d%d",&N,&L);
    char tmp[maxl];
    for(int i=0;i<N;i++)
    {
        scanf("%s",tmp);
        insert(tmp);
    }
    for(int i=0;i<N;i++)
    {
        One tmp;
        scanf("%s",tmp.s);
        str.push_back(tmp);
    }
}

void init()
{
    root.clear();
    str.clear();
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        init();
        input();
        int res=dfs(str,0,0);
        printf("Case #%d: ",cas);
        if(res==inf)
            printf("NOT POSSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}
