// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isSafe(vector<int> &temp, int row, int col){
        for(auto x: temp){
            if(x==col)
                return false;
        }
        
        for(int i=0; i<temp.size(); i++){
            if((row-i-1)==abs(col-temp[i])) 
                return false;
        }
        return true;
    }
    
    void helper(vector<vector<int>> &ans, vector<int> &temp, int n, int row){
        if(row>n){
            ans.push_back(temp);
            return;
        }
        
        for(int col=1; col<=n; col++){
            if(isSafe(temp, row, col)){
                temp.push_back(col);
                helper(ans, temp, n, row+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<int> v;
        
        helper(ans, v, n, 1);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends