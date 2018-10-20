#include <bits/stdc++.h>




using namespace std;




#define fr(i,a,b) for(int i=a; i < b; ++i)
const int oo = 0x3f3f3f3f;

char gr[200][200], gr2[200][200], gr3[200][200];
set<string> s;
bool mud[200];
int t,n,l;


char ot(char c){
	if(c == '0') return '1';
	return '0';
}


bool ok(){
	s.clear();
	fr(i,0,n){
		string now = gr2[i];
		s.insert(now);
	}
	fr(i,0,n){
		string now = gr3[i];
		if(s.find(now) != s.end()) s.erase(now);
	}
	if(s.size()) return false;
	return true;
}


int main(){
	scanf("%d",&t);
	fr(cas,1,t+1){
		scanf("%d %d",&n,&l);
		fr(i,0,n) scanf("%s",gr[i]);
		fr(i,0,n) scanf("%s",gr2[i]), gr3[i][l] = '\0';
		int ans = oo;
		fr(i,0,n){
			memset(mud, false, sizeof mud);
			int now = 0;
			fr(j,0,l){
				if(gr[0][j] != gr2[i][j]) mud[j] = true,now++;
			}
			fr(j,0,n){ 
				fr(k,0,l){
					if(mud[k]) gr3[j][k] = ot(gr[j][k]);
					else gr3[j][k] = gr[j][k];
				}
			}
			if(ok()) ans = min(ans,now);
		}
		printf("Case #%d: ",cas);
		if(ans == oo) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
	return 0;
}














