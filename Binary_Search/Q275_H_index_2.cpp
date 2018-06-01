//
// Created by wu061 on 1/06/18.
//

#include <vector>
#include <iostream>

using namespace std;

//binary search, typical

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int start = 0, end = n - 1;
        int mid;
        while (start <= end){
            mid = start + (end - start)/ 2;
            if (mid < citations[n - mid - 1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        //what to return? only start is valid to return. mid and end are the reasons for the while condition violation.
        return start;
    }
};

int main() {
    vector<int> citations = {0, 1, 3, 5, 6};
    Solution s = Solution();
    cout << s.hIndex(citations) << endl;
}