//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        vector<int> freq(256, 0);
        for(int i=0; i<t.length(); i++){
            freq[t[i]]++;
        }
        
        int start=0, end=0, ansStart=start, count=0, minLen=INT_MAX;
        
        while(end < s.length()){
            
            char c=s[end];
            if(freq[c]>0){
                count++;
            }
            freq[c]--;
            
            while(count==t.length()){
                if(minLen > (end-start+1)){
                    minLen=end-start+1;
                    ansStart=start;
                }
                freq[s[start]]++;
                if(freq[s[start]] > 0)
                    count--;
                
                start++;
            }
            end++;
        }
        
        if(minLen==INT_MAX)
            return "-1";
        
        return s.substr(ansStart, minLen);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends