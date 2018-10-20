#include <iostream>
using namespace std;
int n,l,t;
char* a[11];
char* b[11];
int dao(int i)
{
    for (int j=1; j<=n; j++)
    {
        if (a[j][i-1]=='1') a[j][i-1]='0'; else a[j][i-1]='1';
        }
    }
int xet()
{
    int k=0;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    if (strcmp(a[i], b[j])==0) k++;
    if (k==n) return 1; else return 0;
    }
int xuly(int x, int y, int z)
{
    int k=0;
    if (z==0) return xet();
    else
    {
        for (int i=x; i<=y-z+1; i++)
        {
            dao(i);
            if (xuly(i+1,y,z-1)==1) k=1;
            dao(i);
            }
        return k;
        }
    }
int main ()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for (int q=1; q<=t; q++)
    {
        cin>>n>>l;
        for (int i=1; i<=n; i++)
        {
            delete[] a[i];
            a[i]=new char[l+1];
            cin>>a[i];
            }
        for (int i=1; i<=n; i++)
        {
            delete[] b[i];
            b[i]=new char[l+1];
            cin>>b[i];
            }
        int o=0;
        while (o<=l && xuly(1,l,o)==0) o++;
        cout<<"Case #"<<q<<": ";
        if (o>l) cout<<"NOT POSSIBLE\n"; else cout<<o<<endl;
        }
    fclose(stdin);
    fclose(stdout);
    }
