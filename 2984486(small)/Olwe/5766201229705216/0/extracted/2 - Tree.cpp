/* This program should be run with its input piped from the input file and its output piped to the output file. */

#include <iostream>
#include <set>
#include <cmath>

using namespace std;

struct Node {
    set<int> connections;
};

void traverseTree(int iNumNodes, Node* pNodes, int iRoot, bool* pbNodesVisited) {
    pbNodesVisited[iRoot] = true;
    
    for (set<int>::iterator it = pNodes[iRoot].connections.begin(); it != pNodes[iRoot].connections.end(); ++it) {
        if (!pbNodesVisited[*it]) {
            traverseTree(iNumNodes, pNodes, *it, pbNodesVisited);
        }
    }
}

int getMinimumDeletedNodes(int iNumNodes, Node* pNodes, bool* pbNodesDeleted, int iDepth = 0, int iStartNode = 0) {
    int i;
    int iRoot = -1;
    
    if (iNumNodes - iDepth == 1) {
        return iDepth;
    }
    
    for (i = 0; i < iNumNodes; ++i) {
        if (!pbNodesDeleted[i] && pNodes[i].connections.size() != 1 && pNodes[i].connections.size() != 3) {
            if (iRoot != -1) {
                break;
            }
            
            if (pNodes[i].connections.size() == 2) {
                iRoot = i;
            }
        }
    }
    
    if (iRoot != -1 && i == iNumNodes) {
        bool* pbNodesVisited = new bool[iNumNodes];
        for (i = 0; i < iNumNodes; ++i) {
            pbNodesVisited[i] = false;
        }
        
        traverseTree(iNumNodes, pNodes, iRoot, pbNodesVisited);
        
        for (i = 0; i < iNumNodes; ++i) {
            if (!(pbNodesVisited[i] || pbNodesDeleted[i])) {
                break;
            }
        }
        
        delete[] pbNodesVisited;
        
        if (i == iNumNodes) {
            return iDepth;
        }
    }
    
    int iBest = 1000000;
    int iResult;
    
    for (i = iStartNode; i < iNumNodes; ++i) {
        if (!pbNodesDeleted[i]) {
            pbNodesDeleted[i] = true;
            for (set<int>::iterator it = pNodes[i].connections.begin(); it != pNodes[i].connections.end(); ++it) {
                pNodes[*it].connections.erase(i);
            }
            
            iResult = getMinimumDeletedNodes(iNumNodes, pNodes, pbNodesDeleted, iDepth + 1, i + 1);
            
            pbNodesDeleted[i] = false;
            for (set<int>::iterator it = pNodes[i].connections.begin(); it != pNodes[i].connections.end(); ++it) {
                pNodes[*it].connections.insert(i);
            }
            
            if (iResult < iBest) {
                iBest = iResult;
            }
        }
    }
    
    return iBest;
}

int main() {
    int iNumTests;
    int iNumNodes;
    Node* pNodes;
    
    cin >> iNumTests;
    
    for (int test = 1; test <= iNumTests; ++test) {
        cin >> iNumNodes;
        
        pNodes = new Node[iNumNodes];
        
        int X, Y;
        
        for (int i = 0; i < iNumNodes - 1; ++i) {
            cin >> X >> Y;
            pNodes[X - 1].connections.insert(Y - 1);
            pNodes[Y - 1].connections.insert(X - 1);
        }
        
        bool* pbNodesDeleted = new bool[iNumNodes];
        for (int i = 0; i < iNumNodes; ++i) {
            pbNodesDeleted[i] = false;
        }
        
        int minimum = getMinimumDeletedNodes(iNumNodes, pNodes, pbNodesDeleted);
        
        cout << "Case #" << test << ": " << minimum << endl;
        
        delete[] pNodes;
        delete[] pbNodesDeleted;
    }
    
    return 0;
}
