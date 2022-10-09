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
    
    vector<int> v;
    void helper(TreeNode* root){
        if(!root)
            return;
        
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        helper(root);
        
        int s=0, e=v.size()-1;
        while(s<e){
            int sum=v[s]+v[e];
            
            if(sum==k)
                return true;
            else if(sum>k)
                e--;
            else
                s++;
        }
        return false;
        
    }
};