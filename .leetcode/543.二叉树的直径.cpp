/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        deep(root,ans);
        return ans;
    }
    int deep(TreeNode* p,int& ans){
        if(p==nullptr){return 0;}
        int l=deep(p->left,ans),r=deep(p->right,ans);
        ans=max(ans,l+r);
        return 1+max(l,r);
    }
};
// @lc code=end

