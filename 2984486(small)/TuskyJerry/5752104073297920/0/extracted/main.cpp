#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>

int a[1001],f[1001];
using namespace std;


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	ios :: sync_with_stdio(false);
    int t,n;
    cin>>t;
    int x;
    for (int k=1;k<=t;k++)
    {
        cin>>n;
        cout<<"Case #"<<k<<": ";
        for (int i=0;i<=n-1;i++) cin>>a[i];
        int perm=0;
        for (int i=n-2;i>=0;i--)
        {
            for (int j=i+1;j<=n-1;j++)
            if ((a[i]==j) or (a[j]==i))
            {
                perm++;
                x=a[i];
                a[i]=a[j];
                a[j]=x;
            }
        }
        int flag=1;
        for (int i=0;i<=n-1;i++)
        {
            if (a[i]!=i)
            {
                flag=0;
                break;
            }
        }
        if ((flag==1) and (perm*10>n*8))
        cout<<"GOOD"<<endl;
        else
        cout<<"BAD"<<endl;
    }
    return 0;
}
