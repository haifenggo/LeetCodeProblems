/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string str="";
        dfs(root,str,ans);
        return ans;
    }
    void dfs(TreeNode* cur,string str,vector<string>&ans){
        if(cur==nullptr){return;}
        str+=to_string(cur->val);
        if(cur->left==nullptr&&cur->right==nullptr){
            
            ans.push_back(str);
        }else{
            str+="->";
            dfs(cur->left,str,ans);
            dfs(cur->right,str,ans);
        }
        

    }
};
// @lc code=end

