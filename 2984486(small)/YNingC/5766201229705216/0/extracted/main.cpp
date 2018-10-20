//
//  main.cpp
//  GCJ1AB
//
//  Created by Ningchen Ying on 4/26/14.
//  Copyright (c) 2014 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define MN 1050
using namespace std;

vector<int> Edge[MN];
int ync[MN];
int cnt[MN];

int dfs(int h, int p){
	ync[h] = 0;
	cnt[h] = 1;
	int next;
    
    int l = (int)Edge[h].size();
    
	if (p==-1) next = l;
	else next = l-1;
    
	for (int i = 0;i< l; i++){
        if (Edge[h][i]!=p){
            dfs(Edge[h][i],h);
            cnt[h]+=cnt[Edge[h][i]];
        }
    }
    
	if (next==0) ;
	else if (next==1) {
		ync[h] = cnt[h]-1;
	}else {
		int A = -1, B = -1;
        
		for (int i = 0; i <l; i++){
			int cur = Edge[h][i];
            
			if (cur!=p){
				if (A==-1 || ync[cur]-cnt[cur]<ync[A]-cnt[A]){
					B = A;
					A = cur;
				}else if (B==-1||ync[cur]-cnt[cur]<ync[B]-cnt[B]){
					B = cur;
				}
			}
		}
        
		ync[h] = cnt[h]-1+ync[A]-cnt[A]+ync[B]-cnt[B];
		
	}
	return ync[h];
}

int main(int argc, const char * argv[])
{
	int T;
	int N;
    freopen("/Users/YNingC/Documents/CodeForces/GCJ1AB/GCJ1AB/B-small-attempt0.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ1AB/GCJ1AB/B-small-attempt0.out","w",stdout);
	cin>>T;
	for (int cas = 1; cas<=T; cas++){
		cin>>N;
		for (int i = 1;i <=N; i++)
			Edge[i].clear();
		for (int i = 1;i < N;i++){
            int a,b;
			cin>>a>>b;
			Edge[a].push_back(b);
            Edge[b].push_back(a);
		}
		int res = N;
		for (int i = 1; i<=N; i++){
			dfs(i,-1);
			res = min(res, ync[i]);
		}
        cout<<"Case #"<<cas<<": "<<res<<endl;
	}
}

