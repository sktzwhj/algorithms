//
// Created by wuhuijun on 11/22/17.
//
/*
 * typical problem of two pointers. using two pointers to find the nth node from the end of the linkedlist,
 * you just let one pointer to go n steps first.
 */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode* before = head;
        ListNode* after = head;
        for(int i = 0; i < n; i++)
            before = before->next;
        if(before == NULL){
            //if before == NULL, n=len(list), we are deleting the head.
            head = head->next;
            return head;
        }
        while(before->next != NULL){
            before = before->next;
            after = after->next;
        }
        after->next = after->next->next;

        return head;

    }
};
