/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* helper(vector<int> in, vector<int> post, int n, map<int, int> &mp , int &index, int inorderStart, int                                     inorderEnd){
        
        if(index<0 || inorderStart>inorderEnd){
            return NULL;
        }
        
        int element=post[index];
        index--;
        TreeNode* root=new TreeNode(element);
        
        int pos=mp[element];
        
        root->right=helper(in, post, n, mp, index, pos+1, inorderEnd);
        root->left=helper(in, post, n, mp, index, inorderStart, pos-1);
        
        return root;
}
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[in[i]]=i;
        }
    
        int index=n-1;
        return helper(in, post, n, mp, index, 0, n-1);
    }
};