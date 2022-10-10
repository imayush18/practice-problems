class Solution {
public:
    string breakPalindrome(string palindrome) {
     
        int len=palindrome.length();
        if(len==1)
            return "";
        
        int i=0;
        
        while(i<len/2){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                return palindrome;
            }
            i++;
        }
        palindrome[len-1]='b';
        return palindrome;
        
    }
};