#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

//trocar para 0 para desabilitar output
#if 1
#define DEBUG(x) cout << x << endl
#define PAUSE() cin.get(); cin.get()
#else
#define DEBUG(x)
#define PAUSE()
#endif

#define TRACE(x) DEBUG(#x << " = " << x)
#define DEBUGS() DEBUG("***************************")
#define MAX 1

int main(){
    int t, cases = 0;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int medidor = 0;
        for (int i = 0; i < n; i++){
            int aux;
            cin >> aux;
            if (aux <= n/2 && i >= n/2) medidor++;
            else if (aux >= n/2 && i <= n/2) medidor++;
        }
        cout << "Case #" << ++cases << ": ";
        if (medidor >= n/2-2) cout << "GOOD" << endl;
        else cout << "BAD" << endl;
    }
    return 0;
}
