#include <cstdio>
#include <vector>
using std::vector;

#define CHILD_N 2

struct Tree{
    int size;
    Tree *child[CHILD_N];
    Tree(){
        size = 0;
        for(int i = 0;i < CHILD_N;++i){
            child[i] = NULL;
        }
    };
    ~Tree(){
        for(int i = 0;i < CHILD_N;++i){
            if(child[i] != NULL){
                delete child[i];
            }
        }
    }
    void insert(const char *buffer){
        ++size;
        if(*buffer == 0){
            return;
        }
        int c = *buffer - '0';
        if(child[c] == NULL){
            child[c] = new Tree;
        }
        child[c]->insert(buffer + 1);
    }
    int match(const Tree& rhs, int L, vector<bool>& flip, int flips){
        if(!match(rhs, flip, 0)){
            return -1;
        }
        if(flip.size() == L){
            return flips;
        }
        int min = -1;
        int result;
        for(int i = 0;i < 2;++i){
            flip.push_back(i != 0);
            result = match(rhs, L, flip, flips + i);
            flip.pop_back();
            if(result != -1){
                if(min == -1 || result < min){
                    min = result;
                }
            }
        }
        return min;
    }
    bool match(const Tree& rhs, const vector<bool>& flip, int depth){
        if(depth >= flip.size()){
            return true;
        }
        bool f = flip[depth];
        if(child_size(0) != rhs.child_size(f ? 1 : 0) || child_size(1) != rhs.child_size(f ? 0 : 1)){
            return false;
        }
        return (child[0] == NULL || child[0]->match(*(rhs.child[f ? 1 : 0]), flip, depth + 1)) &&
               (child[1] == NULL || child[1]->match(*(rhs.child[f ? 0 : 1]), flip, depth + 1));
    }
    int child_size(int n) const{
        if(child[n ? 1 : 0] == NULL){
            return 0;
        }
        return child[n ? 1 : 0]->size;
    }
};


int main(){
    int T;
    scanf("%d", &T);
    char buffer[1024];
    for(int t = 1;t <= T;++t){
        int N, L;
        Tree outlets, devices;
        scanf("%d%d", &N, &L);
        for(int i = 0;i < N;++i){
            scanf("%s", buffer);
            outlets.insert(buffer);
        }
        for(int i = 0;i < N;++i){
            scanf("%s", buffer);
            devices.insert(buffer);
        }
        vector<bool> tmp;
        int result = outlets.match(devices, L, tmp, 0);
        if(result == -1){
            printf("Case #%d: NOT POSSIBLE\n", t);
        }else{
            printf("Case #%d: %d\n", t, result);
        }
    }
}
