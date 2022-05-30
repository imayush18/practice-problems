// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        int hol = S/7;
       float x = (float)N/(float)M;
       if(x<=1)
           return -1;
       int buy = ceil(S/x);
       if(S-hol<buy)
           return -1;
       return buy;
   
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  // } Driver Code Ends