//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void dfs(vector<vector<int>> &island, int n, int m, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || island[i][j]!=1)
            return;
        
        island[i][j]=0;
        dfs(island, n, m, i+1, j);
        dfs(island, n, m, i-1, j);
        dfs(island, n, m, i, j+1);
        dfs(island, n, m, i, j-1);
    }
  
    int count(vector<vector<int>> island, int n, int m){
        
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(island[i][j]==1){
                    cnt++;
                    dfs(island, n, m, i, j);
                }
            }
        }
        return cnt;
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        vector<vector<int>> island(n, vector<int> (m, 0));
        vector<int> ans;
        
        for(int i=0; i<operators.size(); i++){
            int a=operators[i][0];
            int b=operators[i][1];
            
            island[a][b]=1;
            ans.push_back(count(island, n, m));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends