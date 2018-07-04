//
// Created by wu061 on 4/07/18.
//

#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        ListNode *curr, *head_small, *head_big, *big, *small;
        ListNode *origin_head = head;
        curr = head;
        big = NULL;
        small = NULL;
        head_small = new ListNode(-1);
        head_big = new ListNode(-1);
        while (curr != NULL) {
            if (curr->val < x) {
                if (small == NULL) small = curr;
                head_small->next = curr;
                head_small = curr;
            } else {
                if (big == NULL) big = curr;
                head_big->next = curr;
                head_big = curr;
            }
            curr = curr->next;
        }
        head_big->next = NULL;
        head_small->next = big;
        return (small == NULL) ? big : small;
    }
};

int main() {
    ListNode *t1 = new ListNode(1);
    t1->next = NULL;
    Solution s = Solution();
    ListNode *ret = s.partition(t1, 0);
    while (ret != NULL) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}