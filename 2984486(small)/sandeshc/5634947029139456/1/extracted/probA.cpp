#include <bits/stdc++.h>

using namespace std;

const double eps=1e-11;
//const double pi=acos(-1.0);
typedef long long ll;
typedef long long int lli;
typedef unsigned long long ull;
typedef long double ld;

#define ff first
#define ss second
#define pb push_back
#define mkp make_pair
typedef std::pair<int,int> pii ;
typedef std::vector<int> vi ;
#define lpu(i,s,e) for(i=s;i<e;i++)
#define lpd(i,s,e) for(i=s;i>e;i--)
#define lpui(i,s,e) for(i=s;i<=e;i++)
#define lpdi(i,s,e) for(i=s;i>=e;i--)
#define abs(a) (a<0?-(a):a)
#define nl() cout << '\n'
#define nlf() cout << endl

class TimeTracker {
	clock_t start, end;
public:
	TimeTracker() {
		start = clock();
	}
	~TimeTracker() {
		end = clock();
		fprintf(stderr, "%.3lf s\n", (double)(end - start) / CLOCKS_PER_SEC);
	}
};

template <class T> inline void swap(T& a,T &b){ a^=b; b^=a; a^=b; }
template <class T> inline T min(T& a,T &b){ if(a<b) { return a; } else return b; }
template <class T> inline T max(T& a,T &b){ if(a>b) { return a; } else return b; }

# define getcx getchar_unlocked

template <class T>
void inp(T& n)//fast input function
{
	n=0;
	int ch=getcx();
	int sign=1;
	while( ch < '0' || ch > '9' )
		{if(ch=='-')sign=-1; ch=getcx();}
	while( ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
	n=n*sign;
}

template <class T>
void oup(T x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	int len=0,data[25];
	while(x)
	{
		data[len++]=x%10;
		x/=10;
	}
	if(!len)
		data[len++]=0;
	while(len--)
		putchar(data[len]+48);
	putchar('\n');
}

void complement(string& s){
	for(int i=0;i<s.length();i++){
		if(s[i]=='1') s[i]='0';
		else s[i]='1';
	}
}

string xorstring(string a,string b){
	string s = a ;
	for(int i=0;i<a.length();i++){
		if(a[i]=='1' && b[i]=='1') s[i]='0';
		else if(a[i]=='0' && b[i]=='0') s[i]='0';
		else s[i]='1';
	}
	return s;
}

bool mysearch(vector<string>& v , string key){
	for(int i=0;i<v.size();i++){
		if(v[i] == key) {
			//cout << "DEBUG : " << i << ' ' << key << ' ';
			return true;
		}
	}
	return false;
}

int main()
{
	#ifdef LOCAL
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
		TimeTracker trk;
	#endif

	int t; inp(t);
	vector<string> v1,v2,v3;
	string v;
	int i,j,n,l,tp,c;
	bool fnd,gfnd ; int min; tp=0;
	string temp ;
	while(tp<t){
		v1.clear(); v2.clear(); v3.clear();
		inp(n); inp(l); min = l+1; gfnd = false;
		lpu(i,0,n) {
			cin >> v ;
			v1.push_back(v);
		}
		lpu(j,0,n) {
			cin >> v ;
			v2.push_back(v);
		}
		lpu(i,0,n){
			v3.clear();
			v = xorstring(v1[0],v2[i]);
			lpu(j,0,n) {
				temp = xorstring(v1[j],v);
				//cout << temp << ' ';
				v3.push_back(temp);
			} //cout << endl;
			
			// lpu(j,0,n) {
			// 	cout << v1.at(j) << ' ';
			// } cout << endl;

			// lpu(j,0,n) {
			// 	cout << v2.at(j) << ' ';
			// } cout << endl;

			// lpu(j,0,n) {
			// 	cout << v3.at(j) << ' ';
			// } cout << endl;

			fnd = true;
			lpu(j,0,n){
				//cout << j << ' ';
				if(!mysearch(v3,v2[j])) { fnd=false; break; }
				//cout << endl ;
			} 
			if(fnd) {
				//cout << i << ' ' << j << endl;
				gfnd = true; 
				c=0;
				for(char ch : v) if(ch=='1') c++;
				if(min > c) { 
					min = c;
					//cout << v << ' ' << c << endl << endl;
				}
			} 
		}
		tp++;	
		cout << "Case #" << tp << ": ";
		if(gfnd) cout << min << endl;
		else cout << "NOT POSSIBLE" << endl;
	}
	return 0;
}