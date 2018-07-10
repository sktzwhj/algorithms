#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smallest = INT_MAX, largest = INT_MAX;
        for(auto x : nums) {
            if (x  <= smallest) smallest = x;
            else if (x <= largest) largest = x;
            else return true;
        }
        return false;
    }
};

int main() {
    vector<int> input = {2, 1, 5, 0, 3};
    Solution s = Solution();
    cout<<s.increasingTriplet(input)<<endl;
}
