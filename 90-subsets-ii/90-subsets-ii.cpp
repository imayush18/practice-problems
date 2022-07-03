class Solution {
public:
    
    void helper(vector<int> nums, set<string> &s, int i, int N, string x){
        if(i==N){
            if(x==""){
                string a="ayush";
                s.insert(a);  
                
            }
            
            else{
                sort(x.begin(), x.end());
                s.insert(x);
            }
            
            return;
        }
        
        helper(nums, s, i+1, N, x);
        helper(nums, s, i+1, N, x+=nums[i]+'0');
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<string> s;
        
        string x="";
        helper(nums, s, 0, nums.size(), x);
        
        vector<vector<int>> ans;
        for(auto i:s){
            vector<int> v;
           if(i=="ayush"){
               ans.push_back(v);
           }
            else{
                int a=0;
                int len=i.length();
                for(int j=0; j<len; j++){
                    v.push_back(i[j]-'0');
                }
                
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};