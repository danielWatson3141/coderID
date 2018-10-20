#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int process(int N, vector<int>* connects, int on, int from, bool shouldDel);
int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    
    int K;
    in>>K;
    for(int k=0;k<K;k++) {
        int N;
        in>>N;
        vector<int>* connects = new vector<int>[N];
        for(int i=0;i<N - 1;i++) {
            int X,Y;
            in>>X>>Y;
            connects[X-1].push_back(Y-1);
            connects[Y-1].push_back(X-1);
        }
        int min = 1000000;
        for(int i=0;i<N;i++) {
            int necessary = process(N, connects, i, -1, false);
            if(necessary < min)
                min = necessary;
            //cout<<"Root "<<(i+1)<<": "<<necessary<<"\n";
        }
        out<< "Case #"<<(k+1)<<": "<<min<<"\n";
    }
}
int find(vector<int> in, int val) {
    for(int i=0;i<in.size();i++)
        if(in[i] == val)
            return i;
    return -1;
}
int process(int N, vector<int>* connects, int on, int from, bool shouldDel) {
    //cout<<on<<" "<<from<<"\n";
    if(from == -1) { // Root node!
        if(connects[on].size() == 0)
            return 0;
        if(connects[on].size() == 1) {
            return process(N, connects, connects[on][0], on, true);
        }
        if(connects[on].size() == 2) {
            return process(N, connects, connects[on][0], on, false) + process(N, connects, connects[on][1], on, false);
        }
        else {
            int min = 1000000000;
            for(int excludeB = 0; excludeB < connects[on].size();excludeB++) {
                for(int excludeC = 0; excludeC < connects[on].size();excludeC++) {
                    if(excludeB == excludeC)
                        continue;
                    //Process
                    int remove = 0;
                    for(vector<int>::iterator iter = connects[on].begin();iter != connects[on].end();iter++) {
                        int val = *iter;
                        if(val != connects[on][excludeB] && val != connects[on][excludeC]) {
                            remove += process(N, connects, val, on, true);
                        }
                        else
                            remove += process(N, connects, val, on, false);
                    }
                    //cout<<" "<<excludeB<<" "<<excludeC<<" "<<remove<<"\n";
                    if(remove < min)
                        min= remove;
                }
            }
            int remove = 0;
            for(vector<int>::iterator iter = connects[on].begin();iter != connects[on].end();iter++) {
                int val = *iter;
                remove += process(N, connects, val, on, true);
            }
            if(remove < min)
                min= remove;
            //cout<<" "<<remove<<"\n";
            return min;
        }
    }
    else if(!shouldDel) { // Non-root node
        if(connects[on].size() == 1)
            return 0;
        else {
            int min = 1000000000;
            int fromi = find(connects[on], from);
            for(int excludeB = 0; excludeB < connects[on].size();excludeB++) {
                if(excludeB == fromi)
                    continue;
                for(int excludeC = 0; excludeC < connects[on].size();excludeC++) {
                    if(excludeC == fromi || excludeB == excludeC)
                        continue;
                    //Process
                    int remove = 0;
                    for(vector<int>::iterator iter = connects[on].begin();iter != connects[on].end();iter++) {
                        int val = *iter;
                        if(val != from && val != connects[on][excludeB] && val != connects[on][excludeC]) {
                            remove += process(N, connects, val, on, true);
                        }
                        else if(val != from)
                            remove += process(N, connects, val, on, false);
                    }
                    if(remove < min)
                        min= remove;
                }
            }
            int remove = 0;
            for(vector<int>::iterator iter = connects[on].begin();iter != connects[on].end();iter++) {
                int val = *iter;
                if(val != from)
                    remove += process(N, connects, val, on, true);
            }
            if(remove < min)
                min= remove;
            return min;
        }
    }
    else { //Non-root node delete
        if(connects[on].size() == 1)
            return 1;
        else {
            int needed = 1;
            for(vector<int>::iterator iter = connects[on].begin();iter != connects[on].end();iter++) {
                if(*iter != from)
                    needed += process(N,connects, *iter, on, true);
            }
            return needed;
        }
    }
}