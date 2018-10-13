//
// Created by wu061 on 13/10/18.
//

#include "headers.h"

#define DEBUG true

class Solution {
public:
    //this is basicly adding commas to split the string
    vector<string> restoreIpAddresses(string s) {
        vector<string> valid_addr;
        if (s.size() < 4 || s.size() > 12) return valid_addr;
        vector<int> comma_pos;
        comma_pos.push_back(0);
        string generated = "";
        dfs(valid_addr, s, 0, 1, generated, 0);
        //deduplication
        sort(valid_addr.begin(), valid_addr.end());
        vector<string>::iterator end_unique = unique(valid_addr.begin(), valid_addr.end());
        valid_addr.erase(end_unique, valid_addr.end());
        return valid_addr;
    }

private:
    void dfs(vector<string> &valid_addr, string &s, int last_pos, int pos, string generated_addr, int generated_len) {
        if (generated_len == 4) {
            if (generated_addr.size() == s.size() + 3)
                valid_addr.push_back(generated_addr);
        }
        if (generated_len > 4 || pos > s.size() || last_pos > s.size() - 1) return;

        if (generated_len < 4) {
            //do not split
            dfs(valid_addr, s, last_pos, pos + 1, generated_addr, generated_len);
            //if split
            string sub_addr_str = s.substr(last_pos, ((generated_len == 3) ? s.size() : pos) - last_pos);
            if (sub_addr_str.substr(0, 1) == "0" && sub_addr_str.size() > 1) return;
            long sub_addr = stol(sub_addr_str);
            if (sub_addr > 255) return;
            dfs(valid_addr, s, pos, pos + 1, generated_addr + ((generated_len == 0) ? "" : ".") + sub_addr_str,
                generated_len + 1);
        }
    }
};

int main() {
    string input = "010010";
    Solution s = Solution();
    vector<string> res = s.restoreIpAddresses(input);
    for (auto val : res) cout << val << endl;
}