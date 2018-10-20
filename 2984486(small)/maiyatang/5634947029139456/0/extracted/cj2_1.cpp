//#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
ifstream fin ("A-small-attempt0.in");
ofstream fout ("A-small-attempt0.out");
string save[150];
string need[150];
bool change[40];
int main ()
{
    int t;
    fin>>t;
    int i;
    for (i=1;i<=t;i++)
    {
        int n,l,j,k,x,y;
        fin>>n>>l;
        for (j=0;j<n;j++)
            fin>>save[j];
        for (j=0;j<n;j++)
            fin>>need[j];
        sort (need,need+n);
        int maxl=-1;
        for (j=0;j<n;j++)
            for (k=0;k<n;k++)
            {
                int many=0;
                for (x=0;x<l;x++)
                    if (save[j][x]==need[k][x]) change[x]=false;
                    else {change[x]=true;many++;}
                for (x=0;x<l;x++)
                    if (change[x])
                        for (y=0;y<n;y++)
                            if (save[y][x]=='1') save[y][x]='0';
                            else save[y][x]='1';
                sort (save,save+n);
                bool can=true;
                for (x=0;x<n&&can;x++)
                    if (save[x]!=need[x]) can=false;
                if (can)
                    if (maxl==-1||many<maxl) maxl=many;
                for (x=0;x<l;x++)
                    if (change[x])
                        for (y=0;y<n;y++)
                            if (save[y][x]=='1') save[y][x]='0';
                            else save[y][x]='1';
            }
        fout<<"Case #"<<i<<": ";
        if (maxl==-1) fout<<"NOT POSSIBLE\n";
        else fout<<maxl<<"\n";
    }
    return 0;
}
