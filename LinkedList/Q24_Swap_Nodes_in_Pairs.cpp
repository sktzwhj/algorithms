//
// Created by wu061 on 27/11/17.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *curr, *next, *last;
        if (head && head->next) {
            curr = head;
            next = curr->next;
            head = next;
            last = NULL;
        } else
            return head;
        while (next) {
            ListNode *tmp;
            tmp = curr;
            curr->next = next->next;
            next->next = curr;
            if (last)last->next = next;
            if (curr->next && curr->next->next) {
                last = curr;
                curr = curr->next;
                next = curr->next;
            } else
                break;
        }
        return head;
    }
};

int main() {
    ListNode *nodes[4];
    for (int i = 0; i < 4; i++) {
        nodes[i] = (ListNode *) malloc(sizeof(ListNode));
        nodes[i]->val = i + 1;
    }

    for (int i = 0; i < 3; i++)
        nodes[i]->next = nodes[i + 1];

    ListNode *head = nodes[0];
    while (head) {
        cout << head->val << endl;
        head = head->next;
    }
    nodes[3]->next = NULL;
    Solution s = Solution();
    s.swapPairs(head);
}
