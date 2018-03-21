//
// Created by wuhuijun on 3/21/18.
//

#include <vector>
#include <iostream>

//very simple to come up with a dfs solution, but it gets TLE. Obviously we introduce massive redundant computations.
using namespace std;
class Solution {
public:
    int removeBoxes(vector<int> &boxes) {
        vector<pair<int, int>> boxes_compress;
        int last_val = boxes[0], last_val_cnt = 1;
        for (int i = 1; i <= boxes.size(); i++) {
            if (i != boxes.size() && boxes[i] == last_val) last_val_cnt++;
            else {
                boxes_compress.push_back(make_pair(last_val, last_val_cnt));
                last_val = boxes[i];
                last_val_cnt = 1;
            }
        }
        int total_point = 0;
        int max_points = (boxes_compress.size())?boxes_compress[0].second*boxes_compress[0].second:0;
        if(boxes_compress.size() > 1) removeBoxHelper(boxes_compress, total_point, max_points);
        return max_points;
    }

private:
    void removeBoxHelper(vector<pair<int, int>>& box_compress, int& total_points, int& max_points) {
        if (box_compress.size() == 0) {
            if (total_points > max_points)
                max_points = total_points;
            return;
        }
        for (int i = 0; i < box_compress.size(); i++) {
            if (box_compress[i].second != 0) {
                //cout<<"total_points = "<<total_points<<" + "<<box_compress[i].second * box_compress[i].second<<endl;
                int gain_point = box_compress[i].second * box_compress[i].second;
                total_points += gain_point;
                //backup the status
                if ((i > 0) && (i < box_compress.size() - 1) &&
                    (box_compress[i - 1].first == box_compress[i + 1].first)) {
                    pair<int, int> box_compress_i = box_compress[i], box_compress_ir = box_compress[i + 1];
                    box_compress[i - 1].second += box_compress[i + 1].second;
                    box_compress.erase(box_compress.begin() + i, box_compress.begin() + i + 2);
                    removeBoxHelper(box_compress, total_points, max_points);
                    //recover the status
                    box_compress.insert(box_compress.begin() + i, box_compress_i);
                    box_compress.insert(box_compress.begin() + i + 1, box_compress_ir);
                    box_compress[i - 1].second -= box_compress_ir.second;
                } else {
                    pair<int, int> box_compress_bk = box_compress[i];
                    box_compress.erase(box_compress.begin() + i);
                    removeBoxHelper(box_compress, total_points, max_points);
                    box_compress.insert(box_compress.begin() + i, box_compress_bk);

                }
                total_points -= gain_point;
            }
        }
    }
};

//a better dp solution to remove the redundant computations.
class Solution {
public:
    int mem[100][100][100]; // initialized to 0, mem[left][right][k] means value from boxes[left]~boxes[right] followed by
    // k same color boxes. Follow does not mean strictly consecutive boxes, for example, [1, 3, 2, 3, 4], 3 can be
    // followed by the other 3 because we can remove 2 first

    int removeBoxes(vector<int>& boxes) {
        return DFS(boxes,0,boxes.size()-1,0);
    }

    int DFS(vector<int>& boxes, int l,int r,int k){
        if (l>r) return 0;
        if (mem[l][r][k]) return mem[l][r][k]; // if we have calculated this DFS result, return it

        mem[l][r][k] = DFS(boxes,l,r-1,0) + (k+1)*(k+1); // box[l][r] result is box[l][r-1]+(k+1)^2
        for (int i=l; i<r; i++) // go through each box from left
            if (boxes[i]==boxes[r]) // check for same color box as boxes[r]
                mem[l][r][k] = max(mem[l][r][k], DFS(boxes,l,i,k+1) + DFS(boxes,i+1,r-1,0)); // if we found same color box,
        // then we have a chance to get a higher value by group boxes[l]~boxes[i] and boxes[r] together, plus the
        // value from boxes[i+1]~boxes[r-1]
        return mem[l][r][k];
    }
};

int main() {
    //int a[] = {1,3,2,2,2,3,4,3,1};
    int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    Solution s = Solution();
    vector<int> input(a, a + 9);
    cout << s.removeBoxes(input);
}