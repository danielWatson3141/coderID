#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<iomanip>

int main(int argc,char* argv[]){
    if(argc!=2){
        std::cerr<<"filename missing\n";
        return 1;
    }
    std::ifstream ifs(argv[1]);
    std::ofstream ofs("output.txt");
    std::string str;
    int T;
    ifs>>T;
    for(int CASE=0;CASE++<T;){
        std::cout<<"Solving Case "<<CASE<<"...\n";
        int n,l;
        ifs>>n>>l;
        std::vector<int> outlets;

        std::vector<int> tablets;
        char omats[n][l];
        char tmats[n][l];
        int tmp;
        for(int i=0;i<n;i++){
            ifs>>str;
            tmp=0;
            for(int j=0;j<l;j++){
                tmp*=2;
                tmp+=str.at(j)-'0';
            }
            outlets.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            ifs>>str;
            
            tmp=0;
            for(int j=0;j<l;j++){
                tmp*=2;
                tmp+=str.at(j)-'0';
            }
            tablets.push_back(tmp);
        }

        sort(tablets.begin(),tablets.end());
        int ret=l+1;
        for(long i=0;i<(1<<l);i++){
            
            int count=0;
            for(int j=0;j<l;j++){
                if(i&(1<<j)) count++;
            }
            if(count>=ret) continue;
                std::vector<int> outlets2;
            for(int j=0;j<n;j++){
                outlets2.push_back(outlets[j]^i);
            }
        sort(outlets2.begin(),outlets2.end());
            bool flag=true;
            for(int j=0;j<n;j++){
                if(outlets2[j]!=tablets[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ret=count;
            }
        }
        if(ret==l+1)
        ofs<<"Case #"<<CASE<<": "<< "NOT POSSIBLE"<<"\n";
        else{
                    ofs<<"Case #"<<CASE<<": "<< ret<<"\n";
        }
    }
    
    
    
    return 0;
}