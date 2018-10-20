#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int n ;

map< vector<int> , int> mymap ;

void dfsbad(vector<int> v,int limit ,int now){
    if (now==limit){
        mymap[v]++ ;
    }else{
        for (int i=0;i<limit;i++)
        {
            swap(v[now],v[i]);
            dfsbad(v,limit,now+1) ;
            swap(v[now],v[i]);
        }
    }
}

void dfsgood(vector<int> v,int limit ,int now){
    if (now==limit){
        mymap[v]++ ;
    }else{
        for (int i=now;i<limit;i++)
        {
            swap(v[now],v[i]);
            dfsgood(v,limit,now+1) ;
            swap(v[now],v[i]);
        }
    }
}

int main(){
    freopen("output.txt","w",stdout);
    for (int N=4;N<=8;N++){
        vector<int> gao(N);
        for (int i=0;i<N;i++)
            gao[i]=i;
        mymap.clear() ;
        dfsbad(gao,N,0);

        vector < pair<int , vector<int> > > v ;
        for (map< vector<int> , int>::iterator it = mymap.begin() ; it != mymap.end() ; it++){

            v.push_back(make_pair(-(*it).second,(*it).first));
        }
        sort(v.begin() , v.end()) ;
        for (int i = 0 ; i < 20 ; i++){
            for (int j = 0 ; j < N ; j++)
                printf("%d " , v[i].second[j]);
            printf(" : %d \n" , -v[i].first);
        }

        printf("_____________________________________________\n") ;

        for (int i = v.size() - 1 ; i >= v.size() - 20 ; i--)
        {
            for (int j = 0 ; j < N ; j++)
                printf("%d " , v[i].second[j]);
            printf(" : %d \n" , -v[i].first);
        }
        printf("_____________________________________________\n") ;
    }
    return 0 ;
}
