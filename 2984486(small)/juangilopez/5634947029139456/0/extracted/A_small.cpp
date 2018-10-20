# include <bits/stdc++.h>

using namespace std;

string flip(int idx, string pass){
    string ans = pass;
    if(pass[idx] == '0') ans[idx] = '1';
    else ans[idx] = '0';
    return ans;
}

int countBits(int mio){
     int ret = 0;
     for(int i = 0; i < 32; ++i)
          if((1 << i) & mio) ret++;
     return ret;               
}


int main(){
     int t; cin >> t;
     int cont = 0;
     while(t--){
          int n, l;
          cin >> n >> l;
          vector<string> my_devices(n);
          vector<string> my_outlets(n);
          for(int i = 0; i < n; ++i)
               cin >> my_outlets[i];
          for(int i = 0; i < n; ++i)
               cin >> my_devices[i];
          
          int maxn = 1 << l;
          //cout<<maxn<<endl;
          int ans = 1<<30;
          
          for(int i = 0; i <= maxn; ++i){
               int mask_actual = i;
               int idx = 0;
               vector<string> my_newoutlets(n);
               my_newoutlets = my_outlets;
               //cout<<mask_actual<<endl;
               for(int j = 0; j <= l; ++j){
                    if((1 << j) & mask_actual){
                         if(j >= l) continue;
                         
                 //        cout<<"cambio bit: "<<j<<" pos vector: "<<l - j - 1<<endl;
                         for(int k = 0; k < n; ++k){
                              my_newoutlets[k] = flip(l - j - 1, my_newoutlets[k]);
                   //           cout<<my_outlets[k]<<" cambio a: "<<my_newoutlets[k]<<endl;
                         }
                     //    cout<<endl;
                    }
               }
               //cout<<endl;
               int matched = 0;
               for(int j = 0; j < n; j++){
                    string actual = my_devices[j];
                    bool flag = false;
                    //cout<<actual<<": ";
                    for(int k = 0; k < n; ++k){
                      //   cout<<my_newoutlets[k]<<" ";
                         if(actual ==  my_newoutlets[k]){
                              flag = true;
                              break;
                         }
                    }
                    //cout<<endl;
                    if(!flag) break;
                    else matched++;
                    //cout<<matched<<endl;
               }
               //cout<<endl;
               //cout<<matched<<" "<<countBits(mask_actual)<<endl;
               if(matched == n && countBits(mask_actual) < ans){
                    ans = countBits(mask_actual);
                 //   cout<<ans<<endl;
               }
          }
          if(ans >= 1 << 30) printf("Case #%d: NOT POSSIBLE\n", ++cont);
          else
               printf("Case #%d: %d\n", ++cont, ans);
     }
     return 0;
}

