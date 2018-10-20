#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;


void print(vector<string>& istring){
  for(int i=0;i<istring.size();++i){
  cout<<"istring = "<<istring[i]<<endl;
  }
}

void flipbit( vector<string>& istring, int bitmask, int l){
 for(int k=0;k<istring.size();++k){
  for(int i=0;i<l;++i){
    if( bitmask&(1<<i) ){
      istring[k][i] = istring[k][i] == '0'? '1': '0';
    }
  }
 }
}

int countbits(int mask){
  int count=0; 
  while(mask){
    mask &= mask - 1;
    count++;
  }
  return count;
}

bool check(vector<string>& ivec, vector<string>& fvec){
  bool found = true;
  for(int i=0;i<ivec.size();++i){
    vector<string>::iterator it = find(fvec.begin(), fvec.end(), ivec[i]);
    if( it == fvec.end()){
      found = false;
      break;
    }
  }
  return found;
}

main(){
  int t;
  //scanf("%d", &t);
  string ts;
  std::getline(cin, ts);
  stringstream tss(ts);
  string num;
  tss>>num;
  t=atoi(num.c_str());
  for(int i=1;i<=t;++i){
    int n,l;
    string data, t;
    std::getline(cin, data);
    stringstream ss(data);
    ss >> t;
    n=atoi(t.c_str());
    ss >> t;
    l=atoi(t.c_str());
    string init,tmp;
    string fin;
    std::getline(cin, init) ;
    std::getline(cin, fin) ;
//cout<<"init = "<<init<<endl;
//cout<<"fin = "<<fin<<endl;
    vector<string> istrings;
    vector<string> fstrings;
    stringstream ss1(init);
    stringstream ss2(fin);
    while(ss1>>tmp){
//cout<<"istring = >"<<tmp<<endl;
      istrings.push_back(tmp);
    }
    while(ss2>>tmp){
      fstrings.push_back(tmp);
    } 

  int total = pow((double)2, l);
//cout<<"total = "<<total<<endl;
  int ans=-1;
  for(int j=0;j<=total;++j){
    vector<string> newvec = istrings;
    flipbit(newvec, j, l);
//cout<<"after flipping "<<endl;
//    print(newvec);
    if(check(newvec, fstrings)){
//cout<<"FOUND"<<endl;
      ans = countbits(j); 
      break;
    }
  }
  if(ans == -1)
    printf("Case #%d: NOT POSSIBLE\n", i);
  else
    printf("Case #%d: %d\n",i,ans);
  } 
}
