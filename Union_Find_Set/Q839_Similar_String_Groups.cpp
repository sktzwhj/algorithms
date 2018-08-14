//
// Created by wuhuijun on 8/14/18.
//

#include "headers.h"

/*
 * further optimizations can track the size of union-find set rather than using a set to count.
 */

class Solution {
public:
    int numSimilarGroups(vector<string> &A) {
        build(A.size());
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (find(i) != find(j) && similar(A[i], A[j])) {
#ifdef DEBUG
                    cout<<endl;
                    cout << "before union" << endl;
                    print_parent();
#endif
                    set_union(i, j);
#ifdef DEBUG
                    cout << "after union" << endl;
                    print_parent();
#endif
                }
            }
        }
        set<int> res;
        for (int i = 0; i < A.size(); ++i) {
            res.insert(find(i));
        }
        return res.size();

    }

private:
    vector<int> parent;

    void build(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int id) {
        return (id == parent[id]) ? id : find(parent[id]);
    }

    void set_union(int x, int y) {
        if (find(x) == find(y)) return;
        int x_parent = find(x);
        //note that we need to set parent[find(y)] rather than parent[y] for consistency
        parent[find(y)] = x_parent;
    }

    bool similar(string a, string b) {
        int non_equal = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] != b[i]) ++non_equal;
            if (non_equal > 2) return false;
        }
        return true;
    }

    void print_parent() {
        for (auto val : parent) cout << val << " ";
        cout << endl;
    }
};

int main() {
    vector<string> input = {"zkhnmefhyr", "ykznfhehmr", "mkhnyefrzh", "zkhnyefrmh", "zkmnhefhyr", "ykznhfehmr",
                            "zkynhfehmr", "mkhnhefrzy", "zkhnmefryh", "zkmnhfehyr"};
    Solution s = Solution();
    cout << s.numSimilarGroups(input);
}