#include<iostream>
#include<cstdio>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<iterator>
#include<functional>
#include<time.h>
#include<iomanip>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define INF 100000000000000000LL

ll diff(ll a,ll b)
{
    return a>b ? a-b : b-a;
}

/*#define COMB_NUM 10001L
ll comb[COMB_NUM][COMB_NUM];
//need init_comb();
void init_comb()
{
    comb[0][0]=1;
    ll i,j;
    for(i=1;i<COMB_NUM;i++)
    {
        comb[i][0]=comb[i][i]=1;
        for(j=1;j<i;j++)
            comb[i][j]=comb[i-1][j]+comb[i-1][j-1];
    }
}
*/

#define print(a)      for(int i=0;i<a.size();i++) cout<<a[i]<<" "; cout<<endl;
#define print2n(a,n)      for(int i=0;i<=n;i++) cout<<a[i]<<" "; cout<<endl;

void llFromString(const string &s,ll &a,ll &b)
{
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
               
    istringstream buffer(replacedString);
    buffer>>a;
    if(buffer.good())
    {
        buffer>>b;
    }
    else
    {
        b=0;
    }
}


template<class T>
vector<T> split(const std::string &s) {
    
    string replacedString = s;
    replace_if(replacedString.begin(),
               replacedString.end(),
               bind2nd(equal_to<char>(),'.'),
               ' ');
    
    vector<T> ret;
    istringstream buffer(replacedString);
    copy(istream_iterator<T>(buffer),
         istream_iterator<T>(), back_inserter(ret));
    return ret;    
}// vector<ll> k = split<ll>(s);

	bool e[1001][1001];
	ll n[1001];
	
	vector<ll> aj[1001];
	ll N;

ll dfs(ll root,ll from)
{
    if(aj[root].size()==1)
    {
        return 1;
    }
    
    //one child
    if(aj[root].size()==2 && from!=-1) return 1;
    
    vector<ll> s;
    for(ll I=0;I<aj[root].size();I++)
    {
        if(aj[root][I]==from) continue;
        s.push_back(dfs(aj[root][I],root));
    }
    sort(s.begin(),s.end(),greater<ll>());
    
    return s[0]+s[1]+1;
}

int main()
{
	fstream in,out;
	//in.open("test.in.txt",ios::in); out.open("test.out",ios::out);
	in.open("B-small-attempt0.in",ios::in); out.open("B-small-0.out",ios::out);
	//in.open("B-large.in",ios::in); out.open("B-large-0.out",ios::out);

	istream& input = in;
	ostream& output = out;
	
	ll case_id,total_case;
    input>>total_case; 
	ll I,H,K,L,M,a,b,ans;

	
	for(case_id=1;case_id<=total_case;case_id++)
	{
        ans=9999;
        
        input>>N;
        for(I=1;I<=N;I++)
        for(H=1;H<=N;H++)
        e[I][H]=0;
        
        for(I=1;I<N;I++)
        {
            input>>a>>b;
            e[a][b]=e[b][a]=1;
            aj[a].push_back(b);
            aj[b].push_back(a);
        }
        
        for(I=1;I<=N;I++)
        {
            for(H=1;H<=N;H++) n[H]=0;
            
            ans = min(ans, N-dfs(I,-1));
        }
        
        for(I=1;I<=N;I++) aj[I].clear();
        
		output<<"Case #"<<case_id<<": ";
		output<<ans;
		output<<endl;
	}
    system("PAUSE");
    return EXIT_SUCCESS;
}
