#include <iostream>
using namespace std;

//int matrx[1100][1100];
int n;
struct node{
    int v;
    node* next;
};

node* arr[1100];
int count1[1100];
int minNum[1100];
int edge[1100];

int wo[2];

void doing(int w, int* vt) {
    int a = -( count1[w] - minNum[w]);
    
    if (a<vt[0]) {
        vt[1] = vt[0];
        wo[1] = wo[0];
        
        
        vt[0] = a;
        wo[0] = w;
        return;
    } else
        if(a<vt[1]) {
            vt[1] = a;
            wo[1] = w;
            return;
        }
}

void calculate(int v, int parent) {
    node* temp = arr[v];
    count1[v] = 1;
    int c = 0;
    
    int vt[2];
    vt[0]=vt[1]= 10000;
    int wen;
    
    //cout<<"processing:"<<v<<endl;
    while(temp != NULL) {
        if (temp->v != parent) {
            calculate(temp->v, v);
            count1[v] += count1[temp->v];
            c++;
            wen= temp->v;
            doing(temp->v, vt);
        }
        temp = temp->next;
    }

    if (c==0) {
        minNum[v] = 0;
    } else
        if(c==1) {
            minNum[v] = count1[wen];
        } else {
            minNum[v] =  count1[v] -1 + vt[0] + vt[1];
        }
    

    
}

int pick(int root) {
    calculate(root, -1);
    return minNum[root];
}

void process() {

    int i,j,k;
    node* temp;
    
    cin>>n;
    for(i=1;i<=n;i++)
        arr[i] = NULL;
    for(i=1;i<=n;i++)
        edge[i] = 0;
    //cout<<"0"<<endl;
    for(i=0;i<n-1;i++) {
        cin>>j>>k;
        //cout<<j<<' '<<k<<endl;
        
        
        temp = new node();
        temp->v = k;
        temp->next = arr[j];
        arr[j] = temp;
        
        temp = new node();
        temp->v = j;
        temp->next = arr[k];
        arr[k] = temp;
        
        
        
    }
    
    int ret = 10000;

    for(i=1;i<=n;i++) {
        j = pick(i);
        //cout<<"picking "<<i<<" getting "<<j<<endl;
        if (j< ret) {
            ret = j;
        }
    }
    cout<<ret;
    
    for(i=1;i<=n;i++)
        while(arr[i] != NULL) {
            temp = arr[i];
            arr[i] = arr[i]->next;
            delete temp;
        }
}

int main() {
    int t,i;
    cin>>t;
    for(i=0;i<t;i++) {
        cout<<"Case #" <<(i+1)<<": ";
        process();
        cout<<endl;
    }
    return 0;
}
