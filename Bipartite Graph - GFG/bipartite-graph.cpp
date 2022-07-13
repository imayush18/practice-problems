// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool dfs(vector<int>graph[], vector<int> &res, int i){
        
        // queue<int> q;
        // q.push(i);
        // res[i]=0;
        
        // while(!q.empty()){
        //     int cur=q.front();
        //     q.pop();

            for(auto x: graph[i]){
                if(res[x]==-1){
                    // q.push(x);
                    res[x]=1-res[i];
                    if(!dfs(graph, res, x))
                        return false;
                }
                else{
                    if(res[x]==res[i])
                        return false;;
                }
            }
        // }
        return true;
    }

	bool isBipartite(int n, vector<int>graph[]){
	   // int n=graph.size();
        vector<int> res(n, -1);
        
        for(int i=0; i<n; i++){
            if(res[i]==-1){
                res[i]=0;
                if(!dfs(graph, res, i))
                    return false;
            }
        }

        return  true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends