// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans(2);
        sort(candies, candies+N);
        
        int j=N-1;
        int mini=0, maxi=0;
        for(int i=0; i<N; i++){
            if(i>j)
                break;
            mini+=candies[i];
            j-=K;
        }
        
        j=0;
        for(int i=N-1; i>=0; i--){
            if(j>i)
                break;
            maxi+=candies[i];
            j+=K;
        }
        
        ans[0]=mini;
        ans[1]=maxi;
        
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
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends