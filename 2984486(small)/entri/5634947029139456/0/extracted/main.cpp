#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int T,N,L;
vector<string> Inp,Inp0, Out, Out0;
const int INF = 1000000;

void printIt(vector<string> X){
    cout <<endl;
    for(int i = 0; i<X.size(); i++)
        cout <<X[i]<<" ";
    cout<<endl;
}

bool checkSwitch(int k){
    bool res = false;
    //printIt(Inp);
    //printIt(Out);
    //cout <<"check it at "<<k<<endl;
    for(int i = 0; i<N; i++){
        if (Inp[i][k] != Out[i][k]) return res;
    }
    return true;
}
void SwitchIt(int k){
    for(int i =0; i<N; i++)
        Inp[i][k] = '0' + ('1' - Inp[i][k]);
}


void rollIt(){
    for(int i = 0; i<N; i++){
        Inp0[i] = Inp0[i].substr(1) + Inp0[i][0];
        Out0[i] = Out0[i].substr(1) + Out0[i][0];
    };
}


void solveIt(int N, int L){

int res = INF;

for(int ii = 0; ii<L; ii++){
    if (ii>0){
        //move:
        rollIt();
    };
    Inp = Inp0;
    Out = Out0;
    sort(Out.begin(), Out.end());
    sort(Inp.begin(), Inp.end());
    int cnt = 0;
    bool possible = true;
    for(int k = 0; k<L; k++){
        if (checkSwitch(k) == false){
            SwitchIt(k);
            cnt++;
            sort(Inp.begin(), Inp.end());
            if (!checkSwitch(k)){ // again:
                //cout <<"NOT POSSIBLE"<<endl;
                //return;
                possible = false;
                break;
            };
        };
    };// for k

    if (possible) res = min(res,cnt);

};// ii
    if (res <INF)
        cout <<res<<endl;
    else cout <<"NOT POSSIBLE"<<endl;
};



void input(){
    cin >>T;
    for(int i = 1; i<=T;i++){
        cin >>N>>L;
        string str;
        Inp0.clear();
        Out0.clear();
        for(int j = 1; j<=N; j++){
            cin >>str;
            Inp0.push_back(str);
        }
        for(int j = 1; j<=N; j++){
            cin >>str;
            Out0.push_back(str);
        };
        cout<<"Case #"<<i<<": ";
        solveIt(N,L);
    }
};

int main()
{
    input();
    return 0;
}
