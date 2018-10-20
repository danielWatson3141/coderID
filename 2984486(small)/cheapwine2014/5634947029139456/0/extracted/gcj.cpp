#include <bits/stdc++.h>
using namespace std;

#define PB(v) push_back(v)
#define PF(v) push_front(v)
#define MP(a,b) make_pair(a,b)
#define SZ(c) ((int)(c).size())
#define BG(c) (c).begin()
#define ED(c) (c).end()
#define BE(c) BG(c),ED(c)
#define TYPE(v) __typeof(v)
#define FORE(i,c) for(TYPE(ED(c))i=BG(c);i!=ED(c);++i)
#define FOR(i,a,b) for(TYPE(b)i(a),_##i(b);i<_##i;++i)
#define REP(i,n) FOR(i,0,n)
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int>VI;
typedef vector<VI>VVI;
typedef vector<LL>VL;
typedef vector<VL>VVL;
typedef vector<string>VS;
typedef vector<VS>VVS;
typedef vector<double>VD;
typedef vector<VD>VVD;
typedef pair<int,int>pii;
typedef pair<double,double>pdd;
template<class T>T& amax(T& var,const T& val){if(val>var)var=val;return var;}
template<class T>T& amin(T& var,const T& val){if(val<var)var=val;return var;}
template<class T>string vtos(const T& v){ostringstream os;os<<v;return os.str();}
template<class T>T stov(const string& s){T v;istringstream(s)>>v;return v;}
int stoi(const string& s){return atoi(s.c_str());}
LL stol(const string& s){return stov<LL>(s);}
template<class T>vector<T> stoken(const string& s){istringstream is(s);vector<T> res;T v;while(is>>v)res.PB(v);return res;}
template<class T>inline T expn(T a,unsigned n){T r=(n&1)?a:1;while(n>>=1){a*=a;if(n&1)r*=a;}return r;}
template<class T>pair<T,T> ext_euclid(T a,T b){
	if(!b)return pair<T,T>(1,0);
	pair<T,T> r=ext_euclid(b,a%b);return pair<T,T>(r.second,r.first-a/b*r.second);
}
LL permute(int n,int p)
	{LL r=p>=0;for(int i=n-p;i<n;r*=++i);return r;}
ULL combine(int n,int c){
	ULL res=1;
	for(int i=0,t=min(c,n-c);i<t;res*=n-i,res/=i+1,++i);
	return res;
}
template<class It,class T>inline bool next_combination(It b,It e,T t){
	It p=e;do if(p==b)return 0;while(*--p>--t);for(t=*p;p!=e;)*p++=++t;return 1;
}
template<class T>inline T gcd(T a,T b){while(b){T r=a%b;a=b;b=r;}return a;}
inline int rnd(){static int s=time(0);return s=s%44488*48271-s/44488*3399,s<0?s+=2147483647:s;}
inline int bct(unsigned i){
	i-=(i>>1)&0x55555555,i=(i&0x33333333)+((i>>2)&0x33333333);return i=(i+(i>>4))&0x0f0f0f0f,i+=i>>8,i+=i>>16,i&0x3f;
}
template<class T>bool isprime(T n){
	if(n<25)return n>1&&((n&1)&&(n%3)||n<4);
	if(!(n&1)||n%3==0||n%5==0||n%7==0||n%11==0||n%13==0||n%17==0||n%19==0||n%23==0)return 0;
	for(unsigned i=29,ed=unsigned(sqrt(n));i<=ed;i+=2)if(n%i==0)return 0;return 1;
}
double totaltime(){return (double)clock()/CLOCKS_PER_SEC;}
bool isvowel(char c){return c=tolower(c),c=='a'||c=='e'||c=='i'||c=='o'||c=='u';}
string sreplace(string s,string a,string b){
	string r;int p=0,np;
	while(np=s.find(a,p),np>=0)r+=s.substr(p,np-p),r+=b,p=np+SZ(a);
	return r+=s.substr(p);
}
int scount(string s,string t){int p=0,np,r=0;while(np=s.find(t,p),np>=0)++r,p=np+SZ(t);return r;}
VS ssplit(string s,string t=" "){
	VS r;int p=0,np;
	while(np=s.find(t,p),np>=0){if(np!=p)r.PB(s.substr(p,np-p));p=np+SZ(t);}
	if(p<SZ(s))r.PB(s.substr(p));return r;
}
string strim(string s){
	int p=0,q=SZ(s);while(p<q&&isspace(s[p]))p++;
	if(p<q)while(isspace(s[--q]));return s.substr(p,q-p+1);
}
bool sstartswith(const string& s1,const string& s2){
	return equal(BE(s2),BG(s1));
}
bool sendswith(const string& s1,const string& s2){
	return equal(s2.rbegin(),s2.rend(),s1.rbegin());
}

//"<<" operator for vector/set/deque/pair/map
#define ZPO {o<<'('<<SZ(v)<<"){ ";FORE(i,v)o<<'\"'<<*i<<"\" ";return o<<'}';}
#define ZPP {return o<<'('<<v.first<<','<<v.second<<')';}
#define ZPS(C) template<class T>ostream& operator<<(ostream& o,const C<T>& v)ZPO
#define ZPD(T,P) template<class K,class V>ostream& operator<<(ostream& o,const T<K,V>&v)P
ZPS(vector)ZPS(set)ZPS(deque)ZPD(map,ZPO)ZPD(pair,ZPP)
#define DBG(v) cerr<<#v<<"="<<(v)<<endl;
template<class T>vector<vector<T> > matrix_mul(const vector<vector<T> >& a,const vector<vector<T> >& b){
    vector<vector<T> > c=vector<vector<T> >(SZ(a),vector<T>(SZ(b[0])));
    REP(i,SZ(a))REP(j,SZ(b))REP(k,SZ(b[0]))c[i][k]=c[i][k]+a[i][j]*b[j][k];
    return c;
}


int n,l;

bool ok(VS a,VS b,int v){
	int n=SZ(a);
	REP(i,l){
		if(v&(1<<i)){
			REP(j,n){
				char ch=a[j][i];
				if(ch=='0')
						a[j][i]='1';
					else a[j][i]='0';
			}
		}
	}
	sort(BE(a));
	sort(BE(b));
	if(a==b)return 1;
	return 0;
}

void solve(int caseno){
	printf("Case #%d: ",caseno);
	cin>>n>>l;
	VS a(n),b(n);
	REP(i,n){
		cin>>a[i];
	}
	REP(i,n)cin>>b[i];



	//DBG(a);	DBG(b);

	int best=100;
	REP(v,1<<l){
		int ct=bct(v);
		if(ct<best && ok(a,b,v))
			best=ct;
	}

	if(best==100){
		printf("NOT POSSIBLE\n");
		return;
	}
	printf("%d\n",best);
}

int main() {
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		solve(i);
	return 0;
}
