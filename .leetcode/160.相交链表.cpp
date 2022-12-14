/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA,*l2=headB;
        while(l1!=l2){
            l1=l1?l1->next:headB;
            l2=l2?l2->next:headA;
        }
        return l1;

        // ListNode* tail=headA;
        // while(tail->next!=nullptr){tail=tail->next;}
        // tail->next=headB;
        // ListNode* slow=headA,*fast=headA;
        // do{
        //     if(fast->next==nullptr||fast->next->next==nullptr){
        //         tail->next=nullptr;
        //         return nullptr;
        //     }
        //     fast=fast->next->next;
        //     slow=slow->next;
        // }while(slow!=fast);
        // slow=headA;
        // while(slow!=fast){
        //     fast=fast->next;
        //     slow=slow->next;
        // }
        // tail->next=nullptr;
        // return slow;

        
    }
};
// @lc code=end

