#include <iostream>
#include <Vector>
#include <queue>

using namespace std;

struct State
{
    vector<string> cur;
    int switchesFlipped;
};

//actually its a bfs
int bruteforce( queue<State> q, vector<string> final, int L, vector<State> visited )
{
    while( !q.empty() )
    {
        State state = q.front();
        q.pop();
        
        
        bool isVisited = false, tempVisited;
        
        for( int i = 0; i < visited.size(); i ++ )
        {
            tempVisited = true;
            for( int j = 0; j < final.size(); j ++ )
                if( visited[i].cur[j] != state.cur[j] )
                    tempVisited = false;
            
            if( tempVisited )
                isVisited = true;
        }
        if( !isVisited){
        
            visited.push_back(state);
           /*
            for( int i = 0; i < final.size(); i ++ )
                cout << state.cur[i] << " ";
            cout << endl;
            */
    bool done = true, tempDone;
    int max = 0, newMax;
    
    for( int i = 0; i < final.size(); i ++ )
    {
        tempDone = false;
        
        for( int j = 0; j < final.size(); j ++ )
            if( state.cur[i] == final[j] )
                tempDone = true;
        
        if( tempDone == false )
            done = false;
    }
    if( done )
        return state.switchesFlipped;
    
    for( int i = 0; i < L; i ++ )
    {
        State s = state;
        s.switchesFlipped = state.switchesFlipped+1;
        
        //int bit = 1 << i;
        for( int j = 0; j < final.size(); j ++ )
        {
            if( s.cur[j][i] == '0' )
                s.cur[j][i] = '1';
            else if( s.cur[j][i] == '1' )
                s.cur[j][i] = '0';
        }
        q.push( s );
    }
        }
    }
    
    return -1;
}

int main()
{
    int cases, N, L;
    string temp;
    
    cin >> cases;
    
    for( int c = 0; c < cases; c ++ )
    {
        cin >> N >> L;
        
        vector<string> initial;
        vector<string> final;
        
        for( int i = 0; i < N; i ++ )
        {
            cin >> temp;
            initial.push_back( temp );
        }
        
        for( int i = 0; i < N; i ++ )
        {
            cin >> temp;
            final.push_back( temp );
        }
        
        State state;
        state.switchesFlipped = 0;
        state.cur = initial;
        
        vector<State> visited;
        queue<State> q;
        
        q.push( state );
        
        int solution = bruteforce( q, final, L, visited );
        
        if( solution != -1 )
            cout << "Case #" << c+1 << ": " << solution << endl;
        else
            cout << "Case #" << c+1 << ": NOT POSSIBLE" << endl;

    }
 
  return 0;
}
