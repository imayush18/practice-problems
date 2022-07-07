// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool helper(vector<bool> &vis, vector<bool> &dfsvis, vector<int> adj[], int i){
        
        vis[i]=true;
        dfsvis[i]=true;
        
        for(auto nei: adj[i]){
            
            if(!vis[nei]){
                bool temp=helper(vis, dfsvis, adj, nei);
                if(temp)
                    return true;
            }
            else if(dfsvis[nei])
                return true;
            
        }
        
        dfsvis[i]=false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, false);
        vector<bool> dfsvis(V, false);
    
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(helper(vis, dfsvis, adj, i))
                    return true;
            }
        }
        return false;

    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends