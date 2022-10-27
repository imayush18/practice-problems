//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leafNodes(int arr[],int N) {
        
        stack<int> s;
        s.push(arr[0]);
        vector<int> ans;
        
        for(int i=1; i<N; i++){
            
            if(s.top() < arr[i]){
                int temp=s.top();
                int rem=0;
                    
                while(!s.empty() and s.top() < arr[i]){
                    rem++;
                    s.pop();
                }
                
                if(rem>1){
                    ans.push_back(temp);
                }
            }
            
            s.push(arr[i]);
            
        }
    
        ans.push_back(s.top());
    
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends