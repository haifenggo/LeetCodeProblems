/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if(!head){return head;}
        int len=0;
        ListNode* cur=head;
        while(cur){
            len++;
            cur=cur->next;
        }
        ListNode* h=new ListNode(0,head);
        for(int li=1;li<len;li<<=1){
            ListNode* pre=h,*cur=h->next;
            while(cur){
                ListNode* h1=cur;
                for(int i=1;i<li&&cur->next;i++){
                    cur=cur->next;
                }
                ListNode* h2=cur->next;
                cur->next=nullptr;
                cur=h2;
                for(int i=1;i<li&&cur&&cur->next;i++){
                    cur=cur->next;
                }
                ListNode* next=nullptr;
                if(cur){
                    next=cur->next;
                    cur->next=nullptr;
                }
                ListNode* mg=merge(h1,h2);
                pre->next=mg;
                while(pre->next){
                    pre=pre->next;
                }
                cur=next;
            }
        }
        return h->next;
    }
    ListNode* merge(ListNode* h1,ListNode* h2){
        ListNode * node=new ListNode(0);
        ListNode* t=node,*l1=h1,*l2=h2;
        while(l1&&l2){
            if(l1->val<=l2->val){
                t->next=l1;
                t=l1;
                l1=l1->next;
            }else{
                t->next=l2;
                t=l2;
                l2=l2->next;
            }
        }
        if(l1==nullptr){
            t->next=l2;
        }else{
            t->next=l1;
        }
        return node->next;
    }
};
// @lc code=end

