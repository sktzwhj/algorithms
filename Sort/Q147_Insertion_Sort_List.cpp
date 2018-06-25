//
// Created by wuhuijun on 6/26/18.
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *curr = NULL, *prev = head;
        curr = prev->next;
        while (curr != NULL) {
            if (curr->val > prev->val) {
                prev = curr;
                curr = prev->next;
            } else {
                ListNode *insert_pos = head;
                ListNode *insert_pos_prev = NULL;
                while (insert_pos->val < curr->val) {
                    insert_pos_prev = insert_pos;
                    insert_pos = insert_pos->next;
                }
                if (insert_pos == head) head = curr;
                else insert_pos_prev->next = curr;
                prev->next = curr->next;
                curr->next = insert_pos;
                curr = prev->next;
            }
            ListNode *tmp = head;
            while (tmp != NULL) {
                cout << tmp->val;
                tmp = tmp->next;
            }
            cout << endl;

        }
        return head;
    }
};

int main() {
    ListNode *t1 = new ListNode(4);
    ListNode *t2 = new ListNode(2);
    ListNode *t3 = new ListNode(1);
    ListNode *t4 = new ListNode(3);
    t1->next = t2;
    t2->next = t3;
    t3->next = t4;
    t4->next = NULL;
    Solution s = Solution();
    ListNode *ret = s.insertionSortList(t1);
    while (ret != NULL) {
        cout << ret->val;
        ret = ret->next;
    }
}