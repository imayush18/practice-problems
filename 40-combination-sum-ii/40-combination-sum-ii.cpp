class Solution {
public:
    
    void helper(vector<int>& candi, int target, int i, vector<int> &v, vector<vector<int>> &ans){
        
        if(target==0){
            ans.push_back(v);
            return;
        }   
        
        for(int j=i; j<candi.size(); j++){
            if(j>i and candi[j-1]==candi[j])
                continue;
                
            if(candi[j]>target)
                break;
            
            v.push_back(candi[j]);
            helper(candi, target-candi[j], j+1, v, ans);
            v.pop_back();
        }
        
        
        // helper(candi, target, i+1, v, ans);
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> v;
        vector<vector<int>> ans;
        helper(candidates, target, 0, v, ans);
        
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        
        
        return ans;
    }
};