/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    
    void dfs(TreeNode* p,vector<TreeNode*>&ans){
        if(p==nullptr)return ;
        dfs(p->left,ans);
        ans.push_back(p);
        dfs(p->right,ans);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*>ans;
        dfs(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            ans[i]->left=nullptr;
            ans[i]->right=ans[i+1];
        }
        ans[ans.size()-1]->left=nullptr;
        ans[ans.size()-1]->right=nullptr;
        return ans[0];
    }
};
// @lc code=end

