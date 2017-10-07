//
// Created by wuhuijun on 10/7/17.
//

#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ret = "/";
        int i = 0;
        int start = 0, end = 0;
        string element;
        //skip first several /s
        while(path[i] == '/' && i < path.size())i++;
        while(i < path.size())
        {
            //skip the continous /s
            //cout<<"i:"<<i<<endl;
            while(path[i] == '/')i++;
            start = i;
            while(path[i] != '/' && i < path.size())i++;
            end = i - 1;
            element = path.substr(start, end - start + 1);
            //cout<<element<<endl;
            if(element.size()>0) {
                if (element == "..") {
                    if (s.size() > 0){
                        //cout<<"pop"<<s[s.size()-1]<<endl;
                        s.pop_back();
                    }
                } else if (element == ".")
                    continue;
                else {
                    //cout << "push" << element << endl;
                    s.push_back(element);
                }
            }


        }
        for(int j = 0; j < s.size(); j++)
        {
            if(j>0)
                ret = ret + '/' + s[j];
            else
                ret = ret + s[j];
        }

        return ret;
    }

private:
    vector<string> s;
};

int main()
{
    string input_path = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
    cout<<"input size:"<<input_path.size()<<endl;
    Solution s = Solution();
    cout<<"result"<<s.simplifyPath(input_path);

}