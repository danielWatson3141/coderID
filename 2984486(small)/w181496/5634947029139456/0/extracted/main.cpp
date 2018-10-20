#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;
//#define fin cin
//#define fout cout
int l,n;
int m[11],m2[11];
ifstream fin("A-small-attempt1.in");
ofstream fout("A-small-attempt1.out");
bool chk()
{
    int t[11],t2[11];
    for(int i=0; i<l; ++i)
    {
        t[i]=m[i];
        t2[i]=m2[i];
    }
    for(int i=0; i<l; ++i)
    {
        bool chk=true;
        for(int j=0; j<l; ++j)
        {
            if(t2[j]!=-1&&t[i]==t2[j])
            {
                t2[j]=-1;
                chk=false;
            }
        }
        if(chk)return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //ifstream fin("B-large-practice.in");
    //ofstream fout("B-large-practice.out");
    int t;
    fin>>t;
    for(int i=1; i<=t; ++i)
    {
        memset(m,0,sizeof(m));
        memset(m2,0,sizeof(m2));
        fin>>l>>n;
        for(int j=0; j<l; ++j)
            for(int k=0; k<n; ++k)
            {
                char ch;
                fin>>ch;
                m[j]=m[j]*2+(ch-'0');
            }
        for(int j=0; j<l; ++j)
            for(int k=0; k<n; ++k)
            {
                char ch;
                fin>>ch;
                m2[j]=m2[j]*2+(ch-'0');
            }
        int ans=99999;
        for(int j=0; j<=(1<<n)-1; ++j)
        {
            for(int k=0; k<l; ++k)
            {
                m2[k]^=j;
            }
            if(chk())
            {
                int tmp=j,cnt=0;
                while(tmp>0)
                {
                    if(tmp%2==1)cnt++;
                    tmp/=2;
                }
                if(cnt<ans)ans=cnt;
            }
            for(int k=0; k<l; ++k)
            {
                m2[k]^=j;
            }
        }

        fout<<"Case #"<<i<<": ";
        if(ans<999)fout<<ans<<endl;
        else fout<<"NOT POSSIBLE"<<endl;
    }
    return 0;
}
