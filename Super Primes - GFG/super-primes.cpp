// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

    void primeSeive(int *p, int n){
        for(int i=0; i<=n; i++){
            p[i]=1;
        }
        
        for(int i=2; i<=n; i++){
            if(p[i]){
                for(int j=i+i; j<=n; j+=i){
                    p[j]=0;
                }
            }
        }
        
        p[0]=p[1]=0;
    }
	
	int superPrimes(int n)
	{
	    int prime[n+1];
	    primeSeive(prime, n);
	    
	   // for(int i=0; i<n; i++){
	   //     cout << prime[i] << " ";
	   // }
	   // cout << endl;
	   
	   //vector<int> ans(n+1, 0);
	   //for(int i=2; i<=n; i++){
	   //    if(prime[i]){
	   //        if(prev!=-1){
	   //            prev=-1;
	   //            int sum=prev+i;
	   //            ans[sum]=ans[sum-1]+1;
	               
	   //        }
	   //    }
	   //}
	   
	   int ans=0;
	   for(int i=5; i<=n; i+=2){
	       if(prime[i] and prime[i-2])
	            ans++;
	   }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends