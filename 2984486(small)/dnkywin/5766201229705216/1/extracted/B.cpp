#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
int dp[1000];
void root_search(int i){
    visited[i] = true;
    int children = 0;
    int max1 = 0;
    int max2 = 0;
    for (vector<int>::iterator it = adj[i].begin(); it<adj[i].end(); it++){
        if (!visited[*it]){
            root_search(*it);
            children++;
            if (dp[*it]>max1){
                max2 = max1;
                max1 = dp[*it];
            }
            else if (dp[*it]>max2){
                max2 = dp[*it];
            }
        }
    }
    if (children<2) dp[i] = 1;
    else dp[i] = 1 + max1 + max2;
}

int main(){
    ifstream in("B.in"); ofstream out("B.out");
    int T;
    in>>T;

    int N;
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";

        for (int i=0;i<1000;i++) adj[i].clear();

        in>>N;
        for (int i=0;i<N-1;i++){
            int a,b;
            in>>a>>b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }

        int ans = 0;
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++) {visited[j]=false; dp[j] = -1;}
            root_search(i);
            if (dp[i]>ans) ans = dp[i];
        }

        out<<N-ans;


        out<<"\n";
    }
}
