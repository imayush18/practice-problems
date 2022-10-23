//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    
    int ans;
    
    void dfs(int i, int n, int m){
        if(i>m)
            return;
        
        if(i>=n and i<=m)
            ans++;
        
        int x=i%10;
        
        if(x==0){
            dfs((i*10)+1, n, m);
        }
        
        else if(x==9){
             dfs((i*10)+8, n, m);
        }
        
        else{
            dfs((i*10)+x+1, n, m);
            dfs((i*10)+x-1, n, m);
        }
    }


    int steppingNumbers(int n, int m)
    {
        ans=0;   
        for(int i=1; i<=9; i++){
            dfs(i, n, m);
        }
        
        if(n==0)
            ans++;
            
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends