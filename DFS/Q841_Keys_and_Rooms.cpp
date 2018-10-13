//
// Created by wu061 on 12/10/18.
//

#include "headers.h"

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        vector<uint8_t> reachable(rooms.size(), 0);
        enter(rooms, reachable, 0);
        for (auto val : reachable) cout << val << endl;
        for (auto can_reach : reachable) {
            if (!can_reach) return false;
        }
        return true;
    }

private:
    void enter(vector<vector<int>> &rooms, vector<uint8_t> &reachable, int root) {
        reachable[root] = 1;
        for (int key : rooms[root]) {
            if (!reachable[key]) {
                enter(rooms, reachable, key);
            }
        }
    }
};

int main() {
    vector<vector<int>> rooms = {{1},
                                 {2},
                                 {3},
                                 {}};
    Solution s = Solution();
    cout << s.canVisitAllRooms(rooms);

}