/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    int findBottomLeftValue(TreeNode* root) {
        int ans=root->val;
        queue<TreeNode*>q;
        if(root->left)q.push(root->left);
        if(root->right)q.push(root->right);
        while(!q.empty()){
            ans=q.front()->val;
            int n=q.size();
            while(n--){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right)q.push(cur->right);
            }
        }
        return ans;
    }
};
// @lc code=end

