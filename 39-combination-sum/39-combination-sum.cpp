class Solution {
public:
    
    void helper(vector<int> candi, int target, int i, vector<int> &v, vector<vector<int>> &ans){
        
        if(i==candi.size()){
            if(target==0){
                ans.push_back(v);
            }
            return;
        }
        
        if(candi[i]<=target){
            v.push_back(candi[i]);
            helper(candi, target-candi[i], i, v, ans);
            v.pop_back();
        }
        
        helper(candi, target, i+1, v, ans);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  
        
        vector<vector<int>> ans;
        vector<int> v;
        helper(candidates, target, 0, v, ans);
      
        
        return ans;
    }
};