/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
    void recoverTree(TreeNode* root) {
        TreeNode* p=nullptr;
        TreeNode* pre=nullptr;
        TreeNode* x=nullptr;
        TreeNode* y=nullptr;
        while(root){
            if(root->left){
                p=root->left;
                while(p->right&&p->right!=root){
                    p=p->right;
                }
                if(p->right==nullptr){
                    p->right=root;
                    root=root->left;
                }else{
                    if(pre&&pre->val>root->val){
                        y=root;
                        if(x==nullptr)x=pre;
                    }
                    pre=root;
                    p->right=nullptr;
                    root=root->right;
                }


            }
            else{
                if(pre&&pre->val>root->val){
                    y=root;
                    if(x==nullptr)x=pre;
                }
                pre=root;
                root=root->right;
            }


           


        }
        swap(x->val,y->val);

    }
};
// @lc code=end

