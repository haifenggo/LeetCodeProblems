/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
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
    unordered_set<int> hashTable;

    bool findTarget(TreeNode *root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (hashTable.count(k - root->val)) {
            return true;
        }
        hashTable.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    // unordered_map<int,bool>mp;
    // bool f=0;
    // void dfs(TreeNode*p,int& k){
    //     if(!p||f)return;
    //     dfs(p->left,k);
    //     if(mp[k-p->val]){
    //         f=1;return;
    //     }
    //     mp[p->val]=1;
    //     dfs(p->right,k);
    // }
    // bool findTarget(TreeNode* root, int k) {
    //     dfs(root,k);
    //     return f;
    // }
};
// @lc code=end

