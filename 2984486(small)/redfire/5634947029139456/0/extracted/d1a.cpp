/* @author Ishita Gupta*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vvi vector< vi >
#define vs vector<string>
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define fori(s,e) for(ll i=s;i<=e;i++)
#define forj(s,e) for(ll j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define aa first
#define bb second
using namespace std;
string a[200],b[200],c[200];

int main()
{
    ios::sync_with_stdio ( false );
    int t,i,j,k,m,n,x,y,L;
      freopen ( "A-small-attempt0.in","r",stdin );
      freopen ( "A.txt","w",stdout );
    cin>>t;
    rep ( T,1,t )
    {
        cin>>n>>L;
        fori ( 0,n-1 )
        {
            cin>>a[i];
        }
        fori ( 0,n-1 )
        {
            cin>>b[i];
        }
        int poss=1,ans=imax,flag;
        sort ( a,a+n );
        //fori ( 0,n-1 ) cout<<b[i]<<endl;
        ll tot= ( 1LL << L )-1;
        fori ( 0,tot )
        {
            int sb=0;
            fork(0,n-1) c[k]=b[k];
            forj ( 0,L-1 )
            {
                if ( ( 1LL<<j ) &i ) //flip jth bit
                {
                    sb++;
                    fork ( 0,n-1 )
                    {

                        if ( b[k][j]=='0' )
                        {
                            c[k][j]='1';
                        }
                        else
                        {
                            c[k][j]='0';
                        }
                    }
                }
                /*else //no flip
                {
                    fork ( 0,n-1 )
                    {
                        c[k][j]=b[k][j];
                    }
                }*/
            }
            sort ( c,c+n );
            flag=0;
           // cout<<"c arr\n";
           // fork ( 0,n-1 ) cout<<c[k]<<endl;
            fork ( 0,n-1 )
            {
                if ( a[k].compare ( c[k] ) !=0 )
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                ans=min(ans,sb);
        }
        /*
        fori(0,L-1)
        {
            if(a[0][i]==b[0][i]) flag=1;
            else flag=0;
            forj(1,n-1)
            {
                if(flag==1 && a[j][i]==b[j][i]);
                else if (flag==0 && a[j][i]!=b[j][i]);
                else
                {
                    poss=-1;
                    break;
                }
            }
            if(poss==-1) break;
            if(flag==0) ans++;
        }*/
        printf ( "Case #%d: ",T );
        if ( ans==imax )
        {
            printf ( "NOT POSSIBLE\n" );
        }
        else
        {
            printf ( "%d\n",ans );
        }
    }
    return 0;
}

