class Solution {
public:
    
    bool helper(int *freq, int *temp){
        for(int i=0; i<26; i++){
            if(freq[i]!=temp[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length()>s2.length())
            return false;
        
        int freq[26]={0};
        for(int i=0; i<s1.length(); i++){
            freq[s1[i]-'a']++;
        }
//         for(int i=0; i<26; i++){
//             cout << freq[i] << " ";
//         }
//         cout << endl;
        
        int temp[26]={0};
        for(int i=0; i<s1.length(); i++){
            temp[s2[i]-'a']++;
        }
        for(int i=s1.length(); i<s2.length(); i++){
            if(helper(freq, temp))
                return true;
            
            temp[s2[i]-'a']++;
            temp[s2[i-s1.length()]-'a']--;
        }
        if(helper(freq, temp))
            return true;
        return false;
    }
};