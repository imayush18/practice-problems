class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int i, j;
        int n=nums.size();
        
        for(i=n-2; i>=0; i--){
            if(nums[i+1]>nums[i])
                break;
        }
        
        if(i==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        for(j=n-1; j>=0; j--){
            if(nums[j]>nums[i])
                break;
        }
        
        // cout << i << " " << j << endl;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin()+i+1, nums.end());
        
    }
};