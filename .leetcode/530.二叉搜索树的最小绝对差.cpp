/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void dfs(TreeNode* p,int& pre,int &ans){
        if(!p)return ;
        dfs(p->left,pre,ans);
        ans=min(ans,abs(p->val-pre));
        pre=p->val;
        dfs(p->right,pre,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=1000000;
        int pre=100000000;
        dfs(root,pre,ans);
        return ans;
    }
};
// @lc code=end

