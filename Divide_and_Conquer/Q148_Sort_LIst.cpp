//
// Created by wu061 on 27/06/18.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//to debug, the idea is simple. every time when you got even number of lists, just add one NULL.

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int num_of_lists = lists.size();
        if (num_of_lists == 0) return NULL;
        ListNode *extra_list = NULL;
        if (num_of_lists % 2 == 1) {
            extra_list = lists[num_of_lists - 1];
            lists[num_of_lists - 1] = NULL;
            num_of_lists -= 1;
        }
        while (num_of_lists > 1) {
            for (int i = 0; i < num_of_lists / 2; i++) {
                lists[i] = mergeTwoLists(lists[2 * i], lists[2 * i + 1]);
            }
            num_of_lists /= 2;
            lists.erase(lists.begin() + num_of_lists, lists.end());
        }
        if (extra_list != NULL) return mergeTwoLists(lists[0], extra_list);
        return lists[0];
    }

    ListNode *getListFromVec(vector<int> vec) {
        if (vec.size() == 0)
            return NULL;
        ListNode *head = new ListNode(vec[0]);
        ListNode *last = head;
        for (int i = 1; i < vec.size(); i++) {
            ListNode *tmp = new ListNode(vec[i]);
            last->next = tmp;
            last = tmp;
        }
        last->next = NULL;
        return head;
    }

private:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        if (a == NULL) return b;
        if (b == NULL) return a;
        ListNode *head, *curr, *a_idx = a, *b_idx = b;
        if (a_idx->val < b_idx->val) {
            head = a_idx;
            if (a_idx != NULL) a_idx = a_idx->next;
        } else {
            head = b_idx;
            if (b_idx != NULL) b_idx = b_idx->next;
        }
        curr = head;
        while (a_idx != NULL && b_idx != NULL) {
            if (a_idx->val < b_idx->val) {
                curr->next = a_idx;
                curr = curr->next;
                a_idx = a_idx->next;
            } else {
                curr->next = b_idx;
                curr = curr->next;
                b_idx = b_idx->next;
            }
        }
        while (a_idx != NULL) {
            curr->next = a_idx;
            curr = curr->next;
            a_idx = a_idx->next;
        }
        while (b_idx != NULL) {
            curr->next = b_idx;
            curr = curr->next;
            b_idx = b_idx->next;
        }
        curr->next = NULL;
        return head;
    }


};

int main() {
    Solution s = Solution();
    ListNode *t1 = s.getListFromVec({-10, -9, -9, -3, -1, -1, 0});
    ListNode *t2 = s.getListFromVec({-5});
    ListNode *t3 = s.getListFromVec({4});
    ListNode *t4 = s.getListFromVec({-8});
    ListNode *t5 = s.getListFromVec({});
    ListNode *t6 = s.getListFromVec({-9, -6, -5, -4, -2, 2, 3});
    ListNode *t7 = s.getListFromVec({-3, -3, -2, -1, 0});
    vector<ListNode *> input = {t1, t2, t3, t4, t5, t6, t7};
    ListNode *merged = s.mergeKLists(input);
    while (merged != NULL) {
        cout << merged->val << "->";
        merged = merged->next;
    }
    cout << "NULL" << endl;
}