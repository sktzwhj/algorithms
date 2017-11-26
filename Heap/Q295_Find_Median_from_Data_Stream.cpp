//
// Created by wuhuijun on 9/27/17.
//

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

//brute-force solution
#include<iostream>
#include<vector>
using namespace std;
#include<priority_queue>


//sliding window solution
class MedianFinder {

    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
public:

// Adds a number into the data structure.
    void addNum(int num) {
        if(left.empty()){
            left.push(num);
            return;
        }
        if(num <= left.top()){
            left.push(num);
            if(left.size()-right.size() > 1){
                right.push(left.top());
                left.pop();
            }
        }
        else{
            right.push(num);
            if(right.size()-left.size() > 1){
                left.push(right.top());
                right.pop();
            }
        }
    }

// Returns the median of current data stream
    double findMedian() {
        if(left.size() == right.size()){
            return (left.top()+right.top())/2.0;
        }
        else if(left.size() > right.size()) return left.top();
        else return right.top();
    }
};

int main()
{
    MedianFinder m = MedianFinder();
    m.addNum(1);


    m.addNum(2);


    cout<<m.findMedian()<<endl;
    m.addNum(3);


    cout<<m.findMedian()<<endl;

}