class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> s(nums.begin(), nums.end());
        
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            int temp=1;
            int less=nums[i]-1;
            if(s.find(less)!=s.end()){
                continue;
            }
            
            int num=nums[i]+1;
            while(s.find(num)!=s.end()){
                temp++;
                num++;
            }
            ans=max(ans, temp);
        }
        
        return ans;
    }
};