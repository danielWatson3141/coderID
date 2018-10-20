#include <iostream> 
#include <fstream> 
#include <algorithm>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>(0)?(a):(-a))

using namespace std;

int count(int **tree, int start, int N){
    //counts total children +self
    int n = 0; //neighbours
    for(int i = 0; i < N; i++){
        if(tree[start][i] == 1) n++;
    }
    //cout << "COUNT " << start << " " << n << endl;
    if(n == 0) return 1;
    int j = 0, ret = 1;
    int *nb = new int[n];
    for(int i = 0; i < N; i++){
        if(tree[start][i] == 1){
            nb[j] = i;
            j++;
        }
    }
    for(int i = 0; i < j; i++){
        tree[start][nb[i]] = 0;
        tree[nb[i]][start] = 0;
        ret += count(tree, nb[i], N);
        tree[start][nb[i]] = 1;
        tree[nb[i]][start] = 1;     
    }
    return ret;
}
    
int deletions(int **tree, int start, int N){
    int n = 0; //neighbours
    for(int i = 0; i < N; i++){
        if(tree[start][i] == 1 || tree[i][start] == 1) n++;
    }
    //cout << start  << " " << n << " **" << endl;
    if(n == 0){
        return 0;
    }
    int ret = 0, j = 0;
    int *nb = new int[n];
    for(int i = 0; i < N; i++){
        if(tree[start][i] == 1){
            nb[j] = i;
            j++;
            //cout << start << " " << i << " *" << endl;
        }
    }
    if(n == 2){
        tree[start][nb[0]] = 0;
        tree[nb[0]][start] = 0;
        ret += deletions(tree, nb[0], N);
        tree[start][nb[0]] = 1;
        tree[nb[0]][start] = 1;
        tree[start][nb[1]] = 0;
        tree[nb[1]][start] = 0;
        ret += deletions(tree, nb[1], N);
        tree[start][nb[1]] = 1;
        tree[nb[1]][start] = 1;
    }
    else if(n == 1){
        tree[start][nb[0]] = 0;
        tree[nb[0]][start] = 0;
        ret += count(tree, nb[0], N);
        //cout << ret << endl;
        tree[start][nb[0]] = 1;
        tree[nb[0]][start] = 1;
    }
    else{
        for(int i = 0; i < n; i++){
            tree[start][nb[i]] = 0;
            tree[nb[i]][start] = 0;
            return deletions(tree,start,N) + count(tree,nb[i], N);
            tree[start][nb[i]] = 1;
            tree[nb[i]][start] = 1;
        }
    }
    return ret;
}

int main(void){
    ifstream fin("B.in");
    ofstream fout("B.out");
    fout << fixed;
    fout.precision(2); //prints doubles as 3.14
    
    int T;
    fin >> T;
    for(int c = 0; c < T; c++){
        int N;
        fin >> N;
        int **tree = new int*[N];
        for(int i = 0; i < N; i++){
            tree[i] = new int[N];
            for(int j = 0; j < N; j++){
                tree[i][j] = 0;
            }
        }
        
        for(int i = 0; i < N-1; i++){
            int x, y;
            fin >> x >> y;
            x--; y--;
            tree[x][y] = 1;
            tree[y][x] = 1;
        }
        
        int ret = N;
        //try each node as the root
        for(int i = 0; i < N; i++){
            int newret = deletions(tree, i, N);
            //cout << "Newret " << i << " " << newret << endl;
            if(newret < ret) ret = newret;
        }
        fout << "Case #" << c+1 << ": " << ret << endl;
        //cout << "*****" << endl;
    }
    cin >> T;
    return 0;
}

