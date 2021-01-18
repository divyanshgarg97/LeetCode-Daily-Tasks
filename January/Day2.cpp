/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    void solve(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original == NULL) 
            return;
        if(target == original) {
            ans = cloned;
            return;
        }
        solve(original->left,cloned->left,target);
        solve(original->right,cloned->right,target);
        
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solve(original,cloned,target);
        return ans;
    }
};