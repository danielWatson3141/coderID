#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<bitset>
#include<vector>
#include<climits>
using namespace std;

int main(){
   int T; scanf("%d",&T);
   for(int cs=0; cs<T; cs++){
      int N,L; scanf("%d%d",&N,&L);
	  string src[N];
	  string dest[N];
	  for(int i=0; i<N; i++) cin>>src[i];
	  for(int i=0; i<N; i++) cin>>dest[i];
	  sort(dest,dest+N);
	  int minval=INT_MAX;
	  for(int i=0; i<N; i++){
	     // try to match dest[0] with src[i]
		 vector<int> v;
		 for(int j=0; j<L; j++){
		    if (dest[0][j]!=src[i][j]) v.push_back(j);
		 }
		 if (v.size()>=minval) continue;
		 string tmp[N];
		 for(int i=0; i<N; i++){
		    tmp[i]=src[i];
			for(int j=0; j<v.size(); j++){
			   if (tmp[i][v[j]]=='0') tmp[i][v[j]]='1';
			   else tmp[i][v[j]]='0';
			}
		 }
		 sort(tmp,tmp+N);
		 bool valid=true;
		 for(int i=0; i<N; i++){
		    if (dest[i]!=tmp[i]){ valid=false; break;}
		 }
		 if (valid) minval=v.size();
	  }
	  printf("Case #%d: ",cs+1);
	  if (minval==INT_MAX) puts("NOT POSSIBLE");
	  else cout<<minval<<endl;
   }
}