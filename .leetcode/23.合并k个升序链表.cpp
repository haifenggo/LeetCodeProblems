/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    struct Comp {
        bool operator() (ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){return nullptr;}
        priority_queue<ListNode*,vector<ListNode*>,Comp>q;
        for(ListNode* l:lists){
            if(l){q.push(l);}
        }
        ListNode* k=new ListNode(0),*cur=k;
        while(!q.empty()){
            cur->next=q.top();
            q.pop();
            cur=cur->next;
            if(cur->next){
                q.push(cur->next);
            }
        }
        return k->next;
    }
};
// @lc code=end

