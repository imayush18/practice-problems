// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    void helper(int n, vector<string> &ans, string &s, int opn, int cls){
        if(opn==0 and cls==0){
            ans.push_back(s);
            return;
        }
        
        if(opn!=0){
            string temp=s;
            temp.push_back('(');
            
            helper(n, ans, temp, opn-1, cls);
        }
        
        if(cls>opn){
            string temp=s;
            temp.push_back(')');
            
            helper(n, ans, temp, opn, cls-1);
        }
        
    }
    
    vector<string> AllParenthesis(int n) 
    {
        vector<string> ans;
        string s="";
        
        helper(n, ans, s, n, n);
        return ans;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends