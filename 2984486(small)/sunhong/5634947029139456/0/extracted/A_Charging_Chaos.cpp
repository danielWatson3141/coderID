#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
string s1[150];
string s2[150];
bool change[50];
int result,N,L;

bool check()
{
    string tmp[150];
    for (int i=0;i<N;i++)
    {
        tmp[i] = s1[i];
        for (int j=0;j<L;j++)
        {
            if (!change[j]) continue;
            if (tmp[i][j]=='1') tmp[i][j]='0';
            else tmp[i][j]='1';
        }
    }
    sort(tmp,tmp+N);
    for (int i=0;i<N;i++)
    {
        if (tmp[i].compare(s2[i])!=0) return false;
    }
    return true;
}
void search(int index)
{
    if (index>=v.size())
    {
        if (check())
        {
            int sum = 0;
            for (int i=0;i<L;i++)
            {
                if (change[i]) sum++;
            }
            result = min(result,sum);
        }
        return;
    }
    change[v[index]]=false;
    search(index+1);
    change[v[index]]=true;
    search(index+1);
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A_small_output.txt","w",stdout);
    int T;
    int c1[150];
    int c2[150];
    char str[100]; 
    scanf("%d",&T);
    for (int cases=1;cases<=T;cases++)
    {
        scanf("%d%d",&N,&L);
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        v.clear();
        for (int i=0;i<N;i++)
        {
            scanf("%s",str);
            s1[i] = str;
            for (int j=0;j<L;j++)
            {
                if (str[j]=='1') c1[j]++;
            }
        }
        for (int i=0;i<N;i++)
        {
            scanf("%s",str);
            s2[i] = str;
            for (int j=0;j<L;j++)
            {
                if (str[j]=='1') c2[j]++;
            }
        }
        sort(s2,s2+N);
        memset(change,0,sizeof(change));
        bool valid = true;
        for (int i=0;i<L;i++)
        {
            if (c1[i]!=c2[i])
            {
                if (c1[i]+c2[i]==N)
                {
                    change[i]=true;
                }else{
                    valid=false;
                    break;
                }
            }else{
                v.push_back(i);
            }
        }
        if (!valid)
        {
            printf("Case #%d: NOT POSSIBLE\n",cases);
            continue;
        }
        if (v.size()>0)
        {
            result = L+1;
            search(0);
        }else{
            result=0;
            for (int i=0;i<L;i++)
            {
                if (change[i]) result++;
            }
        }
        if (result>L) printf("Case #%d: NOT POSSIBLE\n",cases);
        else printf("Case #%d: %d\n",cases,result);
    }
    return 0;
}
