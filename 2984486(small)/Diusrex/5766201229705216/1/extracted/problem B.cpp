#include <iostream>
#include <vector>

using namespace std;

int CalculateDeleteFromParent(int currentNode, int parent, const vector<vector<bool> > &connected, vector<vector<int> >& deleteCost, int size)
{
    // Must delete this guy
    int sum = 1;
    
    for (int i = 0; i < size; ++i)
    {
        if (connected[currentNode][i] && i != parent)
        {
            sum += CalculateDeleteFromParent(i, currentNode, connected, deleteCost, size);
        }
    }
    
    deleteCost[currentNode][parent] = sum;
    
    return sum;
}



void CalculateDeleteNonParent(int currentNode, int parent, int aboveCost, const vector<vector<bool> > &connected, vector<vector<int> >& deleteCost, int size)
{
    // [currentNode][parent] included current
    
    if (parent != -1)
    {
        deleteCost[parent][currentNode] = aboveCost + 1;
    }
    int totalCost(0);
    
    for (int i = 0; i < size; ++i)
    {
        if (connected[currentNode][i])
            totalCost += deleteCost[i][currentNode];
    }
    
    for (int i = 0; i < size; ++i)
    {
        if (connected[currentNode][i] && parent != i)
            CalculateDeleteNonParent(i, currentNode, totalCost - deleteCost[i][currentNode], connected, deleteCost, size);
    }
    

}


// Will return the cost
int EnsureProper(int currentNode, const int& descendedFrom, const vector<vector<bool> >& connected, vector<vector<int> >& deleteCost, int size)
{
    if (descendedFrom != -1 && !connected[currentNode][descendedFrom])
        cout << "WELL FUCK\n\n";
        
    vector<int> descendents;
    
    for (int i = 0; i < size; ++i)
    {
        if (connected[currentNode][i] && i != descendedFrom)
            descendents.push_back(i);
    }
    
    if (descendents.size() == 0)
        return 0;
    
    else if (descendents.size() == 1)
        return deleteCost[descendents[0]][currentNode];
    
    else if (descendents.size() == 2)
        return EnsureProper(descendents[0], currentNode, connected, deleteCost, size) + EnsureProper(descendents[1], currentNode, connected, deleteCost, size);
        
    int best = size;
    
    for (int first = 0; first < descendents.size(); ++first)
    {
        for (int second = first + 1; second < descendents.size(); ++second)
        {
            int current = 0;
            
            for (int toDelete = 0; toDelete < descendents.size(); ++toDelete)
            {
                if (toDelete == first || toDelete == second)
                    continue;
                
                current += deleteCost[descendents[toDelete]][currentNode];
            }
            
            if (current >= best)
                continue;
            
            current += EnsureProper(descendents[first], currentNode, connected, deleteCost, size);
            if (current >= best)
                continue;
                
            current += EnsureProper(descendents[second], currentNode, connected, deleteCost, size);
            if (current < best)
                best = current;
        }
    }
    
    return best;
}


int main()
{
    int T, numNodes;
    
    cin >> T;
    
    for (int t = 1; t <= T; ++t)
    {
        cin >> numNodes;
        
        vector<vector<bool> > connected(numNodes, vector<bool>(numNodes, false));
        
        for (int i = 1; i < numNodes; ++i)
        {
            int first, second;
            cin >> first >> second;
            
            connected[first - 1][second - 1] = true;
            connected[second - 1][first - 1] = true;
        }
        
        
        // Is [current][parent]
        vector<vector<int> > deleteCost(numNodes, vector<int>(numNodes, -1));
        
        CalculateDeleteFromParent(0, -1, connected, deleteCost, numNodes);
        CalculateDeleteNonParent(0, -1, 0, connected, deleteCost, numNodes);
        
           
        int best = numNodes;
        
        for (int base = 0; base < numNodes; ++base)
        {
            int current = EnsureProper(base, -1, connected, deleteCost, numNodes);
            
            if (current < best)
                best = current;
        }
        
        cout << "Case #" << t << ": " << best << '\n';
    }
}