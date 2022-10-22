/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        double ans=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ret;
        while(!q.empty()){
            ans=0;
            int n=q.size();
            for(int i=1;i<=n;i++){
                auto p=q.front();
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
                q.pop();
                ans+=p->val;
            }
            ret.push_back(ans/n);
        }
        return ret;
    }
};
// @lc code=end

