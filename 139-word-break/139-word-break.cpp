class Solution {
public:
    
    map<int, bool> dp;
    
    bool helper(string s, set<string> st, int i){
        if(i==s.length())
            return true;
        
        if(dp.find(i)!=dp.end()){
            return dp[i];
        }
        
        // int 
        for(int x=i; x<s.length(); x++){
            string temp=s.substr(i, x-i+1);
            if(st.find(temp)!=st.end() and helper(s, st, x+1)){
                dp[i]=true;
                return true;
            }          
        }
        dp[i]=false;
        return false;
    
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        set<string> st;
        
        for(auto it: wordDict){
            st.insert(it);
        }
        
        if(helper(s, st, 0))
            return true;
        return false;
        
    }
};