//
//  main.cpp
//  ProperO
//
//  Created by Liubing Yu on 4/25/14.
//  Copyright (c) 2014 Liubing Yu. All rights reserved.
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
    
    
    int T,N,L,M,i,j,k,sw,ones,num;
    
    for(i=0;i<101;i++){
        //  cout<<i<<" "<<poss[i]<<" "<<xl[i]<<" "<<yl[i]<<endl;
    }
    fin.open ("/Users/liubingyu/Desktop/C-small-attempt1.in");
    fout.open("/Users/liubingyu/Desktop/C-small-attempt1.out.txt");
    fin>>T;
    //  std::cout << T<<"Hello, World!\n";
    for(j=0;j<T;j++){
        fin>>N;
        ones=0;
        for(i=0;i<N;i++){
            fin>>num;
            if(num==i)ones++;
        }

        if(ones>=1){
            fout<<"Case #"<<j+1<<": BAD\n";
            cout<<"Case #"<<j+1<<": BAD\n";
        }
        else{
            fout<<"Case #"<<j+1<<": GOOD\n";
            cout<<"Case #"<<j+1<<": GOOD\n";
        }
        
    }
    fin.close();
    fout.close();
    return 1;
    
}