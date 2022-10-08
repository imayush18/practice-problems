class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int diff=INT_MAX;
        int ans=0;
        
        for(int i=0; i<nums.size()-2; i++){
            int val=nums[i];
            int newTar=target-val;
            
            int left=i+1;
            int right=nums.size()-1;
            int sum;
            
            while(left<right){
                sum=nums[left]+nums[right];
                
                if(sum==newTar)
                    return target;
                else if(sum>newTar)
                    right--;
                else
                    left++;
                
                int x=abs(newTar-sum);
                if(x<diff){
                    ans=sum+val;
                    diff=x;
                }
            }
        }
        return ans;
        
    }
};