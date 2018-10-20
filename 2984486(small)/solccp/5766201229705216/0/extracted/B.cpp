#include <iostream>
#include <vector>
#include <fstream>
#include <stack>

using namespace std;

struct Node
{
    int N;
    vector<const Node*> child;
};

int countUnBinary(int N, const Node* root)
{
    vector<bool> visited(N, false);
    stack<const Node*> mystack;
    vector<int> parent(N, 0);

    int nbin = 0;
    mystack.push(root);
    while(!mystack.empty())
    {
        const Node* cur = mystack.top();
        mystack.pop();
        if (!visited[cur->N])
        {
            visited[cur->N] = true;
            int unvisit = 0;
            for(int i=0; i<cur->child.size();++i)
            {
                if (parent[cur->N] != cur->child[i]->N)
                {
                    unvisit++;
                }
            }
            if (unvisit != 2 && unvisit != 0)
            {
                nbin++;
            }
            for(int i=0; i<cur->child.size();++i)
            {
                parent[cur->child[i]->N] = cur->N;
                mystack.push(cur->child[i]);
            }
        }
    }
    return nbin;
}

int main()
{

    int ncase;
	cin >> ncase;
    for(int icase = 0; icase < ncase; ++icase)
    {
        int num ;
        cin >> num;
        vector<Node*> nodes(num);
        for(int i=0; i<num; ++i)
        {
            Node* node = new Node;
            node->N = i;
            nodes[i] = node;
        }
        for(int i=0; i<num-1; ++i)
        {
            int s , e;
            cin >> s >> e;
            s--;
            e--;
            nodes[s]->child.push_back(nodes[e]);
            nodes[e]->child.push_back(nodes[s]);
        }
        
    
        int ncut = 100000000;
        for(int i=0; i<num;++i)
        {
            int mycut = countUnBinary(num, nodes[i]);
            if (mycut < ncut)
            {
                ncut = mycut;
            }
        }


        cout << "Case #" << icase+1 << ": " << ncut << endl;
    }
}

