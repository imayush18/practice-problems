// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    
    
    void helper(vector<int> nums, set<string> &s, int i, int N, string x){
        if(i==N){
            if(x==""){
                string a="ayush";
                s.insert(a);  
            }
            
            else{
                sort(x.begin(), x.end());
                s.insert(x);
            }
            
            return;
        }
        
        helper(nums, s, i+1, N, x);
        helper(nums, s, i+1, N, x+=nums[i]+'0');
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        set<string> s;
        
        string x="";
        helper(arr, s, 0, n, x);
        
        vector<vector<int>> ans;
        vector<int> v1;
        ans.push_back(v1);
        for(auto i:s){
            vector<int> v;
            if(i=="ayush"){
                // ans.push_back(v);
            }
            else{
                int a=0;
                int len=i.length();
                for(int j=0; j<len; j++){
                    v.push_back(i[j]-'0');
                }
                
                ans.push_back(v);
            }
        }
        
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
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends