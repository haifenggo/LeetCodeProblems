/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>dir(to_delete.begin(),to_delete.end());
        vector<TreeNode*>ans;
        root=f(root,ans,dir);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
    TreeNode* f(TreeNode* p,vector<TreeNode*>&ans,set<int>&dir){
        if(p==nullptr)return nullptr;
        p->left=f(p->left,ans,dir);
        p->right=f(p->right,ans,dir);
        if(dir.count(p->val)){
            if(p->left){
               ans.push_back(p->left);
            }
            if(p->right){
                ans.push_back(p->right);
            }
            p=nullptr;
        }
        return p;
    }
};
// @lc code=end

