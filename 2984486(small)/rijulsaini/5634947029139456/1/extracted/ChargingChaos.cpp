#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

const int inf = 10000;
int n,l,t; string a[200], b[200]; int v[1000];

int main(){
  ios_base::sync_with_stdio(false);
  int i1,i,j,p,q;
  cin>>t;
  for(i1 = 1; i1<=t;i1++){
    cin>>n>>l;
    for(i=0;i<n;i++){
      cin>>a[i]; //scanf("%s",a[i]);
    }
    for(i=0;i<n;i++){
      cin>>b[i];
    }
    sort(b,b+n);
    int ans = inf; int flag;
    for(i=0;i<n;i++){
      q=0;
      for(j=0;j<l;j++){
	if(a[0][j] != b[i][j]){
	  for(p = 1; p<n;p++){
	    if(a[p][j] == '0'){
	      a[p][j] = '1';
	    }
	    else{
	      a[p][j] = '0';
	    }
	  }
	  v[q] = j;
	  q++;
	}
      }
      sort(a+1,a+n); flag =1;
      /*if(i==2){
	for(j=1,p=0;j<n;j++,p++){
	  if(p==i)continue;
	  cout<<a[j]<<" "<<b[p]<<endl;
	}
      }*/
      for(j=1,p=0;j<n && flag;j++,p++){
	if(p==i){
	  j--;
	}
	else if(a[j] != b[p]){
	  flag = 0;
	}
      }
      if(flag == 1){
	ans = min(ans,q);
      }
      for(j=0;j<q;j++){
	for(p=1;p<n;p++){
	  if(a[p][v[j]] == '0'){
	    a[p][v[j]] = '1';
	  }
	  else{
	    a[p][v[j]] = '0';
	  }
	}
      }
    
    }
    cout<<"Case #"<<i1<<": ";
    if(ans == inf){
      cout<<"NOT POSSIBLE\n";
    }
    else{
      cout<<ans<<'\n';
    }
  }
  return 0;
}