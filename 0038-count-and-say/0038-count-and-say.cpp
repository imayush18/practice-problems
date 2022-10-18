class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string currStr = countAndSay(n-1);
        string ans = countSub(currStr);
        return ans;
    }

    string countSub(string s) {
        string str;
        int i = 0, count = 0, n = s.length();
        while(i < n) {
            char num = s[i];
            while(i < n && num == s[i]) {
                i++;
                count++;
            }
            char temp = count+'0';
            str.push_back(temp);
            str.push_back(num);
            count = 0;
        }
        return str;
    }
};