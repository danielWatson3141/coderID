#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

struct coin
{
    string c;
};

coin a[200];
coin b[200];
int count_a[50];
int count_b[50];
int min_change;
int cmp(coin a, coin b)
{
    return a.c < b.c;
}
void bfs(int n, int l, int k, int change)
{
    if(k == l)
    {
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        for(int i = 0; i < n; i++)
        {
            if(a[i].c != b[i].c) return;
        }
        min_change = min(change, min_change);
        return;
    }

    if(count_a[k] == count_b[k])
    {
        int j;
        for(j = k+1; j < l; j++)
        {
            int count1_a = 0, count2_a = 0;
            int count1_b = 0, count2_b = 0;
            for(int i = 0; i < n; i++)
            {
                
                if(b[i].c[k] == '1' && b[i].c[j] == '1')
                    count1_b++;
                if(b[i].c[k] == '0' && b[i].c[j] == '1')
                    count2_b++;
                
                if(a[i].c[k] == '1' && a[i].c[j] == '1')
                    count1_a++;
                if(a[i].c[k] == '0' && a[i].c[j] == '1')
                    count2_a++;
            }
            //cout<<count1_b<<count1_a<<endl;
            if(!(count1_b == count1_a || count1_b + count1_a == count_a[k]))
                break;
            if(!(count2_b == count2_a || count2_b + count2_a == n - count_a[k]))
                break;
        }
        if(j >= l)
            bfs(n,l,k+1,change);
    }
    if(count_a[k] + count_b[k] == n)
    {
        int j;
        for(j = k+1; j < l; j++)
        {
            int count1_a = 0, count2_a = 0;
            int count1_b = 0, count2_b = 0;
            for(int i = 0; i < n; i++)
            {
                
                if(b[i].c[k] == '1' && b[i].c[j] == '1')
                    count1_b++;
                if(b[i].c[k] == '0' && b[i].c[j] == '1')
                    count2_b++;
                
                if(a[i].c[k] == '1' && a[i].c[j] == '1')
                    count2_a++;
                if(a[i].c[k] == '0' && a[i].c[j] == '1')
                    count1_a++;
            }
            //cout<<count1_b<<count1_a<<endl;
            if(!(count1_b == count1_a || count1_b + count1_a == count_b[k]))
                break;
            if(!(count2_b == count2_a || count2_b + count2_a == n - count_b[k]))
                break;
        }
        if(j < l) return;
        for(int i = 0; i < n; i++)
        {
            if(a[i].c[k] == '1')
                a[i].c[k] = '0';
            else
                a[i].c[k] = '1';
        }
        bfs(n,l,k+1,change+1);
        for(int i = 0; i < n; i++)
        {
            if(a[i].c[k] == '1')
                a[i].c[k] = '0';
            else
                a[i].c[k] = '1';
        }
    }
}
int main() {
    char temp[50];
    int Case = 1;
    int t,n,l,i,j;
    cin>>t;
    while(t--)
    {
        memset(count_a,0,sizeof(count_a));
        memset(count_a,0,sizeof(count_b));
        
        cin>>n>>l;
        min_change = 10000;
        
        for(j = 0; j < l;j++)
        {
            count_a[j] = 0;
            count_b[j] = 0;
        }
        
        for(i = 0; i < n; i++)
        {
            cin>>temp;
            a[i].c= temp;
            for(j = 0; j < l;j++)
            {
                if(a[i].c[j] == '1') count_a[j]++;
            }
        }
        for(i = 0; i < n; i++)
        {
            cin>>temp;
            b[i].c = temp;
            for(j = 0; j < l;j++)
            {
                if(b[i].c[j] == '1') count_b[j]++;
            }
        }
        for(i = 0; i < l; i++)
        {
            //cout<<count_a[i]<<" "<<count_b[i]<<endl;
            if(!((count_a[i] == count_b[i]) || (count_a[i]+count_b[i] == n)))
            {
                cout<<"Case #"<<Case++<<": NOT POSSIBLE"<<endl;
                break;
            }
        }
        if(i != l) continue;
        bfs(n,l,0,0);
        if(min_change > 1000)
        {
            cout<<"Case #"<<Case++<<": NOT POSSIBLE"<<endl;
        }
        else
        {
            cout<<"Case #"<<Case++<<": "<<min_change<<endl;
            
        }
        
    }
    
    return 0;
}
