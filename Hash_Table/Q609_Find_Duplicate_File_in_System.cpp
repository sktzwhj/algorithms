//
// Created by wu061 on 31/05/18.
//

#include <string>
#include <vector>
#include <iostream>
#include <regex>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string> &paths) {
        unordered_map<string, vector<string>> fp_table;
        vector<vector<string>> res;
        regex dir_format("root[/\\S]{0,}");
        regex file_format("\\w+.txt\\(\\w+\\)");
        smatch dir_name, file_name;
        for (string path:paths) {
            regex_search(path, dir_name, dir_format);
            string dirname = dir_name.str();
            while (regex_search(path, file_name, file_format)) {
                string filename = file_name[0].str();
                string::size_type pos = filename.find("(");
                string file_hash = filename.substr(pos + 1, filename.size() - pos - 2);
                filename = filename.substr(0, pos);
                path = file_name.suffix();
                string tmp = dirname + "/" + filename;
                fp_table[file_hash].emplace_back(tmp);
            }
        }
        for (auto kv:fp_table) {
            if (kv.second.size() > 1) res.emplace_back(kv.second);
        }
        return res;
    }
};

int main() {
    vector<string> input = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
                            "root 4.txt(efgh)"};
    Solution s = Solution();
    vector<vector<string>> ret = s.findDuplicate(input);
    for (auto vec:ret) {
        for (auto file:vec) {
            cout << file << endl;
        }
        cout << endl;
    }
}