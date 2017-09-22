//
// Created by wu061 on 22/09/17.
//

#include <set>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        set<ListNode*> seenPtr;
        while(head!=NULL)
        {
            if(seenPtr.find(head)!=seenPtr.end())
                return 1;
            else
                seenPtr.insert(head);
            head = head->next;
        }
        return 0;
    }
};