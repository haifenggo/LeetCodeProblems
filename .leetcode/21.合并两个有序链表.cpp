/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr)return list2;
        if(list2==nullptr)return list1;
        ListNode* head=nullptr;
        if(list1->val<=list2->val){
            head=list1;
            list1=list1->next;
        }else{
            head=list2;
            list2=list2->next;
        }
        ListNode* cur=head;
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val<=list2->val){
                cur->next=list1;
                cur=cur->next;
                list1=list1->next;
            }else{
                cur->next=list2;
                cur=cur->next;
                list2=list2->next;
            }
        }
        if(list1==nullptr){
            cur->next=list2;
        }else{
            cur->next=list1;
        }
        return head;
    }
};
// @lc code=end

