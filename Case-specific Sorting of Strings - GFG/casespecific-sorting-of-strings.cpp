//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string temp=str;
        sort(temp.begin(), temp.end());
        int start=-1;
        
        for(int i=0; i<n; i++){
            if(temp[i]>='a' and temp[i]<='z'){
                start=i;
                break;
            }
        }
        
        if(start==-1 or start==0)
            return temp;
            
        int i=0;
        for(int j=0; j<n; j++){
            if(str[j]>='a' and str[j]<='z'){
                str[j]=temp[start++];
            }
            else{
                str[j]=temp[i++];
            }
        }
        
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends