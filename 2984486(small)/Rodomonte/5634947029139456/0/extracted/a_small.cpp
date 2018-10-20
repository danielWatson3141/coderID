// Round 1A
// Problem A Small

#include <stdio.h>
#include <vector>
using namespace std;
#define vc vector<char>
#define vvc vector<vector<char> >
#define pb push_back

int N,L;
int eval(vvc a, vvc b, int l){
	if(l == L){
		char f,f2;
		int i,j,k;
		for(i = 0; i < N; i++){
			f = 0;
			for(j = 0; j < b.size(); j++){
				f2 = 1;
				for(k = 0; k < L; k++){
					if(a[i][k] != b[j][k]){
						f2 = 0;
						break;
					}
				}
				if(f2){
					f = 1;
					b.erase(b.begin()+j);
					break;
				}
			}
			if(!f)
				return 0;
		}
		return 1;
	}else if(l == L-1){
		int i,j,r1,r2;
		vvc b2;
		for(i = 0; i < N; i++){
			vc bn;
			for(j = 0; j < L; j++)
				bn.pb(b[i][j]);
			b2.pb(bn);
		}
		r1 = eval(a,b,l+1);
		if(r1)
			return 0;
		for(i = 0; i < N; i++)
			a[i][l] = (a[i][l] == 1) ? 0 : 1;
		r2 = eval(a,b2,l+1);
		if(r2)
			return 1;
		return -1;
	}else{
		int i,j,r1,r2;
		vvc b2;
		for(i = 0; i < N; i++){
			vc bn;
			for(j = 0; j < L; j++)
				bn.pb(b[i][j]);
			b2.pb(bn);
		}
		r1 = eval(a,b,l+1);
		for(i = 0; i < N; i++)
			a[i][l] = (a[i][l] == 1) ? 0 : 1;
		r2 = eval(a,b2,l+1);
		if(r1 == -1 && r2 == -1)
			return -1;
		if(r1 == -1)
			return r2+1;
		if(r2 == -1)
			return r1;
		return (r1 < r2+1) ? r1 : r2+1;
	}
}
int main(){
	char c;
	int T,ti, i,j,r;
	vvc a,b;
	FILE *fi = fopen("a_small.in","r"),
		*fo = fopen("a_small.out","w");
	fscanf(fi,"%d\n",&T);
	for(ti = 1; ti <= T; ti++){
		fscanf(fi,"%d %d\n",&N,&L);
		a.clear(); b.clear();
		for(i = 0; i < N; i++){
			vc an;
			for(j = 0; j < L; j++){
				fscanf(fi,"%c",&c);
				an.pb((c == '1')?1:0);
			}
			a.pb(an);
			fscanf(fi,"%c",&c);
		}
		for(i = 0; i < N; i++){
			vc bn;
			for(j = 0; j < L; j++){
				fscanf(fi,"%c",&c);
				bn.pb((c == '1')?1:0);
			}
			b.pb(bn);
			if(!(ti == T && i == N-1))
				fscanf(fi,"%c",&c);
		}
		r = eval(a,b,0);
		if(r == -1)
			fprintf(fo,"Case #%d: NOT POSSIBLE\n",ti);
		else
			fprintf(fo,"Case #%d: %d\n",ti,r);
	}
	fclose(fi); fclose(fo);
	return 0;
}
