// Round 1A
// Problem B Small

#include <stdio.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int> >
#define pb push_back

int N;
int size(vvi a, char* v, int i){
	int j, c = 1;
	v[i] = 1;
	for(j = 0; j < a[i].size(); j++){
		if(v[a[i][j]])
			continue;
		c += size(a, v, a[i][j]);
	}
	//printf("  SIZE %d: %d\n",i,c);
	return c;
}
int eval(vvi a, char* v, int r, int i){
	v[i] = 1;
	if(i == r){
		if(a[i].size() == 0)
			return 0;
		if(a[i].size() == 1)
			return size(a, v, a[i][0]);
		if(a[i].size() == 2)
			return eval(a, v, r, a[i][0]) + eval(a, v, r, a[i][1]);
		int m1 = 1000, m2 = 1000, m1i = 0, m2i = 0, c = 0, j,t;
		char v2[1001];
		for(j = 0; j <= N; j++)
			v2[j] = v[j];
		for(j = 0; j < a[i].size(); j++){
			t = eval(a, v, r, a[i][j]);
			if(t < m1)
				m2 = m1, m2i = m1i, m1 = t, m1i = a[i][j];
			else if(t < m2)
				m2 = t, m2i = a[i][j];
		}
		for(j = 0; j < a[i].size(); j++)
			if(a[i][j] != m1i && a[i][j] != m2i)
				c += size(a, v2, a[i][j]);
		if(m1 < 1000) c += m1;
		if(m2 < 1000) c += m2;
		return c;
	}
	if(a[i].size() == 1)
		return 0;
	if(a[i].size() == 2)
		return (v[a[i][0]]) ? size(a, v, a[i][1]) : size(a, v, a[i][0]);
	if(a[i].size() == 3){
		int j, c = 0;
		for(j = 0; j < 3; j++){
			if(v[a[i][j]])
				continue;
			c += eval(a, v, r, a[i][j]);
		}
		return c;
	}
	int m1 = 1000, m2 = 1000, m1i = 0, m2i = 0, c = 0, j,t,p;
	char v2[1001];
	for(j = 0; j <= N; j++)
		v2[j] = v[j];
	for(j = 0; j < a[i].size(); j++){
		if(v[a[i][j]]){
			p = a[i][j];
			continue;
		}
		t = eval(a, v, r, a[i][j]);
		if(t < m1)
			m2 = m1, m2i = m1i, m1 = t, m1i = a[i][j];
		else if(t < m2)
			m2 = t, m2i = a[i][j];
	}
	for(j = 0; j < a[i].size(); j++){
		if(a[i][j] == p)
			continue;
		if(a[i][j] != m1i && a[i][j] != m2i)
			c += size(a, v2, a[i][j]);
	}
	if(m1 < 1000) c += m1;
	if(m2 < 1000) c += m2;
	return c;
}
int main(){
	int T,ti, X,Y, i,j,k,e,r;
	char v[1001];
	vvi a;
	FILE *fi = fopen("b_small.in","r"),
		*fo = fopen("b_small.out","w");
	fscanf(fi,"%d\n",&T);
	for(ti = 1; ti <= T; ti++){
		//printf("\nCASE %d:\n\n",ti);
		fscanf(fi,"%d\n",&N);
		a.clear();
		for(i = 0; i <= N; i++){
			vi an;
			a.pb(an);
		}
		for(i = 1; i < N; i++){
			fscanf(fi,"%d %d\n",&X,&Y);
			a[X].pb(Y);
			a[Y].pb(X);
		}
		r = 1000;
		for(i = 1; i <= N; i++){
			vvi ac;
			for(j = 0; j <= N; j++){
				vi an;
				for(k = 0; k < a[j].size(); k++)
					an.pb(a[j][k]);
				ac.pb(an);
				v[j] = 0;
			}
			e = eval(ac, v, i, i);
			//printf("ROOT %d: %d\n",i,e);
			r = (e < r) ? e : r;
		}
		fprintf(fo,"Case #%d: %d\n",ti,r);
	}
	fclose(fi); fclose(fo);
	return 0;
}

