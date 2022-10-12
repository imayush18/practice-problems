//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int i;
    
    string helper(string s){
        string ans;
        while(i<s.length()){
            
            if(s[i]>='0' and s[i]<='9'){
                int n=0;
                while(s[i]>='0' and s[i]<='9'){
                    n=(n*10)+(s[i]-'0');
                    i++;
                }
                i++;
                string temp=helper(s);
                while(n>0){
                    ans.append(temp);
                    n--;
                }
            }
            
            else{
                if(s[i]==']'){
                    i++;
                    return ans;
                }
                else{
                    ans+=s[i];
                    i++;
                }
            }
        }
        return ans;
    }

    string decodedString(string s){
        i=0;
        return helper(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends