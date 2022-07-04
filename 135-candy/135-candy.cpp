class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        int arr[len];
        
        for(int i=0; i<len; i++){
            arr[i]=1;
        }
        
        for(int i=0; i<len-1; i++){
            if(ratings[i+1]>ratings[i]){
                arr[i+1]=arr[i]+1;
            }
        }
        
        for(int i=len-2; i>=0; i--){
            if(ratings[i]>ratings[i+1] and arr[i]<=arr[i+1]){
                arr[i]=arr[i+1]+1;
            }
        }
        
        int ans=0;
        for(int i=0; i<len; i++)
        {
            ans+=arr[i];
        }
    
        return ans;
    }
};