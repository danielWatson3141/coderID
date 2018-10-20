#include<bits/stdc++.h>
using namespace std;

#define st_clk double st=clock();
#define end_clk double en=clock();
#define show_time cout<<"\tTIME="<<(en-st)/CLOCKS_PER_SEC<<endl;

#define f_in(st) freopen(st,"r",stdin);
#define f_out(st) freopen(st,"w",stdout);

int flip(int a){
   if(a=='0') return  '1';
   else return '0';
}


int solve(int n,int l,vector<string> init, vector<string> final){
        vector<string> in=init,f=final;
		int minCount = 1000,curCount= 0;
		for(int i=0;i<n;i++){
		     for(int j=0;j<n;j++){
		     	  if(1){
		     //	  	cout << "for : " << i << " " << j << endl;
				   curCount = 0;
		     	  in = init; f = final;
			      for(int k=0;k<l;k++){
			      //	 cout << k << " " << in[i][k] << " " << f[j][k] << endl;
				     if(in[i][k]!=f[j][k]) {
					    curCount++;
						for(int y=0;y<n;y++) in[y][k]= flip(in[y][k]);
					 }
				  }
			//	  cout << i << " " << j << " " <<curCount << endl;
				  sort(in.begin(),in.end());
				  sort(f.begin(),f.end());
			      int g,h;
				  for(g=0;g<n;g++){
				  	 for(h=0;h<l;h++)
				       if(in[g][h] != f[g][h]) break;
				     if(h!=l) break; 
				  }
				  if(g==n){
				      minCount = min(minCount,curCount);
				  }
			  } 
			 }
		}
		return minCount;
}


int main(){
	 #ifndef ONLINE_JUDGE
     f_in("in");
     f_out("out");
     #endif
     int t;
     scanf("%d",&t);
     for(int x=0;x<t;x++){
	      int n,l;
	      cin >> n >> l;
	      vector<string> init,final;
	      for(int i=0;i<n;i++){
		      string temp; cin >> temp;
		      init.push_back(temp);
		  }
		  for(int i=0;i<n;i++){
		      string temp; cin >> temp;
		      final.push_back(temp);
		  }
		  int ans = solve(n,l,init,final);
		  if(ans != 1000)
		  cout << "Case #" << x+1 << ": " << ans << endl;
		  else cout << "Case #" << x+1 << ": NOT POSSIBLE" << endl;
	 }
}

