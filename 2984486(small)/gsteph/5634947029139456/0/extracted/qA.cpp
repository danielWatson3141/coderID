#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct entry{
	unsigned long long diff;
	int ind;
	entry(unsigned long long _d, int _i){
		diff = _d;
		ind = _i;
	}
	entry(){}
};

bool cmp(const entry &a, const entry &b){
	if (a.diff<b.diff) return true;
	else if (a.diff==b.diff) return a.ind<b.ind;
	else return false;
}

int compar (const void* a, const void* b){
	const entry *ea = (const entry*)a;
	const entry *eb = (const entry*)b;
	if (ea->diff<eb->diff) return -1;
	else if (ea->diff==eb->diff) return 0;
	else return 1;
}

entry diff[150][150];
unsigned long long a[150],b[150];
char tmps[41];

int eval(int N, int L){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			diff[i][j].diff = a[i]^b[j];
			diff[i][j].ind = j;
		}
		sort(diff[i],diff[i]+N,cmp);
	}
	for (int i = 0; i < N; i++){
		int tst[N];
		int r =0;
		memset(tst,-1,sizeof tst);
		long long mask = diff[0][i].diff;
		tst[0] = diff[0][i].ind;
		for (int j = 1; j < N; j++){
			entry *bs = (entry*) bsearch(new entry(mask,0),diff[j],N,sizeof(entry),compar);
			if (!bs) goto fail;
			if (tst[j]==-1) tst[j] = bs->ind;
			else goto fail;
		}
		
		for (int m = 0; m < 64; m++){
			if (mask&(1LL<<m)) r++;
		}
		return r;
		fail:;
	}
	return -1;
}
int main(){
	//freopen("test.in","r",stdin);
	freopen("A-small-attempt2.in","r",stdin);
	freopen("A-small-attempt2.out","w",stdout);
	int T,N,L;
	cin >> T;
	for (int t = 0; t < T; t++){
		memset(diff,0,sizeof diff);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		cin >> N >> L;
		
		for (int i = 0; i < N; i++){
			cin >> tmps;
			for (int j = 0; j < L; j++){
				if (tmps[j]=='1')a[i]|=1LL<<(j);
			}
		}
		for (int i = 0; i < N; i++){
			cin >> tmps;
			for (int j = 0; j < L; j++){
				if (tmps[j]=='1')b[i]|=1LL<<(j);
			}
		}
		
		cout << "Case #" << t+1 << ": ";
		int ret = eval(N,L);
		
		for (int i = 0; i < N; i++){
			unsigned long long tmp;
			tmp = a[i];
			a[i]=0;
			for (int j = 0; j < L; j++) {
				if (tmp&(1LL<<j)) a[i] |= (1LL<<(L-j-1));
			}
			tmp = b[i];
			b[i]=0;
			for (int j = 0; j < L; j++) {
				if (tmp&(1LL<<j)) b[i] |= (1LL<<(L-j-1));
			}
		}
		ret = min(ret,eval(N,L));
		if (ret==-1) cout << "NOT POSSIBLE" << endl;
		else cout << ret << endl;
		
		/*for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				diff[i][j].diff = a[i]^b[j];
				diff[i][j].ind = j;
			}
			sort(diff[i],diff[i]+N,cmp);
		}
		cout << "Case #" << t+1 << ": ";
		for (int i = 0; i < N; i++){
			int tst[N];
			int r =0;
			memset(tst,-1,sizeof tst);
			long long mask = diff[0][i].diff;
			tst[0] = diff[0][i].ind;
			for (int j = 1; j < N; j++){
				entry *bs = (entry*) bsearch(new entry(mask,0),diff[j],N,sizeof(entry),compar);
				if (!bs) goto fail;
				if (tst[j]==-1) tst[j] = bs->ind;
				else goto fail;
			}
			
			for (int m = 0; m < 64; m++){
				if (mask&(1LL<<m)) r++;
			}
			cout << r << endl;
			goto done;
			fail:;
		}
		cout << "NOT POSSIBLE" << endl;
		done:;*/
		
	}
	return 0;
}
