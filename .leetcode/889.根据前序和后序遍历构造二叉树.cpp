/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* dfs(int l,int r,int ll,int rr,vector<int>& preorder){
        if(l>r||ll>rr)return nullptr;
        TreeNode* p=new TreeNode(preorder[l]);
        if(l+1>r)return p;
        int li=mp[preorder[l+1]];
        int len=li-ll;
        p->left=dfs(l+1,l+len+1,ll,li,preorder);
        p->right=dfs(l+len+2,r,li+1,rr-1,preorder);
        return p;

    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n=postorder.size();
        for(int i=0;i<n;i++){
            mp[postorder[i]]=i;
        }
        return dfs(0,n-1,0,n-1,preorder);
    }
};
// @lc code=end

