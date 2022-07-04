// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    bool helper(string s, set<string> st, int i){
        if(i==s.length())
            return true;
        
        for(int x=i; x<s.length(); x++){
            string temp=s.substr(i, x-i+1);
            if(st.find(temp)!=st.end() and helper(s, st, x+1))
                return true;
          
        }
        return false;
    }
    

    int wordBreak(string A, vector<string> &B) {
    
        set<string> st;
        
        for(auto it: B){
            st.insert(it);
        }
        
        if(helper(A, st, 0))
            return 1;
        return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends