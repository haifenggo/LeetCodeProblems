/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return f(root)!=-1;
    }
    int f(TreeNode* p){
        if(!p){return 0;}
        int l=f(p->left),r=f(p->right);
        if(l==-1||r==-1||abs(r-l)>1){
            return -1;
        }
        return 1+max(l,r);
    }
};
// @lc code=end

