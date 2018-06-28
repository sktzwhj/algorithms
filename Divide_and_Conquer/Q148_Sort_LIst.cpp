//
// Created by wuhuijun on 12/1/17.
//
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        //use two pointers to find the mid of the linkedlist.
        //NULL not allowed
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //the slow pointer is at the mid now
        fast = slow->next;
        slow->next = NULL;
        ListNode *sortedL = sortList(head);
        ListNode *sortedR = sortList(fast);
        return merge(sortedL, sortedR);

    }

private:
    ListNode *merge(ListNode *left, ListNode *right) {
        if (!left || !right) {
            if (left)return left;
            else if (right) return right;
            else return NULL;
        }
        ListNode *l = left;
        ListNode *r = right;
        ListNode *stub = new ListNode(0);
        ListNode *curr = stub;
        while (l && r) {
            if (l->val <= r->val) {
                curr->next = l;
                l = l->next;
            } else if (l->val > r->val) {
                curr->next = r;
                r = r->next;
            }

            curr = curr->next;
        }

        //just concat the rest by the next of curr since it's the linkedlist
        if (l) curr->next = l;
        else if (r) curr->next = r;;

        return stub->next;
    }
};