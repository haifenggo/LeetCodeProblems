/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 */

// @lc code=start
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
    bool isleaf(TreeNode* p){
        return !p->left&&!p->right;
    }
    int dfs(TreeNode* p){
        int ans=0;
        if(p->left){
            if(isleaf(p->left)){
                ans+=p->left->val;
                ans+=dfs(p->left);
            }else{
                ans+=dfs(p->left);
            }
        }
        if(p->right){
            ans+=dfs(p->right);
        }
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)return 0;
        return dfs(root);
    }
};
// @lc code=end

