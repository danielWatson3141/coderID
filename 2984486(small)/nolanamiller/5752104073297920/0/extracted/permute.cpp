//
//  main.cpp
//  code_jam_q1
//
//  Created by Nolan Miller on 4/12/14.
//  Copyright (c) 2014 Nolan Miller. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <sstream>
#include <climits>
#include <cmath>
#include <queue>

using namespace std;


int main(int argc, const char * argv[])
{

    int SIZE = 1000000;
    srand((uint)time(0));
    int N = 1000;
    int ** histbad = new int*[N];
//    int ** histgood = new int*[N];
    for (int i = 0; i<N; i++) {
        histbad[i] = new int[N];
//        histgood[i] = new int[N];
        for (int ii = 0; ii<N; ii++) {
            histbad[i][ii] = 0;
//            histgood[i][ii] = 0;
        }
    }
    for (int c = 0; c<SIZE; c++) {
        
        int * arrayb = new int[N];
//        int * arrayg = new int[N];
        for (int k = 0; k<N; k++) {
//            arrayg[k] = k;
            arrayb[k] = k;
        }
//        for (int k = 0; k<N; k++) {
//            int p = (rand()%(N-k))+k;
//            int tmp = arrayg[p];
//            arrayg[p] = arrayg[k];
//            arrayg[k] = tmp;
//        }
        for (int k = 0; k<N; k++) {
            int p = rand()%N;
            int tmp = arrayb[p];
            arrayb[p] = arrayb[k];
            arrayb[k] = tmp;
        }
        for (int i = 0; i<N; i++) {
            histbad[i][arrayb[i]]++;
//            histgood[i][arrayg[i]]++;
        }
    }
//    for (int i = 0; i<N; i++) {
//        for (int ii = 0; ii<N; ii++) {
//            histgood[i][ii] = SIZE/N;
//        }
//    }
    long sqrsum = 0;
    for (int c = 0; c<SIZE; c++) {
        int * arrayg = new int[N];
        //        int * arrayg = new int[N];
        for (int k = 0; k<N; k++) {
            //            arrayg[k] = k;
            arrayg[k] = k;
        }
        for (int k = 0; k<N; k++) {
            int p = (rand()%(N-k))+k;
            int tmp = arrayg[p];
            arrayg[p] = arrayg[k];
            arrayg[k] = tmp;
        }
        long base_score = 0;
        for (int i = 0; i<N; i++) {
            base_score+=histbad[i][arrayg[i]];
        }
        base_score-=SIZE;
        sqrsum += base_score*base_score;
    }
    long avesqr = sqrsum/SIZE;
    long stdv = (long)sqrt((double)avesqr);
    
    
    
    
    int t;
    cin>>t;
    for (int i = 0; i<t; i++) {
        int n;
        cin>>n;
        int * input = new int[n];
        for (int x = 0; x<n; x++) {
            cin>>input[x];
        }
//        long gscore = 0;
        long bscore = 0;
        
        for (int x = 0; x<n; x++) {
//            gscore+= histgood[x][input[x]];
            bscore+= histbad[x][input[x]];
        }
        
        if (bscore > SIZE + stdv)
            cout<<"Case #"<<i+1<<":"<<" BAD";
        else
            cout<<"Case #"<<i+1<<":"<<" GOOD";
        if(i+1!=t)
            cout<<endl;
    }
    return 0;
}
