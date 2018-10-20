#include <set>
#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

typedef unsigned long long flow_t;



int popCount(flow_t t){
    int counter = 0;
    while(t!=0){
        if(t%2!=0)
            counter++;
        t>>=1;
    }
    return counter;
}

int N;
int L;
flow_t devices[150];
flow_t outlets[150];

bool flowComp(flow_t a, flow_t b){
    int pa = popCount(a);
    int pb = popCount(b);
    //printf("C: %lld %lld\n",a,b);
    //printf("P: %d %d\n",pa,pb);
    if(pa==pb){
        return a<b;
    }
    else{
        return pa<pb;
    }
}

flow_t solve(bool& worked){
    worked = true;
    set<flow_t,bool (*)(flow_t,flow_t)> seenChanges(flowComp);
    flow_t changeRequired[150][150];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            changeRequired[i][j] = devices[i]^outlets[j];
            seenChanges.insert(changeRequired[i][j]);
        }
    }
    for(flow_t f : seenChanges){
        bool seen[150];
        bool success = true;
        for(int i=0;i<150;i++){
            seen[i] = false;
        }
        //for each device
        for(int i=0;i<N;i++){
            bool anythingSeen = false;
            //find the outlet with the corresponding change
            for(int j=0;j<N;j++){
                if(changeRequired[i][j]==f){
                    anythingSeen = true;
                    if(seen[j]){
                        success = false;
                    }
                    //printf("I,J: %d,%d,%llx\n",i,j,f);
                    seen[j] = true;
                    break;
                }
            }
            if(!anythingSeen)
                success = false;
            //printf("N: %d\n",success);
            if(!success)
                break;
        }

        if(success){
            return f;
        }
    }
    worked = false;
    return 0;
}


flow_t inputFlow(){
    flow_t res = 0;
    string data;
    cin >> data;
    for(int i=0;i<L;i++){
        if(data[i]=='1'){
            res |= (1ULL<<(L-i-1));
        }
    }
    //printf("I: %lld\n",res);
    return res;
}

int main(){
    int ncases;
    cin >> ncases;
    for(int c=1;c<=ncases;c++){
        cin >> N >> L;
        for(int i=0;i<N;i++){
            outlets[i] = inputFlow();
        }
        for(int i=0;i<N;i++){
            devices[i] = inputFlow();
        }
        bool succ = false;
        flow_t res = solve(succ);
        //printf("R: %lld\n",res);
        if(succ){
            printf("Case #%d: %d\n",c,popCount(res));
        }
        else{
            printf("Case #%d: NOT POSSIBLE\n",c);
        }
    }
}
