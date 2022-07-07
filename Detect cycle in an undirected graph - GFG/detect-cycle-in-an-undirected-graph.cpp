// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool helper(vector<bool> &vis, vector<int> adj[], int i){
        
        unordered_map<int, int> parent;
        stack<int> s;
        s.push(i);
        
        parent[i]=-1;
        vis[i]=true;
        
        while(!s.empty()){
            int node=s.top();
            s.pop();
            
            for(auto x: adj[node]){
                if(vis[x]){
                    if(x!=parent[node])
                        return true;
                }
                else{
                    vis[x]=true;
                    parent[x]=node;
                    s.push(x);
                }
            }
        }
        return  false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i])
                if(helper(vis, adj, i))
                    return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends