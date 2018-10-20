#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <cctype>
using namespace std;
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FORS(i,s) for(int i=0;(s)[i];i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define CLR(s) memset(s,0,sizeof(s))
typedef long long LL;
#define PB push_back
#define INF 1000000000

int n;
int x[1111];
vector<double> cs,cs2;

double pos(int i){
	return (i - ((n-1)*0.5)) / ((n-1)*0.5);
}
int main() {
	if(false){
		n = 1000;
		int NIT = 10000;
		double avc = 0.0, avc2=0.0;
		double avu = 0.0, avu2=0.0;
		double avv = 0.0, avv2=0.0;
		double avy = 0.0, avy2=0.0;
		FOR(it,0,NIT){
			srand(it*21);
			FOR(k,0,n) x[k] = k;
			FOR(k,0,n){
				int p = (rand()+rand()+rand()+rand()+rand()+rand()) % n;
				//int p = (rand()+rand()+rand()+rand()+rand()+rand()) % (n-k) + k;
				swap(x[k], x[p]);
			}
			double c = 0.0,u,v,y=0.0;
			FOR(k,0,n){
				c += pos(x[k])*pos(k);
				if(x[k] == n-1) u = pos(k);
				if(x[k] > k) y += 1.0;
				else if(x[k] < k) y -= 1.0;
			}
			v = pos(x[n-1]);
			c /= n;
			y /= n;
			avc += c; avc2 += c*c;
			avu += u; avu2 += u*u;
			avv += v; avv2 += v*v;
			avy += y; avy2 += y*y;
			cs.push_back(c);
			//FOR(k,0,n) printf("%d\n", x[k]);
		}
		avc /= NIT; avc2 = sqrt(avc2/NIT - avc*avc);
		avu /= NIT; avu2 = sqrt(avu2/NIT - avu*avu);
		avv /= NIT; avv2 = sqrt(avv2/NIT - avv*avv);
		avy /= NIT; avy2 = sqrt(avy2/NIT - avy*avy);
		printf("%.9f  %.9f\n", avc, avc2);
		printf("%.9f  %.9f\n", avu, avu2);
		printf("%.9f  %.9f\n", avv, avv2);
		printf("%.9f  %.9f\n", avy, avy2);
		sort(cs.begin(),cs.end());
		printf("%.9f\n", cs[NIT/2]);
		return 0;
	}
	
	
	cs.clear(); cs2.clear();
	
int nt; scanf("%d", &nt); FOR(tt,0,nt){
	scanf("%d", &n);
	FOR(i,0,n) scanf("%d", &x[i]);
	double c = 0.0;
	FOR(k,0,n){
		//c += (x[k] - ((n-1)*0.5))*(k - ((n-1)*0.5));
		if(x[k] > k) c += 1.0;
		else if(x[k] < k) c -= 1.0;
	}
	cs.push_back(c);
	cs2.push_back(c);

}	
sort(cs2.begin(),cs2.end());
FOR(tt,0,nt){
	printf("Case #%d: ", tt+1);
	if(cs[tt] >= cs2[nt/2]) printf("BAD\n"); else printf("GOOD\n");
}
return 0;
}


