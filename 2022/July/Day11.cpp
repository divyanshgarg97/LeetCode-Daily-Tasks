// https://leetcode.com/problems/binary-tree-right-side-view/

class Solution {
public:
    map<int,int>mp;
    void solve(TreeNode* root,int val) {
        if(root == NULL) return;
        if(mp.find(val) == mp.end()) mp[val] = root->val;
        solve(root->right,val+1);
        solve(root->left,val+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        solve(root,0);
        vector<int> v;
        for(auto i : mp) {
            v.push_back(i.second);
        }
        return v;
    }
};