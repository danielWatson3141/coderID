#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fin("fullbinsmall.in");
ofstream fout("fullbinsmall.out");

int N, X, Y;
vector<int> edg[1005];

int size(int root, int par){
    int ans = 1;
    for(int i = 0; i<edg[root].size(); i++){
        if(edg[root][i] == par) continue;
        ans += size(edg[root][i], root);
    }
    return ans;

}

int min_cost(int root, int par){
    int del = size(root, par) - 1;
    
    vector<int> chil;
    for(int i = 0; i<edg[root].size(); i++){
        if(edg[root][i] == par) continue;
        
        int keep = size(edg[root][i], root) - min_cost(edg[root][i], root);
        
        chil.push_back(keep);
    }
    sort(chil.begin(), chil.end());
    
    if(chil.size() >= 2){
        del -= chil[chil.size()-1];
        del -= chil[chil.size()-2];
    }
    return del;
}

int main(){
    int T;
    fin >> T;
    for(int t=0; t<T; t++){
        fin >> N;
        for(int i=0; i<N; i++)
            edg[i].clear();
            
        for(int i=0; i<N-1; i++){
            fin >> X >> Y;
            X--;
            Y--;
            edg[X].push_back(Y);
            edg[Y].push_back(X);
        }
        
        int ans = 1 << 30;
        for(int i=0; i<N; i++)
            ans = min(ans, min_cost(i, -1));
        
        fout << "Case #" << t+1 << ": ";
        fout << ans;
        fout << endl;
    }
}
