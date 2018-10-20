#include <algorithm>

using namespace std;

int N,L;
char outlet[160][50];
char device[160][50];
int flip[50];

void solve_case(){
	scanf("%d %d",&N,&L);
	for(int i=0;i<N;++i){
		scanf("%s",outlet[i]);
	}
	for(int i=0;i<N;++i){
		scanf("%s",device[i]);
	}
	int vys=-1;
	vector<long long> A;
	for(int i=0;i<N;++i){
		long long x=0;
		for(int j=0;j<L;++j){
			x|=device[i][j]=='1'?(1LL<<j):0;
		}
		A.push_back(x);
	}
	sort(A.begin(),A.end());
	for(int i=0;i<N;++i){
		for(int j=0;j<L;++j){
			flip[j]=outlet[0][j]==device[i][j]?0:1;
		}
		vector<long long> B;
		for(int j=0;j<N;++j){
			long long x=0;
			for(int k=0;k<L;++k){
				x|=((outlet[j][k]-'0')^flip[k])?(1LL<<k):0;
			}
			B.push_back(x);
		}
		sort(B.begin(),B.end());
		int ok=1;
		for(int j=0;j<N;++j){
			if (A[j]!=B[j]){
				ok=0;
				break;
			}
		}
		if (ok){
			int cur=0;
			for(int j=0;j<L;++j){
				if (flip[j]) cur++;
			}
			if (vys==-1||cur<vys) vys=cur;
		}
	}
	if (vys==-1) puts("NOT POSSIBLE");
	else printf("%d\n",vys);
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

