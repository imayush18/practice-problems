class Solution {
public:
    
//     int helper(vector<int>& jobDifficulty, int d, int len, int i){
//         if(d==1){
//             int maxi=INT_MIN;
//             for(int j=i; j<len; j++){
//                 maxi=max(maxi, jobDifficulty[i]);
            
//             }
//             return maxi;
//         }
        
//         int ans=INT_MAX, cur=INT_MIN;
//         for(int j=i; j<=len-d; j++){
//             cur=max(cur, jobDifficulty[j]);
//             ans=min(ans, cur+helper(jobDifficulty, d-1, len, j+1));
//         }
        
//         return ans;
//     }
    
    
//     int minDifficulty(vector<int>& jobDifficulty, int d) {
        
//         int len=jobDifficulty.size();
//         if(d>len)
//             return -1;
        
//         return helper(jobDifficulty, d, len, 0);
        
//     }
    
    int dp[1001][12];
    int helper(vector<int>& arr,int left,int right,int d){
        if(d == 1){
            return *max_element(arr.begin()+left,arr.end());
        }
        if(dp[left][d] != -1)return dp[left][d];
        int curr = INT_MIN;
        int res = INT_MAX;
        for(int i = left;i<=right-d;i++){
            curr = max(curr,arr[i]);
            res = min(res,curr+helper(arr,i+1,right,d-1));
        }
        return dp[left][d] = res;
    }
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if(n<d)return -1;
        memset(dp,-1,sizeof(dp));
        return helper(arr,0,n,d);
    }
};