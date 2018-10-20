#include <algorithm>
#include <set>

using namespace std;

int N;
int X[1010];

void solve_case(){
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		X[i]=i;
	}
	vector<int> v;
	for(int i=0;i<N;++i){
		int x,k;
		scanf("%d",&x);
		for(int j=i;j<N;++j){
			if (X[j]==x){
				k=j-i;
				swap(X[i],X[j]);
				break;
			}
		}
		//printf("%d\n",k);
		v.push_back(k);
	}
	set<int> s;
	s.insert(v.begin(),v.end());
	//printf("%d %d\n",s.size(),v.size());
	if (s.size()/(double)v.size()<.5){
		puts("BAD");
	}
	else puts("GOOD");
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		solve_case();
	}
	return 0;
}

