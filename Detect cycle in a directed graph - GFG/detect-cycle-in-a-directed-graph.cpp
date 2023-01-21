//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    
    bool helper(vector<bool> &vis, vector<bool> &dfsvis, int node, vector<int> adj[]){
        
        vis[node]=dfsvis[node]=true;
        
        for(auto x: adj[node]){
            if(!vis[x]){
                if(helper(vis, dfsvis, x, adj))
                    return true;
            }
            else{
                if(dfsvis[x])
                    return true;
            }
        }
        dfsvis[node]=false;
        return false;
        
    }
    
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
       
        vector<bool> vis(V, false);
        vector<bool> dfsvis(V, false);
       
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(helper(vis, dfsvis, i, adj)){
                    return true;
                }
            }
        }
        
        return false;
       
    }
};

//{ Driver Code Starts.

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