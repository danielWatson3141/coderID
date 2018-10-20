#include<stdio.h>
#include<vector>
#include<map>
#include<set>
#include<string>
#include <unordered_set>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip> 
#include <algorithm>
using namespace std;
bool checkValid(vector<long long>& o,vector<long long>& d){
    sort(o.begin(),o.end());
    sort(d.begin(),d.end());
    for(int i=0;i<o.size();++i){
        if(o[i]!=d[i])return false;
    }
    return true;
}
void turnSwitch(vector<long long>& o,vector<bool>& configure){
    long long mask=0;
    long long catched=0;
    long long ind=1;
    for(int i=configure.size()-1;i>=0;--i){
        if(configure[i]){
            mask|=ind;
        }
        ind=ind<<1;
    }
    for(int i=0;i<o.size();++i){
        long long tmp=o[i]&mask;
        tmp=~tmp;
        tmp=tmp&mask;
        o[i]&=~mask;
        o[i]|=tmp;
    }
}
int main(){
    ifstream fi("F:/draft/A-small-attempt0.in");
    ofstream fo("F:/draft/A-small-attempt0.out");
    //ifstream fi("F:/draft/in.txt");
    //ofstream fo("F:/draft/out.txt");
    int T=0;
    fi>>T;
    
    for(int caseInd=1;caseInd<=T;++caseInd){
        int N,L;
        fi>>N>>L;
        vector<long long> vecOutlet(N,0);
        vector<long long> vecDevices(N,0);
        for(int i=0;i<N;++i){
            string tmp;
            fi>>tmp;
            long long ind=1;
            for(int j=tmp.length()-1;j>=0;--j){
                if(tmp[j]=='1'){
                    vecOutlet[i]|=ind;
                }
                ind=ind<<1;
            }
        }
        for(int i=0;i<N;++i){
            string tmp;
            fi>>tmp;
            long long ind=1;
            for(int j=tmp.length()-1;j>=0;--j){
                if(tmp[j]=='1'){
                    vecDevices[i]|=ind;
                }
                ind=ind<<1;
            }
        }
        //map<long long,int> deviceNum;
        int min=-1;
        int curTmp=0;
        while(curTmp<=L){
            vector<bool> configures(L,false);
            for(int j=0;j<curTmp;++j){
                configures[j]=true;
            }
            while(true){
                vector<long long> tmpOutlet=vecOutlet;
                turnSwitch(tmpOutlet,configures);
                if(checkValid(tmpOutlet,vecDevices)){
                    min=curTmp;
                    break;
                }
                bool hasTurn =false;
                for(int j=configures.size()-2;j>=0;--j){
                    if(configures[j]&&(!configures[j+1])){
                        configures[j]=false;
                        configures[j+1]=true;
                        hasTurn=true;
                        int tmpcur=j+2;
                        for(int k=tmpcur;k<configures.size();++k){
                            if(configures[k]){
                                configures[tmpcur]=true;
                                ++tmpcur;
                            }
                        }
                        while(tmpcur<configures.size()){
                            configures[tmpcur]=false;
                            ++tmpcur;
                        }
                        break;
                    }
                }
                if(!hasTurn)break;
                
            }
            ++curTmp;
            if(min>=0)break;
        }
        if(min>=0)
            fo<<"Case #"<<caseInd<<": "<<min<<"\n";
        else
            fo<<"Case #"<<caseInd<<": NOT POSSIBLE"<<"\n";
    }
   
    
    return 0;
}