#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream inp;
ofstream oup;
int cha(char a){
    if (a=='0') return 0;
    else return 1;   
}
bool compare1(pair<int,long> a, pair <int, int> b){
 return a.second<b.second;   
}
bool compare2(pair<int,long> a, pair <int, int> b){
 return a.first<b.first;   
}
pair <int,long> stack[150*150];
int main(){
    inp.open("input1.in");
    oup.open("output1.txt");
    int T;
    inp>>T;
    for (int t=0; t<T; t++){
        int N;
        int L;
        inp>>N>>L;
        string array[N];
        long numbers[N];
        string array2[N];
        long numbers2[N];
        for (int i=0; i<N; i++){
            inp>>array[i];
            numbers[i]=0;
            for (int j=L-1; j>=0; j--){
                numbers[i]*=2;
                numbers[i]+=cha(array[i][j]);
            }
        }
        for (int i=0; i<N; i++){
            inp>>array2[i];
            numbers2[i]=0;
            for (int j=L-1; j>=0; j--){
                numbers2[i]*=2;
                numbers2[i]+=cha(array2[i][j]);
            }
        }
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                stack[N*i+j].first=N*i+j;
                stack[N*i+j].second=numbers[i]^numbers2[j];
            }
        }
        sort(stack, stack+N*N, compare1);
        int cnt=0;
        long last=LONG_MAX;
        int mini=INT_MAX;
        for (int i=0; i<N*N; i++){
            if (last==stack[i].second){
                cnt++;   
            }
            else {
                cnt=0;   
            }
            if (cnt==N-1){
                int cntr=0;
                long tmp=stack[i].second;
                while (tmp!=0){
                    cntr++;
                    tmp-=(tmp&-tmp);   
                }
                mini=min(mini,cntr);
            }
            last=stack[i].second;
        }
        oup<<"Case #"<<t+1<<": ";
        if (mini==INT_MAX){
            oup<<"NOT POSSIBLE"<<endl;   
        }
        else {
            oup<<mini<<endl;   
        }
    }
    system("PAUSE");
       
}
