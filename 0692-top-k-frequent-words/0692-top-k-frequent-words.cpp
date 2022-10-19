class Solution {
public:
    
    static bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if(a.second==b.second)
            return a.first < b.first;
        return (a.second > b.second);
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> m;
        for(auto x: words){
            m[x]++;
        }
        
        vector<pair<string, int>> vec;
 
        for(auto it: m) {
            vec.push_back(it);
        }
  
   
        sort(vec.begin(), vec.end(), cmp);
        // for(auto it: vec){
        //     cout << it.first << "    " << it.second << endl; 
        // }
        vector<string> ans;
        
        for(auto it: vec){
            if(k==0)
                break;
            ans.push_back(it.first);
            k--;
        }
        
        // sort(ans.begin(), ans.end());
        return ans;
        
    }
};