#define FROM_FILE
#define TO_FILE

//-Wl,--stack,52800000
#include <bits/stdc++.h>

using namespace std;

#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define All(n) (n).begin(), (n).end()

typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;

#ifdef FROM_FILE
ifstream fin("in.txt");
#define cin fin
#endif

#ifdef TO_FILE
ofstream fout("out.txt");
#define cout fout
#endif

const int MAXN=150 + 10;
//const int MOD=1000*1000*1000 + 7;
//const lli INF=1000000000000000000ll;

lli toNum(string s)
{
    lli x=0;
    for(int i=0;i<s.size();i++)
    {
        x*=2;
        x+=s[i]-'0';
    }
    return x;
}

int cnt(lli c)
{
    int ans=0;
    while(c)
    {
        ans+=c&1;
        c/=2;
    }
    return ans;
}

lli a[MAXN];
lli b[MAXN];
int n;
bool isG(lli pat)
{
    multiset<lli> s;
    for(int i=0;i<n;i++)s.insert(b[i]);
    for(int i=0;i<n;i++)
    {
        lli x=a[i]^pat;
        if(s.find(x)==s.end())
            return false;
        s.erase(s.find(x));
    }
    return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
    {
        int l;
        cin>>n>>l;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            a[i]=toNum(s);
        }
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            b[i]=toNum(s);
        }
        int ans=1000;
        for(int i=0;i<n;i++)
        {
            lli pat=a[0]^b[i];
            if(isG(pat))
                ans=min(ans,cnt(pat));
        }
        cout<<"Case #"<<z<<": ";
        if(ans==1000)cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
