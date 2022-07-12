// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dist(n, 100000);
	    dist[0]=0; // treating 0 as the source
	    
	    
	    for(int i=0; i<n; i++){
	        for(auto j: edges){
	            int prev=dist[j[1]];
	            int cur=dist[j[0]] + j[2];
	            
	            if(cur<prev){
	                dist[j[1]]=cur;
	            }
	        }
	    }
	    
	    for(auto j: edges){
	        int prev=dist[j[1]];
	        int cur=dist[j[0]] + j[2];
	            
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