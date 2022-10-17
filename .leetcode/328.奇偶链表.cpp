/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* headnext=head->next;
        ListNode* odd=head,*even=head->next,*cur=head->next->next;
        while(even&&even->next){
            odd->next=even->next;
            odd=even->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next=headnext;
        return head;
    }
};
// @lc code=end

