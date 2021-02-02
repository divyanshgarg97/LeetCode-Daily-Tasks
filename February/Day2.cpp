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
    int l1,r1;
    TreeNode* solve(TreeNode* root) {
        if(root == NULL) return NULL;
        TreeNode* l = solve(root->left);
        TreeNode* r = solve(root->right);
        root->left = l;
        root->right = r;
        if(root->val <= r1 && root->val >=l1) {
            return root;
        }
        if(l) return l;
        if(r) return r;
        return NULL;
        
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == NULL) return root;
        l1 = low;r1 = high;
        return solve(root);
    }
};