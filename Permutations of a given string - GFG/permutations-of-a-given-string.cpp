// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	    void helper(string S, set<string>& ans, int s, int e){
        if(s>=e){
            ans.insert(S);
            return;
        }
        
        for(int i=s; i<e; i++){
            swap(S[s], S[i]);
            helper(S, ans, s+1, e);
            swap(S[s], S[i]);
        }
    }
	
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
            set<string> st;
            helper(S, st, 0, S.length());
            
            for(auto it:st){
                ans.push_back(it);
            }
            sort(ans.begin(), ans.end());
            return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends