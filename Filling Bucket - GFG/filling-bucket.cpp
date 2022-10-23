//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // int ans;
    // int mod=100000000;
    
    // void helper(int N){
        
    //     if(N<0)
    //         return;
            
    //     if(N==0){
    //         ans++;
    //         return;
    //     }
        
    //     helper(N-1);
    //     helper(N-2);
    // }
  
    int fillingBucket(int N) {
        
        // ans=0;
        
        // helper(N);
        // return ans%mod;
        
        int ans=1, prev=2, secPrev=1;
        int mod=100000000;

        for(int i=2; i<N; i++){
            ans=(secPrev%mod+prev%mod)%mod;
            secPrev=prev;
            prev=ans;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends