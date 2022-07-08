// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>> vis(N, vector<int> (N, 0));
	    
	    queue<pair<int, int>> q;
	    q.push({KnightPos[0]-1, KnightPos[1]-1});
	    
	    
	    while(!q.empty()){
	        auto pos=q.front();
	        q.pop();
	        int f=pos.first;
	        int s=pos.second;
	        
	        if(f+1>=0 and f+1<N and s+2>=0 and s+2<N and vis[f+1][s+2]==0){
	            vis[f+1][s+2]=1+vis[f][s];
	            q.push({f+1, s+2});
	        }
	        
	        if(f+2>=0 and f+2<N and s+1>=0 and s+1<N and vis[f+2][s+1]==0){
	            vis[f+2][s+1]=1+vis[f][s];
	            q.push({f+2, s+1});
	        }
	        
	        if(f+2>=0 and f+2<N and s-1>=0 and s-1<N and vis[f+2][s-1]==0){
	            vis[f+2][s-1]=1+vis[f][s];
	            q.push({f+2, s-1});
	        }
	        
	        if(f+1>=0 and f+1<N and s-2>=0 and s-2<N and vis[f+1][s-2]==0){
	            vis[f+1][s-2]=1+vis[f][s];
	            q.push({f+1, s-2});
	        }
	        
	        if(f-1>=0 and f-1<N and s-2>=0 and s-2<N and vis[f-1][s-2]==0){
	            vis[f-1][s-2]=1+vis[f][s];
	            q.push({f-1, s-2});
	        }
	        
	        if(f-2>=0 and f-2<N and s-1>=0 and s-1<N and vis[f-2][s-1]==0){
	            vis[f-2][s-1]=1+vis[f][s];
	            q.push({f-2, s-1});
	        }
	        
	        if(f-2>=0 and f-2<N and s+1>=0 and s+1<N and vis[f-2][s+1]==0){
	            vis[f-2][s+1]=1+vis[f][s];
	            q.push({f-2, s+1});
	        }
	        
	        if(f-1>=0 and f-1<N and s+2>=0 and s+2<N and vis[f-1][s+2]==0){
	            vis[f-1][s+2]=1+vis[f][s];
	            q.push({f-1, s+2});
	        }
	    }
	    
	    int val=vis[TargetPos[0]-1][TargetPos[1]-1];
	    return val;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends