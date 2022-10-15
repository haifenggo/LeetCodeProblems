/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode* next=head->next;
        if(next==nullptr)return head;
        ListNode* cur=next->next;
        next->next=head;
        head->next=cur;
        ListNode* pre=head;
        head=next;
        while(cur!=nullptr&&cur->next!=nullptr){
            next=cur->next;
            pre->next=next;
            cur->next=next->next;
            next->next=cur;
            pre=cur;
            cur=cur->next;
        }
        return head;
    }
};
// @lc code=end

