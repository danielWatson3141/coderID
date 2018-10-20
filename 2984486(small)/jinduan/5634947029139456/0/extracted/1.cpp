#include<cstdio>
#include<string> 
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int T, n,l,in[200],out[200];
int ans;
bool flag;
char c[100];

int trans(string s) {
	int ret = 0;
	for (int i=0;i<s.size();i++)
		ret = ret*2+s[i]-'0';
	return ret;
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for(int t=1;t<=T;t++) {
		ans = 1000;
		flag = 1;
		scanf("%d%d", &n, &l);
		printf("Case #%d: ", t);
		for(int i=0;i<n;i++){
			scanf("%s", c);
			in[i] = trans(c);
		}
		for(int i=0;i<n;i++){
			scanf("%s", c);
			out[i] = trans(c);
		}

		vector<set<int> > v;
		for(int i=0;i< n;i++){
			set<int> tmp;
			for(int j=0;j<n;j++){
				tmp.insert(in[i]^out[j]);
			}
			v.push_back(tmp);
		}
		set<int> tmp = v[0];
		for(int i = 1;i<n;i++){
			set<int> d;
			set_intersection(v[i].begin(), v[i].end(), tmp.begin(), tmp.end(), inserter(d, d.begin()));
			//for(set<int>::iterator j = d.begin(); j!=d.end(); j++)
			//	printf("%d ", (*j));
			tmp = d;
			//printf("\n%d\n\n", tmp.size()); 
		}
		if(tmp.size()==0){
			printf("NOT POSSIBLE\n");
			continue;
		}
		for(set<int>::iterator i = tmp.begin(); i!=tmp.end(); i++){
			int now = (*i), ttmp = 0;
			while(now>0){
				ttmp+=now%2;
				now = now >>1;
			}
			if(ans>ttmp)
				ans = ttmp;
		}
		printf("%d\n", ans);
	}
	return 0;
}
