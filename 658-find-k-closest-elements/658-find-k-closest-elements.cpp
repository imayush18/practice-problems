class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int l=0;
        int r=arr.size()-1;
        vector<int> ans;
        
        while(l<=r){
            
            if((r-l)+1 > k){ 
                
                if(abs(arr[l] - x) > abs(arr[r] - x))
                    l++;
                
                else
                    r--;
            }
            
            else{
                ans.push_back(arr[l]);
                l++;
            }
        }
        
        return ans;
    }
};