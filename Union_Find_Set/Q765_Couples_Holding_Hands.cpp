//
// Created by wu061 on 1/03/18.
//

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
 * the minumum number of seat changes required to ensure that every couple seats together. This problem can be solved
 * elegantly by constructing a graph.
 * Suppose each two adjacent seats are a couch and we index the coaches. The final target is to ensure that each coach
 * is occupied by a couple. In other words, no one's partner is on a different coach. If we construct a undirected graph
 * where edges exist if the partner of the coach is at a different coach. In this case, our target is to make the graph
 * of n individual components.
 */

class Solution {
public:
    int minSwapsCouples(vector<int> &row) {
        int num_people = row.size(), coach_num = row.size() / 2;
        unordered_map<int, int> person_to_coach;
        for (int j = 0; j < row.size(); j++) person_to_coach[row[j]] = j / 2;
        for (int k = 0; k < coach_num; k++) parent[k] = k;
        for (int i = 0; i < coach_num; i++) {
            if (abs(row[2 * i] - row[2 * i + 1]) == 1) {
                if (row[2 * i] / 2 == row[2 * i + 1] / 2) {
                    continue;
                }
            }

            int neighbor_group1 = (row[2 * i] % 2 == 0) ? (person_to_coach[row[2 * i] + 1]) : (person_to_coach[
                    row[2 * i] - 1]);
            int neighbor_group2 = (row[2 * i + 1] % 2 == 0) ? (person_to_coach[row[2 * i + 1] + 1]) : (person_to_coach[
                    row[2 * i + 1] - 1]);
            cout << "coach " << i << " is connected with " << neighbor_group1 << " and " << neighbor_group2 << endl;
            cout << "BEGIN" << endl;
            for (int p = 0; p < coach_num; p++)
                cout << find(parent[p]) << " ";
            cout << endl;
            unionSet(i, neighbor_group1);
            cout << "MID" << endl;
            for (int p = 0; p < coach_num; p++)
                cout << find(parent[p]) << " ";
            cout << endl;
            cout << "END" << endl;

            unionSet(i, neighbor_group2);
            for (int p = 0; p < coach_num; p++)
                cout << find(parent[p]) << " ";
            cout << endl;
        }
        int total_group_size = 0;

        set<int> group_id;
        for (int i = 0; i < parent.size(); i++) {
            cout << "group[" << i << "]=" << find(parent[i]) << endl;
            group_id.insert(find(parent[i]));
        }

        cout << "total_group_size = " << group_id.size() << endl;

        return coach_num - group_id.size();
    }

private:
    //implement a simple union-find set here, further optimizations can be made to balance the union-find set.
    unordered_map<int, int> parent;

    void unionSet(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent != y_parent) parent[x_parent] = y_parent;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return find(parent[x]);
    }
};

int main() {
    int a[] = {12, 11, 9, 0, 23, 7, 1, 22, 21, 18, 15, 16, 14, 2, 17, 19, 13, 8, 5, 3, 6, 4, 20, 10};
    vector<int> input(a, a + 24);
    Solution s = Solution();
    cout << s.minSwapsCouples(input);

}