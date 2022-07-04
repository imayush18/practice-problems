class Solution {
public:
    
    void helper(vector<int>& nums, vector<vector<int>>& ans, int s, int e){
        if(s>=e){
            ans.push_back(nums);
            return;
        }
        
        for(int i=s; i<e; i++){
            swap(nums[s], nums[i]);
            helper(nums, ans, s+1, e);
            swap(nums[s], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        // vector<int> v;
        helper(nums, ans, 0, nums.size());
        return ans;
    }
};