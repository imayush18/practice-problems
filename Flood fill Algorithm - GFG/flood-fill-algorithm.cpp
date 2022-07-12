// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    void helper(vector<vector<int>>& image, int i, int j, int newColor, int row, int col, vector<vector<bool>> &vis, int prev){
        if(i<0 or j<0 or i>=row or j>=col){
            return;
        }
        
        if(vis[i][j]){
            return;
        }
        
        if(image[i][j]!=prev){
            return;
        }
        
        vis[i][j]=1;
        image[i][j]=newColor;
        
        helper(image, i+1, j, newColor, row, col, vis, prev);
        helper(image, i-1, j, newColor, row, col, vis, prev);
        helper(image, i, j+1, newColor, row, col, vis, prev);
        helper(image, i, j-1, newColor, row, col, vis, prev);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
        int row=image.size();
        int col=image[0].size();
        vector<vector<bool>> vis(row, vector<bool> (col, false));
        
        int prev=image[sr][sc];
        helper(image, sr, sc, newColor, row, col, vis, prev);
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends