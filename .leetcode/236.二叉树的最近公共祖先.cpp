/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
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
    bool dfs(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==nullptr)return false;
        bool l=dfs(root->left,p,q);
        bool r=dfs(root->right,p,q);
        if((l&&r)||((root->val==p->val||root->val==q->val)&&(l||r))){
            ans=root;
        }
        return (root->val==p->val||root->val==q->val)||(l||r);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return ans;
    }
};
// @lc code=end

