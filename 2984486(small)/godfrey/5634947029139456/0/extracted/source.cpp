#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define FORD(i, a, b) for (int i(a), _b(b); i >= _b; --i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)
#define REPD(i, n) for (int i((n) - 1); i >= 0; --i)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

template<typename T> int size(const T& c) { return int(c.size()); }
template<typename T> T abs(T x) { return x < 0 ? -x : x; }
template<typename T> T sqr(T x) { return x*x; }
template<typename T> bool remin(T& x, T y) { if (x <= y) return false; x = y; return true; }
template<typename T> bool remax(T& x, T y) { if (x >= y) return false; x = y; return true; }
template<typename T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

ifstream fin("input");
ofstream fout("output");

int btoi(string str){
	int result=0;
	REP(i,str.length()){
		result*=2;
		result+=str[i]-'0';
	}
	return result;
}

int count(int x, int l){
	int result=0;
	REP(i,l){
		result+=(x>>i)&0x1;
	}
	return result;
}

string doCase(){
	int n=0,l=0;
	fin>>n>>l;
	string str;
	vector<int> list1(n);
	vector<int> list2(n);
	vector<int> temp(n);
	REP(i,n){
		fin>>str;
		list1[i]=btoi(str);
	}
	REP(i,n){
		fin>>str;
		list2[i]=btoi(str);
	}

	int result=50;
	sort(list2.begin(),list2.end());
	REP(mask,pow(2.0,l)){
		bool done=true;
		REP(i,n) temp[i]=list1[i]^mask;
		sort(temp.begin(),temp.end());
		REP(i,n){
			if(list2[i]!=temp[i]){
				done=false;
				break;
			}
		}
		int temp=count(mask,l);
		if((done)&&(temp<result)) result=temp;
	}
	if(result==50){
		return "NOT POSSIBLE";
	}else{
		return itos(result);
	}
}

int main(){
    int nn;
    fin>>nn;
    REP(ii,nn){
    	fout<<"Case #"<<ii+1<<": "<<doCase()<<endl;
    	//double: <<fixed<<setprecision(10)
    }
    return 0;
}
