//
// Created by WuHuijun on 2019-04-07.
//

#include "headers.h"


class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>> s;
        ListNode* p = head;
        unordered_map<int, int> tmp_res;
        vector<int> res;
        int p_idx = 0;
        while (p != NULL) {
            if (s.empty()) {
                s.push({p->val, p_idx++});
                p = p->next;
            } else {
                while (!s.empty() && (p->val > s.top().first)) {
                    tmp_res[s.top().second] = p->val;
                    s.pop();
                }
                s.push({p->val, p_idx++});
                p = p->next;
            }
        }

        while (!s.empty()) {
            tmp_res[s.top().second] = 0;
            s.pop();
        }
        res = vector<int>(tmp_res.size(), 0);
        for (int i = 0; i < tmp_res.size(); ++i) res[i] = tmp_res[i];
        return res;
    }
};

int main() {
    vector<int> input = {2, 7, 4, 3, 5};
    ListNode* head = generateListFromArray(input);
    printList(head);
    Solution s = Solution();
    vector<int> res = s.nextLargerNodes(head);
    for (auto val : res) cout<<val<<endl;
}