#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n,l;

struct A
{
	int sumf;
	int b;
	int f[40];
	pair<long long,long long> c[150];
	bool operator < (const A &r) const {
		if(sumf != r.sumf)
			return sumf < r.sumf;
		if(b != r.b)
			return b < r.b;
		for(int i = 0; i < l; i++)
			if(f[i] != r.f[i])
				return f[i] < r.f[i];
		return false;
	}
};

set<A> pq;

long long x0[150];
long long x1[150];

int main(){
	int tc;
	scanf("%d", &tc);
	for(int ti=1; ti<=tc; ti++){
		printf("Case #%d: ", ti);
		scanf("%d%d", &n, &l);
		char s[100];
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			x0[i] = 0;
			for(int j = 0; j < l; j++)
				if(s[j]=='1')
					x0[i] += ((long long)1)<<(l-j-1);
			// printf("%lld ", x0[i]);
		}
		// printf("\n");
		sort(x0,x0+n);
		for(int i = 0; i < n; i++){
			scanf("%s", s);
			x1[i] = 0;
			for(int j = 0; j < l; j++)
				if(s[j]=='1')
					x1[i] += ((long long)1)<<(l-j-1);
			// printf("%lld ", x1[i]);
		}
		// printf("\n");
		A a;
		a.sumf=0; a.b=l-1; for(int i = 0; i < l; i++)a.f[i] = 0;
		for(int i = 0; i < n; i++)a.c[i] = make_pair(0,x1[i]);
		pq.clear();
		pq.insert(a);
		bool isdone=false;
		while(pq.size()>0){
			A h = *pq.begin();
			// printf("%d %d\n", h.sumf, h.b);
			pq.erase(pq.begin());
			if(h.b == -1){
				printf("%d\n", h.sumf);
				isdone = true;
				break;
			}
			A t = h;
			for(int i = 0; i < n; i++)
				if( ((t.c[i].second) & (((long long)1)<<t.b))>0)
				t.c[i].first += ((long long)1)<<t.b;
			sort(t.c,t.c+n);
			long long m = ((((long long)1)<<(l-t.b))-1)<<t.b;
			bool z=true;
			for(int i = 0; i < n; i++){
				// printf("(%lld,%lld)",(t.c[i].first & m), (x0[i] & m));
				if((t.c[i].first & m) != (x0[i] & m))
					z = false;
			}
			// printf("\n");
			t.f[t.b]=0;
			t.sumf+=0;
			t.b = t.b-1;
			if(z)
				pq.insert(t);
			
			t = h;
			for(int i = 0; i < n; i++)
				if( ((t.c[i].second) & (((long long)1)<<t.b))==0)
				t.c[i].first += ((long long)1)<<t.b;
			// for(int i = 0; i < n; i++)printf("a%lld ", t.c[i].first);printf("\n");
			sort(t.c,t.c+n);
			// for(int i = 0; i < n; i++)printf("b%lld ", t.c[i].first);printf("\n");
			z=true;
			for(int i = 0; i < n; i++){
				// printf("(%lld,%lld)",(t.c[i].first & m), (x0[i] & m));
				if((t.c[i].first & m) != (x0[i] & m))
					z = false;
			}
			// printf("\n");
			t.f[t.b]=1;
			t.sumf+=1;
			t.b = t.b-1;
			if(z)
				pq.insert(t);


		}
		if(!isdone){
			printf("NOT POSSIBLE\n");
		}


	}
}