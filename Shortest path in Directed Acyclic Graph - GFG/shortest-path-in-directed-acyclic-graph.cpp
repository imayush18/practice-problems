//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void dfs(unordered_map<int, list<pair<int, int>>> adj, vector<bool> &vis, int i, vector<int> &topo){
        
        vis[i]=true;
        for(auto x: adj[i]){
            if(!vis[x.first]){
                dfs(adj, vis, x.first, topo);
            }
        }
        
        topo.push_back(i);
        
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        unordered_map<int, list<pair<int, int>>> adj;
        for(auto i: edges){
            adj[i[0]].push_back({i[1], i[2]});
        }
        
        vector<bool> vis(N, false);
        vector<int> topo;
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(adj, vis, i, topo);
            }
        }
        
        reverse(topo.begin(), topo.end());
        // for(auto i: topo){
        //     cout << i << "  ";
        // }
        
        vector<int> dist(N, INT_MAX);
        dist[0]=0;
        
        for(int i=0; i<N; i++){
            
            if(dist[i]!=INT_MAX){
                for(auto x: adj[i]){
                    if(dist[x.first] > x.second+dist[i]){
                        dist[x.first] = x.second+dist[i];
                    }
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends