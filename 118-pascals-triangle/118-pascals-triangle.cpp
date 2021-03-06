class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        for(int i=1; i<=n; i++){
            vector<int> v;
            for(int j=1; j<=i; j++){
                if(j==1 || j==i)
                    v.push_back(1);
                else{
                    int sum=ans[i-2][j-2]+ans[i-2][j-1];
                    v.push_back(sum);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};