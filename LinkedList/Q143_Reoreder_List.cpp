//
// Created by wu061 on 3/12/17.
//

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

//initial solution, works but so slow...
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode *p = head;
        int listLen = 0;
        while(p->next != NULL){
            p = p->next;
            listLen += 1;
        }
        //cout<<"listLen is "<<listLen<<endl;
        //ListNode *end = p;
        //connect the head and the tail of the linkedlist
        int stepLen = listLen;
        ListNode *curr = head, *base = head;
        ListNode *retNext = NULL;
        while(stepLen > 0){
            int tmpStepLen = stepLen;
            //cout<<"tmpStepLen is "<<tmpStepLen<<endl;
            retNext = base->next;
            while(tmpStepLen > 0){
                curr = curr->next;
                tmpStepLen--;
            }
            if(retNext == curr){
                base->next = curr;
                curr->next = NULL;
                break;
            }
            //cout<<"curr is "<<curr->val<<endl;
            base->next = curr;
            curr->next = retNext;
            base = retNext;
            curr = base;
            stepLen -= 2;
            if(stepLen == 0) curr->next = NULL;
        }
    }
};

//better solution
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return;
        //a smarter idea could be reversing the second half part of the linkedlist, and merge them together.
        //first find the mid point by two pointers
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL &&fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //the mid point should be slow.
        fast = slow->next;
        slow->next = NULL;
        ListNode *prev = NULL, *curr = NULL;

        if(fast!= NULL){
            prev = NULL;
            curr = fast;
            while(curr != NULL){
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            fast = prev;
        }
        ListNode *stub = new ListNode(0);
        curr = stub;
        ListNode* l1 = head, *l2 = fast;
        while(l1 != NULL && l2!=NULL){
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;
            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        if(l1 != NULL)
            curr->next = l1;
        if(l2 != NULL)
            curr->next = l2;
        head = stub->next;

    }

};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for(int i = 2; i <= 3; i++){
        ListNode *tmp = new ListNode(i);
        cur->next = tmp;
        cur = tmp;
    }
    cur->next = NULL;
    Solution s = Solution();
    s.reorderList(head);
    while(head!=NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for(int i = 2; i <= 3; i++){
        ListNode *tmp = new ListNode(i);
        cur->next = tmp;
        cur = tmp;
    }
    cur->next = NULL;
    Solution s = Solution();
    s.reorderList(head);
    while(head!=NULL){
        cout<<head->val<<endl;
        head = head->next;
    }
}