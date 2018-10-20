//
//  main.cpp
//  ChangingChaos
//
//  Created by Liubing Yu on 4/25/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
//

//
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;


ifstream fin;    // Input file stream
ofstream fout;   //Output file stream

int main(int argc, const char * argv[])
{
    
    
    int T,N,L,M,i,j,k,sw,ones;
    char tempc;
    long long num,templ,match1,Match_Ch;
    vector<long long> init, requ;
    unordered_map<long long, int> ReFlow;
    
    for(i=0;i<101;i++){
        //  cout<<i<<" "<<poss[i]<<" "<<xl[i]<<" "<<yl[i]<<endl;
    }
    fin.open ("/Users/liubingyu/Desktop/A-small-attempt2.in");
    fout.open("/Users/liubingyu/Desktop/A-small-attempt2.out.txt");
    fin>>T;
    //  std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        fin>>N>>L;
        init.clear();
        ReFlow.clear();
        requ.clear();
        for(i=0;i<N;i++){
            num=0;
            for(k=0;k<L;k++){
                fin>>tempc;
                num=((num <<1)|(tempc - '0'));
               
            }
           //  cout<<num<<endl;
            init.push_back(num);
        }
        for(i=0;i<N;i++){
            num=0;
            for(k=0;k<L;k++){
                fin>>tempc;
                num=((num <<1)|(tempc - '0'));
                
            }
           // cout<<num<<endl;
            requ.push_back(num);
            ReFlow[num]=1;
        }
        sw=50;
        for(i=0;i<N;i++){
            match1=requ[i];
            templ=requ[i]^init[0];
            for(k=0;k<N;k++){
                Match_Ch=init[k]^templ;
                if(ReFlow.find(Match_Ch)==ReFlow.end()) break;
            }
            if(ReFlow.find(Match_Ch)==ReFlow.end()) continue;
            ones=0;            
            for(k=0;k<L;k++){
               // cout<<templ;
                if(templ&1)ones++;
                templ=(templ>>1);
            }
            sw=min(sw,ones);
        }
        if(sw==50){
        fout<<"Case #"<<j+1<<": NOT POSSIBLE\n";
        cout<<"Case #"<<j+1<<": NOT POSSIBLE\n";
        }
        else{
            fout<<"Case #"<<j+1<<": "<<sw<<"\n";
            cout<<"Case #"<<j+1<<": "<<sw<<"\n";
        }
        
    }
    fin.close();
    fout.close();
    return 1;
    
}


