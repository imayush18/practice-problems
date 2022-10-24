class Solution {
public:
    string minWindow(string s, string t) {
        
//         unordered_map<char, int> mp;
//         for(int i=0; i<t.length(); i++){
//             mp[t[i]]++;
//         }
        
//         int x=0;
//         int j=-1;
//         string ans="";
//         unordered_map<char, int> temp;
        
//         for(int i=0; i<s.length(); i++){
            
//             char c=s[i];
//             temp[c]++;
            
//             if(mp.find(c)!=mp.end()){
//                 int req=mp[c];
//                 if(req>temp[c]-1){
//                     x++;
//                 }
//             }           
            
//             if(x==t.length()){
//                 string cur=s.substr(j+1, i-j);
//                 cout << cur << endl;
                
//                 if(ans.length()==0 or ans.length()>cur.length()){
//                     ans=cur;
//                 }
                
//                 while(j<i and x==t.length()){
//                     j++;
//                     char q=s[j];
//                     if(mp.find(q)!=mp.end()){
//                         int val=temp[j];
//                         if(val<mp[q]+1){
//                             x--;
//                         }
//                     }
                    
//                     temp[q]--; 
//                 }
                
//             }   
//         }
        
//         return ans;
        
//         string ans="";
        
//         unordered_map<char, int> mp;
//         for(int i=0; i<t.length(); i++){
//             mp[t[i]]++;
//         }
        
//         int mct=0;
//         int dmct=t.length();
//         unordered_map<char, int> mp1;
//         int i=-1, j=-1;
        
//         while(true){
//             bool f1=true, f2=true;
            
//             while(i<s.length()-1 and mct<dmct){
//                 cout << "Aa" << endl;
//                 f1=false;
//                 i++;
//                 char c=s[i];
//                 mp1[c]++;
                
//                 if(mp.find(c)!=mp.end() and mp1[c] <= mp[c]){
//                     mct++;
//                 }
//             }
            
//             while(j<i and mct==dmct){
//                 f2=false;
//                 string pans=s.substr(j+1, i-j);
//                 cout << s << endl;
//                 if(ans.length()==0 or ans.length() > pans.length()){
//                     ans=pans;
//                 }
                
//                 j++;
//                 char c=s[j];
//                 mp1[c]--;
//                 if(mp.find(c)!=mp.end() and mp1[c] < mp[c])
//                     mct--;
//             }
            
//             if(f1 and f2){
//                 break;
//             }
//         }
        
//         return ans;
        
        
//         int n = str.size();
//         map<int, int> map;
//         for (char c : target)
//             ++map[c];

//         int minLen = n + 1;
//         int count = 0;
//         int k = map.size();

//         string result = "";

//         int i = 0, j = 0;
//         while (j < n) {
//             if (count < k) {
//                 if (map.count(str[j])) {
//                     --map[str[j]];
//                     if (map[str[j]] == 0)
//                         ++count;
//                 }
//                 ++j;
//             }
//             while (count == k) {
//                 if (minLen > j - i) {
//                     minLen = j - i;
//                     result = str.substr(i, j - i);
//                 }

//                 if (map.count(str[i])) {
//                     ++map[str[i]];
//                     if (map[str[i]] == 1)
//                         --count;
//                 }
//                 ++i;
//             }
//         }

//         return result;
        
        
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
            return "";
        
        return s.substr(ansStart, minLen);
        
    }
};