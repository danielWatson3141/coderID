// Ideone_Language_Id:1
/* Don't remove the first line! */
#include <bits/stdc++.h>
/*more #includes. Don't write "using namespace std" here*/

#ifdef __WIN32__
#define getchar_unlocked getchar
#endif
//Input-output macros
#define s(n) scan(&n)
#define sf(n) scanf("%f",&n)
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
// Useful constants
#define INF (int)1e9
#define MOD 1000000007
#define EPS 1e-9
// Useful hardware instructions
#define bitcount __builtin_popcount
#define lz __builtin_clz
#define tz __builtin_ctz
#define gcd __gcd
// Useful container manipulation / traversal macros
#define forall(i,a,b) for(int i=a;i<b;i++)
#define forrev(i,a,b) for(int i=a;i>b;i--)
#define foreach(v,c) for(typeof((c).begin()) v=(c).begin();v!=(c).end();++v)
#define all(a) a.begin(),a.end()
#define in(a,b) ((b).find(a)!=(b).end())
#define pb push_back
#define fill(a,v) memset(a,v,sizeof a)
#define sz(a) ((int)(a.size()))
#define mp make_pair
#define checkbit(n,b) ((n>>b)&1)
#define DREP(a) sort(all(a));a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define re return
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int > ii;
typedef vector<ii > vii;
typedef vector<string> vs;
typedef vector<vi > vvi;
typedef istringstream iss;
typedef ostringstream oss;

/*Faster input functions*/
void scan(int* i){int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
void scan(long long int* i){long long int t=0;char c;bool negative=false;c=getchar_unlocked();while(c<'0'||c>'9'){if(c=='-')negative=true;c=getchar_unlocked();}while(c>='0'&&c<='9'){t=(t<<3)+(t<<1)+c-'0';c=getchar_unlocked();}if(negative)t=~(t-1);*i=t;}
/*debug functions*/
#ifdef DEBUG
	#define debug(args...) {dbg,args;std::cout<<std::endl;}
#else
	#define debug(args...) // Just strip off all debug tokens
#endif
struct debugger{template<typename T> debugger& operator ,(const T& v){std::cout<<v<<" ";return *this;}}dbg;
template <typename T1,typename T2> inline std::ostream& operator<<(std::ostream& os,const std::pair<T1,T2>& p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::vector<T>& v){std::string delim="[";for(unsigned int i=0;i < v.size();i++){os<<delim<<v[i];delim=", ";}return os<<"]";}
template<typename T>inline std::ostream&operator<<(std::ostream& os,const std::set<T>& v){std::string delim="[";for (typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}
template<typename T1,typename T2>inline std::ostream&operator<<(std::ostream& os,const std::map<T1,T2>& v){std::string delim="[";for (typename std::map<T1,T2>::const_iterator ii=v.begin();ii!=v.end();++ii){os<<delim<<*ii;delim=", ";}return os<<"]";}

int toInt(string a){int i; iss(a)>>i; return i;}
string toString(int a){oss ss;ss<<a;return ss.str();}

/*structs and typedefs*/
vi prob;
int n,l;
int f(int i, long long mask,vs& a, vs& b){
	if(i==sz(prob))
		return __builtin_popcountll(mask);
	//debug(i,prob[i],mask);
	int e=-1,g=-1;
	vs c,d;
	forall(j,0,n){
		c.pb(a[j].substr(0,prob[i]+1));
		d.pb(b[j].substr(0,prob[i]+1));
	}
	forall(j,0,prob[i]){
		if(mask&(1<<j)){
			forall(k,0,n){
				c[k][j]= ((c[k][j]=='1'?'0':'1'));
			}
		}
	}
	sort(all(c));
	sort(all(d));
	if(c==d){
		e = f(i+1,mask,a,b);
	}
	forall(k,0,n){
		c[k][prob[i]]= ((c[k][prob[i]]=='1'?'0':'1'));
	}
	sort(all(c));
	sort(all(d));
	if(c==d){
		g = f(i+1,mask|(1LL<<prob[i]),a,b);
	}
	//debug(e,g);
	//debug(c);
	//debug(d);
	if(e!=-1 && g!=-1){
		return min(e,g);
	}
	else if(e==-1){
		return g;
	}
	else if(g==-1){
		return e;
	}

}
int main(int argc, char const *argv[])
{
	/* code */
	int T;
	s(T);
	forall(t,0,T){
		prob.clear();

		s(n);
		s(l);
		vs a,b;
		string u;
		vi o1(l,0),o2(l,0);

		forall(i,0,n){
			cin>>u;
			a.pb(u);
			forall(j,0,l)if(u[j]=='1')o1[j]++;
		}
		forall(i,0,n){
			cin>>u;
			b.pb(u);
			forall(j,0,l)if(u[j]=='1')o2[j]++;
		}
		int flag = 0;
		int count = 0;
		//debug(a,b,o1,o2);

		forall(i,0,l){
			if(o1[i]==o2[i]){
				if(o1[i]==n-o2[i]){
					prob.pb(i);
				}
				else continue;
			}
			else if(o2[i] == n-o1[i]){
				//debug(i);
				count++;
				forall(j,0,n){
					a[j][i]=((a[j][i]=='1')?'0':'1');
				}
			}
			else{
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			cout<<"Case #"<<t+1<<": NOT POSSIBLE\n";
			continue;
		}

		sort(all(a));
		sort(all(b));
		//debug(a,b);
		if(a==b){
			cout<<"Case #"<<t+1<<": "<<count<<"\n";
		}
		else{
			int ans = f(0,0,a,b);
			if(ans == -1)
				cout<<"Case #"<<t+1<<": NOT POSSIBLE\n";
			else{
				cout<<"Case #"<<t+1<<": "<<count+ans<<"\n";
			}
		}
	}
	return 0;
}
