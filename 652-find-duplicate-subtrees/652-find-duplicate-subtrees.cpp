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
    
unordered_map <string, int> mp;
vector<TreeNode*> ans;
    
string helper(TreeNode* root){
    
    string s="!";
    if(!root){
        return s;
    }
        
    // if(!root->left and !root->right){
    //     s+=to_string(root->data);
    //     mp[s]++;
    //     return s;
    // }
        
    s+=to_string(root->val);
    s+=helper(root->left);
    s+=helper(root->right);
        
    mp[s]++;
    if(mp[s]==2)
        ans.push_back(root);
        
    return s;
}
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         ans.clear();
    mp.clear();
    
    helper(root);
        
        return ans;
    }
};