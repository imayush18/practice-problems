// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n, INT_MAX);
	    dist[0]=0; // treating 0 as the source
	    
	    int x=edges.size();
	    
	    for(int i=0; i<n-1; i++){
	        for(auto j: edges){
	            int prev=dist[j[1]];
	            if(dist[j[0]]==INT_MAX)
	                continue;
	            int cur=dist[j[0]] + j[2];
	            
	            if(cur<prev){
	                dist[j[1]]=cur;
	            }
	        }
	    }
	    
	    for(int i=0; i<x; i++){
	        int prev=dist[edges[i][1]];
	            int cur=dist[edges[i][0]] + edges[i][2];
	            
	            if(cur<prev){
	                return 1;
	            }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends