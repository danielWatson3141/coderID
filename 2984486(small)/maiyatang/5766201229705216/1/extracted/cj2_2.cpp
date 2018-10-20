#include<fstream>
using namespace std;
ifstream fin ("B-large.in");
ofstream fout ("B-large.out");
int save[1000];
int node[2000][2];
bool old[1000];
int visit (int now)
{
    old[now]=true;
    int head=save[now];
    int max1=0,max2=0;
    while (head!=-1)
    {
        int temp=0;
        if (old[node[head][0]]==false) temp=visit (node[head][0]);
        if (temp>max1&&temp>max2) {max2=max1;max1=temp;}
        else if (temp>max2) {max2=temp;}
        head=node[head][1];
    }
    if (max1<=0||max2<=0) return 1;
    else return max1+max2+1;
}
int main ()
{
    int t;
    fin>>t;
    int i;
    for (i=1;i<=t;i++)
    {
        int n;
        fin>>n;
        int j,k;
        for (j=0;j<n;j++)
            save[j]=-1;
        int p=0;
        for (j=0;j<n-1;j++)
        {
            int a,b;
            fin>>a>>b;
            a--;
            b--;
            node[p][0]=b;
            node[p][1]=save[a];
            save[a]=p;
            p++;
            node[p][0]=a;
            node[p][1]=save[b];
            save[b]=p;
            p++;
        }
        int maxl=0;
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++) old[k]=false;
            int temp=visit(j);
            if (temp>maxl) maxl=temp;
        }
        fout<<"Case #"<<i<<": "<<n-maxl<<endl;
    }
    return 0;
}
