#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)

#define INF 1000000000
#define N 155
vector<int> code[N];
vector<int> plug[N];

int answer;
int n,m;

void saiki(vector<int>& rev){
	
	//rep(i,rev.size())printf("%d",rev[i]);puts("");
	
	
	vector<int> check[N];
	rep(i,n){
		rep(j,rev.size()){
			check[i].push_back(code[i][j]^rev[j]);
		}
	}
	sort(check, check+n);
	
	/*
	printf("plug:");
	rep(i,n){rep(j,rev.size())printf("%d",plug[i][j]);printf(" ");}printf("\n");
	printf("code:");
	rep(i,n){rep(j,rev.size())printf("%d",check[i][j]);printf(" ");}printf("\n");
	*/
	bool ok = true;
	rep(i,n){
		rep(j,rev.size()){
			if(plug[i][j]!=check[i][j])ok=false;
		}
	}
	if(!ok)return;
	
	if(rev.size()==m){
		int sum = 0;
		rep(i,rev.size()){
			sum += rev[i];
		}
		answer = min(answer, sum);
		//puts("YES");
		return;
	}
	
	rev.push_back(0);
	saiki(rev);
	rev.pop_back();
	
	rev.push_back(1);
	saiki(rev);
	rev.pop_back();
}

int main(){
	int T;
	cin>>T;
	rep(t,T){
		cin>>n>>m;
		rep(i,2){
			rep(j,n){
				string str;
				cin>>str;
				vector<int> a;
				rep(k,m){
					if(str[k]=='1')a.push_back(1);
					if(str[k]=='0')a.push_back(0);
				}
				if(i==0)code[j]=a;
				if(i==1)plug[j]=a;
			}
		}
		
		sort(plug, plug+n);
		
		answer = INF;
		saiki(vector<int>());
		
		
		printf("Case #%d: ",t+1);
		
		if(answer!=INF)printf("%d\n",answer);
		else printf("NOT POSSIBLE\n");
	}
}

/*
3
3 2
01 11 10
11 00 10
2 3
101 111
010 001
2 2
01 10
10 01

*/