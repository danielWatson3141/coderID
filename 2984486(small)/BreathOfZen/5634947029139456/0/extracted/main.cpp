#include <iostream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
int getDist(string str1, string str2, int &flips){
	int score=0;
	flips=0;
	for(int i=0;i<(int)str1.length();i++){
		if(str1.at(i)!=str2.at(i)){
			score++;
			flips+=pow(2,i);
		}
	}
	return score;
}
int  putVal(int val, vector<int> &vals,bool index){
	for(int i=0;i<(int)vals.size();i++){
		if(val==vals[i]){
//			cout<<"same"<<i;
			return i;
		}
		if (val<vals[i]&&index){
			vals.insert(vals.begin()+i,val);
	//		cout<<"less"<<i;
			return i;
		}
	}
	vals.push_back(val);
//	cout<<"more"<<(int)vals.size()-1;
	return (int)vals.size()-1;
}
	 bool pushBit(vector<int> &bitLocs,int bit, int n,int r){
//		 cout<<endl<<bitLocs[bit]<<"<"<<bit<<"<"<<n<<"<"<<r;
		 if(bitLocs[bit]<(n-r+bit)){
			 bitLocs[bit]++;
		 }else{
			 if(bit==0){
				 return false;
			 }
			 bool found=pushBit(bitLocs,bit-1,n,r);
			 if(found){
				bitLocs[bit]=bitLocs[bit-1]+1;
			 }
			 return found;
		 }
		 return true;
	 }
	 int sign(int val){
		 if (val>0){
			 return 1;
		 }
		 if (val<0){
			 return -1;
		 }
		 return 0;
	 }
	 int abs(int val){
		 if (val<0){
			 return -val;
		 }
		 return val;
	 }
	 vector<vector<int> > nPr(int n, int r){
		 vector<vector<int> > output;
		 vector<int> bitLocs;
		 for(int i=0;i<r;i++){
			 bitLocs.push_back(i);
		 }
		 bool going=true;
		 while (going){
			 vector<int> line;
			 for(int i=0;i<n;i++){
				 line.push_back(0);
			 }
			 for(int i=0;i<(int)bitLocs.size();i++){
				 line[bitLocs[i]]=1;
			 }
			 output.push_back(line);
			 if(r>0){
				going=pushBit(bitLocs,r-1,n,r);			 
			 }else{
				 going=false;
			 }
		 }
		 return output;
	 }
int main()
{
    //freopen("c:/loadfiles/codejam/input.txt", "r", stdin);
    freopen("c:/loadfiles/downloads/A-small-attempt0.in","r",stdin);
	freopen("c:/loadfiles/codejam/outputCPP.txt", "w", stdout);
    int trials;
    cin >> trials;
    for (int trial = 1; trial <= trials; ++trial) {
		vector<string> outlets,devices;
		int N,L;
		printf("Case #%d: ", trial);
		cin>>N>>L;
		for(int i=0;i<N;i++){
			string d;
			cin>>d;
			outlets.push_back(d);
		}
		for(int i=0;i<N;i++){
			string d;
			cin>>d;
			devices.push_back(d);
		}
		map<int, map<int, vector < pair<int,int> > > > scoreMap;
		vector<int> scores;
		vector<int> flips;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				int flip;
				
				int score=getDist(outlets[i],devices[j],flip);
				putVal(score,scores,true);
				int out=putVal(flip,flips,false);
			//	cout<<flip<<" "<<out<<endl;	
				scoreMap[score][out].push_back(make_pair(i,j));
			}
		}
		bool found=false;
		for(int i=0;i<(int)scores.size()&&!found;i++){
			int score=scores[i];
			for(int j=0;j<(int)scoreMap[score].size()&&!found;j++){
				vector<pair<int, int> > pairs=scoreMap[score][j];
		//		cout<<score<<" "<<j<<" "<<pairs.size()<<endl;
				if((int)pairs.size()<N) continue;
				vector<vector<int> > perms=nPr(pairs.size(),N);
				for(int p1=0;p1<(int)perms.size()&&!found;p1++){
					vector<int> perm=perms[p1];
					vector<int> devs;
					vector<int> outs;
					for(int p2=0;p2<(int)perm.size()&&!found;p2++){
						if(perm[p2]==1){
							putVal(pairs[p2].first,outs,false);
							putVal(pairs[p2].second,devs,false);
						}
						if((int)outs.size()==N&&(int)devs.size()==N){
							cout<<score;
							found=true;
							printf("\n");
						}
					}
				}
			}

		}
		if(!found){
			cout<<"NOT POSSIBLE";
			printf("\n");
			
		}
	}
    
    return 0;
}
