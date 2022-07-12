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
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row=image.size();
        int col=image[0].size();
        vector<vector<bool>> vis(row, vector<bool> (col, false));
        
        int prev=image[sr][sc];
        helper(image, sr, sc, color, row, col, vis, prev);
        
        return image;
    }
};