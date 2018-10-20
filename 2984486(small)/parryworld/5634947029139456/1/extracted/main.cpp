#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
//#pragma comment(linker, "/STACK:1024000000,1024000000")

#define mp make_pair
#define pb push_back
#define SCAN(n) scanf("%d",&n)
#define SCAN2(a,b) scanf("%d%d",&a,&b)
#define SCANS(a) scanf("%s",a)
#define PRINT(n) printf("%d\n",n)
#define sqr(a) ((a)*(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;

const int N=1200010;
const int M=3000010;
const int INF=1e9;
const int MOD=1e9+7;
const double eps=1e-6;

string s1[155];
string s2[155];
string s3[155];
string s4[155];
bool change[155];

void solve(){
	int t;
	cin>>t;
	for(int cs=1;cs<=t;cs++){
		int n,l;
		cin>>n>>l;
		int ans=INF;
		for(int i=1;i<=n;i++) cin>>s1[i];
		for(int i=1;i<=n;i++) cin>>s2[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				s3[j]=s1[j];
				s4[j]=s2[j];
			}
			int cnt=0;
			swap(s4[i],s4[1]);
			for(int j=0;j<l;j++){
				if(s3[1][j]!=s4[1][j]){
					cnt++;
					for(int k=2;k<=n;k++){
						s3[k][j]=1-(s3[k][j]-'0')+'0';
					}
				}
			}
			if(cnt>=ans) continue;
			sort(s3+2,s3+n+1);
			sort(s4+2,s4+n+1);
			for(int j=2;j<=n;j++){
				if(s3[j]!=s4[j]){
					cnt=INF;
					break;
				}
			}
			ans=ans<cnt?ans:cnt;
		}
		if(ans==INF) cout<<"Case #"<<cs<<": "<<"NOT POSSIBLE"<<endl;
		else cout<<"Case #"<<cs<<": "<<ans<<endl;
	}
}

int main()
{
   	freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    //ios :: sync_with_stdio(false);
    solve();
    return 0;
}
