//
// Created by wuhuijun on 12/16/17.
//

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//typical two pointer problem

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL)
            return NULL;
        ListNode *slow = head, *fast = head;
        int len = 0;
        ListNode *tmp = head;
        while (tmp != NULL) {
            tmp = tmp->next;
            len++;
        }
        //deal with the case where k >= len
        k %= len;
        //if k is 0, do nothing
        if (k == 0)
            return head;
        while (k > 0 && fast != NULL) {
            fast = fast->next;
            k--;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        fast->next = head;
        slow->next = NULL;
        return newHead;
    }
};