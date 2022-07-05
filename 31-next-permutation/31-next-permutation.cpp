class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int jiskoswap, jiskesathswap, n = nums.size();
        for(jiskoswap = n-2; jiskoswap >= 0; jiskoswap--){
            if(nums[jiskoswap] < nums[jiskoswap+1]) break;
        }
        
        if(jiskoswap<0)
            reverse(nums.begin(), nums.end());
        else{
        for(jiskesathswap = n-1; jiskesathswap > jiskoswap; jiskesathswap--){
            if(nums[jiskesathswap] > nums[jiskoswap]) break;
        }
        
        swap(nums[jiskoswap], nums[jiskesathswap]);
        reverse(nums.begin() + jiskoswap + 1, nums.end());
        }
    }
    
};