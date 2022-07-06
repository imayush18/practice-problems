// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  
    void helper(int node, vector<int> adj[], vector<int> &ans, vector<bool> &vis){
        
        if(vis[node])
            return;
            
        vis[node]=true;
        ans.push_back(node);
        
        for(auto x: adj[node])
            helper(x, adj, ans, vis);
    }
  
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        // vector<int> ans;
        
        // int vis[V];
        // for(int i=0; i<V; i++){
        //     vis[i]=0;
        // }
        // vis[0]=1;
        // stack<int> s;
        // s.push(0);
        
        // while(!s.empty()){
        //     int node=s.top();
        //     s.pop();
        //     ans.push_back(node);
            
        //     for(int it=adj[node].size()-1; it>=0; it--){
        //         if(vis[it]==0)
        //             s.push(it);
        //         vis[it]=1;
        //     }
        // }
        // return ans;
        
        vector<int> ans;
        vector<bool> vis(V, false);
        
        helper(0, adj, ans, vis);
        
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends