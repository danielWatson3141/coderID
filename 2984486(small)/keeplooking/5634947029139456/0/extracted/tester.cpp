#include<bits/stdc++.h>
#define sc(n) scanf("%d",&n)
#define pn(n) printf("%d\n",n)
#define slc(n) scanf("%lld",&n)
#define pln(n) printf("%lld\n",n)
#define ps(n) printf("%d ",n) //
using namespace std;
string S[150],S1[150],S2[150];
long long int A[150],C[150];
int n,l;
bool conv()
{
	for(int i=0;i<n;i++){
		C[i]=0;
		for(int j=l-1;j>=0;j--){
			C[i]*=2;
			if(S2[i][j]=='1')
				C[i]++;
		}
	}
	sort(C,C+n);
	for(int i=0;i<n;i++){
		if(A[i]!=C[i])
			return 0;
	}
	return 1;
}
void flip(int j)
{
	for(int i=0;i<n;i++){
		if(S2[i][j]=='1')
			S2[i][j]='0';
		else
			S2[i][j]='1';
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t,ty = 1;
	int ans,ans1;
	bool found;
	cin>>t;
	while(t--){
		cin>>n>>l;
		found=0;
		for(int i=0;i<n;i++)
			cin>>S[i];
		for(int i=0;i<n;i++)
			cin>>S1[i];
		for(int i=0;i<n;i++){
			A[i]=0;
			for(int j=l-1;j>=0;j--){
				A[i]*=2;
				if(S1[i][j]=='1')
					A[i]=A[i]+1;
			}
		}
		sort(A,A+n);
		for(int i=0;i<n;i++){
			ans=0;
			for(int k=0;k<n;k++){
				S2[k]=S[k];
			}
			for(int j=0;j<l;j++){
				if(S[0][j]!=S1[i][j]){
					flip(j);
					ans++;
					//cout<<S[0][j]<<S1[i][j]<<j<<endl;
				}
			}
			if (conv()==1){
				//found=1;
				//break;
				if(found==0){
					ans1=ans;
					found=1;
				}
				else{
					if(ans<ans1)
						ans1=ans;
				}
			}
		}
		if(found==1)
			printf("Case #%d: %d\n",ty++,ans1);
		else
			printf("Case #%d: NOT POSSIBLE\n",ty++);
	}
}
