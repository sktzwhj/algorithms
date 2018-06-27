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

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int num_of_lists = lists.size();
        ListNode* extra_list = NULL;
        if (num_of_lists %2 == 1) {
            extra_list = lists[lists.size() - 1];
            lists.pop_back();
            num_of_lists -= 1;
        }
        while (num_of_lists > 1) {
            for(int i = 0; i < num_of_lists / 2; i++) {
                lists[i] = mergeTwoLists(lists[2*i], lists[2*i + 1]);
            }
            num_of_lists /= 2;
        }
        if(extra_list != NULL) return mergeTwoLists(lists[0], extra_list);
        return lists[0];
    }

private:
    ListNode *mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *head, *curr, *a_idx = a, *b_idx = b;
        if (a_idx->val < b->val) {
            head = a_idx;
            if (a_idx->next!=NULL) a_idx = a_idx->next;
        }
        else {
            head = b_idx;
            if (b_idx->next!=NULL) b_idx = b_idx->next;
        }
        curr = head;
        while(a_idx->next != NULL && b_idx->next != NULL) {
            if (a_idx->val < b->val) {
                curr->next = a_idx;
                curr = curr->next;
                a_idx = a_idx->next;
            }
            else {
                curr->next = b_idx;
                curr = curr->next;
                b_idx = b_idx->next;
            }
        }
        while(a_idx->next != NULL) {
            curr->next = a_idx;
            curr = curr->next;
            a_idx = a_idx->next;
        }
        while(b_idx->next != NULL) {
            curr->next = b_idx;
            curr = curr->next;
            b_idx = b_idx->next;
        }
        curr->next = NULL;
        return head;
    }
};

int main() {
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(4);
    ListNode *t3 = new ListNode(5);
    t1->next = t2;
    t2->next = t3;
    t3->next = NULL;
    ListNode *t4 = new ListNode(1);
    ListNode *t5 = new ListNode(3);
    ListNode *t6 = new ListNode(4);
    t4->next = t5;
    t5->next = t6;
    t6->next = NULL;
    ListNode *t7 = new ListNode(2);
    ListNode *t8 = new ListNode(6);
    t7->next = t8;
    t8->next = NULL;
    Solution s = Solution();
    vector<ListNode*> input = {t1, t4, t7};
    ListNode *merged = s.mergeKLists(input);
    while(merged != NULL) {
        cout<<merged->val<<"->";
        merged = merged->next;
    }
    cout<<"NULL"<<endl;
}