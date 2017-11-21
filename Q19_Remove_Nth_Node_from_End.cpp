//
// Created by wuhuijun on 11/22/17.
//
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
        while(before->next != NULL){
            before = before->next;
            after = after->next;
        }
        after->next = after->next->next;
        return head;

    }
};
