/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return f(mp,preorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* f(unordered_map<int,int>&mp,vector<int>& preorder,int pl,int pr,int il,int ir){
        if(pl>pr)return nullptr;
        int pp=pl;
        int ip=mp[preorder[pp]];
        int len=ip-il;
        TreeNode* node=new TreeNode(preorder[pl]);
        node->left=f(mp,preorder,pl+1,pl+len,il,ip-1);
        node->right=f(mp,preorder,pl+len+1,pr,ip+1,ir);
        return node;
    }
};
// @lc code=end

