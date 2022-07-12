// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	
	void dfs(int node, vector<int> adj[], stack<int> &s, vector<bool> &vis){
	    
	    vis[node]=true;
	    
	    for(auto x: adj[node]){
	        if(!vis[x]){
	            dfs(x, adj, s, vis);   
	        }
	    }
	    
	    s.push(node);
	}
	
	void dfs1(int node, vector<int> adj[], stack<int> &s, vector<bool> &vis){
	    
	    vis[node]=true;
	    
	    for(auto x: adj[node]){
	        if(!vis[x]){
	            dfs(x, adj, s, vis);   
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, s, vis);
            }
        }
        
        //transpose
        vector<int> revadj[V];
        for(int i=0; i<V; i++){
            for(auto x: adj[i]){
                revadj[x].push_back(i);
            }
        }
        
        for(int i=0; i<V; i++){
            vis[i]=false;
        }
        
        int ans=0;
        while(!s.empty()){
            int top=s.top();
            s.pop();
            
            if(!vis[top]){
                dfs1(top, revadj, s, vis);
                ans++;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends