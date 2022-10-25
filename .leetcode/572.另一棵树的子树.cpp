/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
    vector<TreeNode*>ans;
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        find(root,subRoot);
        bool f=false;
        for(auto t:ans){
            f=f|check(t,subRoot);
        }
        return f;

    }
    bool check(TreeNode* p, TreeNode* q){
        if(p==nullptr&&q==nullptr){
            return true;
        }else if(p==nullptr)return false;
        else if(q==nullptr)return false;
        else if(p->val!=q->val)return false;
        return check(p->left,q->left)&&check(p->right,q->right);
    }
    void find(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr)return ;
        if(root->val==subRoot->val){
            ans.push_back(root);
        }
        find(root->left,subRoot);
        find(root->right,subRoot);
    }
};
// @lc code=end

