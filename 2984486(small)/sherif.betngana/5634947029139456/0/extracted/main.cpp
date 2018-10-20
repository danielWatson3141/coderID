#include <iostream>
#include<vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#define READ(s) freopen(s, "r", stdin)
#define WRITE(s) freopen(s, "w", stdout)
using namespace std;
string bin(int a,int n)
{
    string res="";
    while (a>0)
    {
        int c=a%2;
        c+=48;
        char s=char(c);
        res=res+s;
        a=a/2.0;
    }
    while(res.size()<n)
    {
        res+="0";
    }
    return res;
}
string conv(string s,string e)
{
    for(int i=0; i<e.size(); i++)
    {
        if(e[i]=='1')
        {
            if(s[i]=='0')
                s[i]='1';
            else
                s[i]='0';
        }
    }
    return s;
}
int main()
{
    READ("A-small-attempt1 (1).in");
    WRITE("A-small-attempt1 (1).out");
    int T,n,l;
    string e,d;
    cin>>T;
    for(int i=0; i<T; i++)
    {
        cin>>n>>l;
        cin.ignore(1000,'\n');
        getline(cin,e);
        getline(cin,d);
        int fnl=0;
        int min=999999999;
        bool flg=false;
        vector<string> flow;
        vector<string> devcs;
        for (int j=0; j<e.size(); j+=l+1)
        {
            string tm;
            tm=e.substr(j,l);
            flow.push_back(tm);
            if(flow.size()==n)
                break;
        }
        for (int j=0; j<d.size(); j+=l+1)
        {
            string tm;
            tm=d.substr(j,l);
            devcs.push_back(tm);
            if(devcs.size()==n)
                break;
        }
        int per=pow(2,l);
        for(int e=0; e<=per; e++)
        {
            string cur=bin(e,l);
            vector<string> temp;
            if(e!=0)
            {
                for(int s=0; s<n; s++)
                {
                    temp.push_back(conv(flow[s],cur));
                }
            }
            if(e==0)
                temp=flow;
            int cnt=0;
            for(int s=0; s<n; s++)
            {
                for(int u=0; u<n; u++)
                {
                    if(temp[s]==devcs[u])
                    {
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt==n)
            {
                flg=true;
                for(int k=0; k<cur.size(); k++)
                {
                    if(cur[k]=='1')
                        fnl++;
                }
                if(fnl<min)
                    min=fnl;
            }
        }
        if(flg==true)
            cout<<"Case #"<<i+1<<": "<<min<<endl;
        else
            cout<<"Case #"<<i+1<<": NOT POSSIBLE"<<endl;
    }
    return 0;
}
