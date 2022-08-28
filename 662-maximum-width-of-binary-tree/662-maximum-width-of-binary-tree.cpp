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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        long ans=INT_MIN;
        
        while(!q.empty()){
            long st=q.front().second;
            long en=q.back().second;
            ans=max(ans, en-st+1);
            
            int n=q.size();
            for(int i=0; i<n; i++){
                pair<TreeNode*, int> p=q.front();
                q.pop();
                
                long parent=p.second;
                TreeNode* node=p.first;
                
                if(node->left){
                    q.push({node->left, (2*parent)+1});
                }
                if(node->right){
                    q.push({node->right, (2*parent)+2});
                }
            }
        }
        
        return ans;
        
    }
};