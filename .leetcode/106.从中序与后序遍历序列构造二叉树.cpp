/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    unordered_map<int,int>mp;
    TreeNode* dfs(int l,int r,int ll,int rr,vector<int>& postorder){
        if(l>r||ll>rr)return nullptr;
        TreeNode* p=new TreeNode(postorder[r]);
        if(l+1>r)return p;
        int index=mp[postorder[r]];
        int len=index-ll;
        p->left=dfs(l,l+len-1,ll,index-1,postorder);
        p->right=dfs(l+len,r-1,index+1,rr,postorder);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return dfs(0,postorder.size()-1,0,postorder.size()-1,postorder);
    }
};
// @lc code=end

