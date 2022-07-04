class Solution {
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
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        
        helper(n, ans, s, n, n);
        return ans;
    }
};