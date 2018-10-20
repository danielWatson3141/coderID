#include<bits/stdc++.h>
#define sc(n) scanf("%d",&n)
#define pn(n) printf("%d\n",n)
#define slc(n) scanf("%lld",&n)
#define pln(n) printf("%lld\n",n)
#define ps(n) printf("%d ",n) //

using namespace std;

int n, A[2001], great[2001];
vector<int> close[2001];
inline void do_it(int x){
    int i;
    for(i = 0; i < close[x].size(); i++){
        if(great[x] != close[x][i]){
            great[close[x][i] ] = x;
	        do_it(close[x][i]);
	    }
    }
    int temp = 0, temp1 = 0;
    for(i = 0; i < close[x].size(); i++){
        if(temp1 <= A[close[x][i] ]){
            temp= temp1;
            temp1= A[close[x][i] ];
        }
        else
            temp= max(temp, A[close[x][i]]);
    }
    if(temp == 0 ){
        A[x] = 1;
        return;
    }
    A[x] = temp + temp1 + 1;
    return;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, ty = 1;
    cin>>t;
    while(t--){
        int i, x, y, ans1, ans;
	    sc(n);
	    for(i = 0; i <= n; i++){
	        close[i].clear();
	    }
	    for(i = 0; i < n-1; i++){
	        sc(x);
	        sc(y);
	        close[x].push_back(y);
	        close[y].push_back(x);
	    }
	    ans = 0;
	    for(i = 1; i <= n; i++){
		    for(int j = 0; j <= n; j++){
		        A[j] = 0;
		        great[j] = 0;
		    }
		    do_it(i);
			ans1 = A[i];
	        ans = max(ans1, ans);
	    }
		printf("Case #%d: %d\n",ty++,n - ans);
    }
}
