class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp ;
        for(auto it : t) mp[it]++ ;
        
        int count = mp.size() , l=0 , r=0 ;
        string ans="" ;
        
        while(r < s.length())
        {
            if(mp.find(s[r]) != mp.end()) 
            {
                mp[s[r]]-- ;
                if(!mp[s[r]]) count--;
            }
            if(!count)
            {
                if(ans.empty()) ans = s.substr(l,r-l+1);
                if(r-l+1 < ans.length()) ans = s.substr(l,r-l+1);
                
                while(mp.find(s[l]) == mp.end() || mp[s[l]] < 0)
                {
                    if(mp.find(s[l]) != mp.end() && mp[s[l]] < 0)
                    {
                        mp[s[l]]++ ;
                        if(mp[s[l]] > 0) count++ ;
                    }
                    l++;
                    if(r-l+1 < ans.length()) ans = s.substr(l,r-l+1);
                }
            }
            r++;
        }
        return ans;
    }
};