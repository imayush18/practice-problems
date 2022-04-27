// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool helper(long long x){
        if(x==1)
            return false;
        if(x==2)
            return true;
        if(x%2==0)
            return false;
            
        for(long long i=3; i*i<=x; i+=2){
            if(x%i==0)
                return false;
        }
        return true;
    }
    
    long long primeProduct(long long L, long long R){
        
        // int p[R+1];
        // primeSeive(p, R, L);
        
        long long prod=1;
        for(long long i=L; i<=R; i++){
            if(helper(i)){
                // cout << i << endl;
                prod*=i;
                prod%=1000000007;
            }
        }
        
        return prod;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends