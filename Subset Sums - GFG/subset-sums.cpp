// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    void helper(vector<int> &ans, vector<int> arr, int N, int sum, int i){
        
        if(i==N){
            ans.push_back(sum);
            return;
        }
        
        helper(ans, arr, N, sum+arr[i], i+1);
        helper(ans, arr, N, sum, i+1);
        
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        
        helper(ans, arr, N, 0, 0);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends