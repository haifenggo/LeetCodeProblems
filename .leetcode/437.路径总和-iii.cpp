/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<long,int>mp;
    int dfs(TreeNode* p,long cur,int s){
        if(p==nullptr)return 0;
        int ans=0;
        cur+=p->val;
        if(mp.count(cur-s)){
            ans=mp[cur-s];
        }
        mp[cur]++;
        ans+=dfs(p->left,cur,s);
        ans+=dfs(p->right,cur,s);
        mp[cur]--;
        return ans;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        return dfs(root,0,targetSum);
    }
};
// @lc code=end

