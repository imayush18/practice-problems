class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1=="0" or num2=="0")
            return "0";
        
        vector<int> temp(num1.size()+num2.size(), 0);
        
        for(int i=num1.size()-1; i>=0; i--){
            for(int j=num2.size()-1; j>=0; j--){
                temp[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                temp[i+j] += temp[i+j+1]/10;
                temp[i+j+1] %= 10;
            }
        }
        
        int i=0;
        while(i<temp.size() and temp[i]==0){
            i++;
        }
        
        string ans="";
        for(; i<temp.size(); i++){
            ans+=temp[i]+'0';
        }
        
        
        return ans;
        
    }
};