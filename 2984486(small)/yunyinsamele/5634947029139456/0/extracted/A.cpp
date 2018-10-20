#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

int ans;

vector <string> outlet,plugin;
int N,L;

void dfs(int m,vector <int>& pos)
{
    //cerr<<"now pos: "<<m<<" "<<pos.size()<<endl;
    //cerr<<"N " <<N<<endl;
    if(pos.size()>=ans) return ;
    if(m==L)
    {
        vector <string> now;
        now.clear();
        for(int i=0;i<N;i++) now.push_back(outlet[i]);
        //cerr<<"======"<<endl;
        //cout<<N<<endl;
        //cerr<<now.size()<<endl;
        //for(int i=0;i<N;i++) cerr<<now[i]<<" ";
        //cerr<<endl;
        //cerr<<"====="<<endl;
        for(int i=0;i<pos.size();i++)
        {
            int t = pos[i];
            for(int j=0;j<N;j++)
            {
                now[j][t] = now[j][t]=='0'?'1':'0';
            }
        }
        sort(now.begin(),now.end());
        //cerr<<"==="<<endl;
       // cerr<<now.size()<<endl;
       // for(int i=0;i<N;i++) cerr<<now[i]<<" ";
      //  cerr<<endl;
      //   cerr<<"==="<<endl;
        for(int i=0;i<N;i++)
        {
            if(now[i]!=plugin[i]) return;
        }
        ans = pos.size();
    }
    int ox=0,px=0;
    for(int i=0;i<N;i++)
    {
        if(plugin[i][m]=='0') px++;
        if(outlet[i][m]=='0') ox++;
    }
    //cerr<<m<<" "<<px<<" "<<ox<<endl;
    if(px==ox) dfs(m+1,pos);
    if(px==N-ox)
    {
        pos.push_back(m);
        dfs(m+1,pos);
        pos.pop_back();
    }
}

int main()
{
    int T;
    string tmp;

    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
cin>>T;
    for(int cnt = 1;cnt<=T;cnt++)
    {
        cin>>N>>L;
        outlet.clear();
        plugin.clear();
        for(int i=0;i<N;i++) { cin>>tmp; outlet.push_back(tmp); }
        for(int i=0;i<N;i++) { cin>>tmp; plugin.push_back(tmp); }
        ans = L+1;
        vector <int> pos;
        sort(plugin.begin(),plugin.end());
       // for(int i=0;i<N;i++) cerr<<plugin[i]<<" ";
       // cerr<<endl;
        pos.clear();
        dfs(0,pos);
        printf("Case #%d: ",cnt);
        if(ans==L+1) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
