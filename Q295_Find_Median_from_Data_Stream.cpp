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

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void printVec()
    {
        for(int i = 0; i < stream.size(); i++)
            cout<<stream[i]<<" "<<endl;
    }

    void addNum(int num) {
        if (stream.size()==0)
        {
            stream.push_back(num);
            return;
        }

        else
        {
            for(vector<int>::iterator it = stream.begin(); it != stream.end(); it++)
            {
                if(*it < num)
                    continue;
                else
                {
                    stream.insert(it,num);
                    return;
                }

            }
        }
        stream.push_back(num);

    }

    double findMedian() {
        int streamLen = stream.size();
        double median;
        if(streamLen%2==0)
            median = ((double)stream[streamLen/2 - 1] + (double)stream[streamLen/2])/2;
        else
            median = (double)stream[(streamLen-1)/2];
        return median;
    }
private:
    vector<int> stream;
};

//sliding window solution

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void printQ()
    {
        cout<<"ideq size is "<<ideq.size()<<endl;
        cout<<"ideq[0]:"<<ideq[0]<<" ideq[1]:"<<ideq[1]<<endl;
    }

    void addNum(int num) {
        streamLen++;
        if(ideq.size() < 2)
        {
            median_index = 0;
            if(ideq.empty())
                ideq.push_back(num);
            else if(num > ideq[0])
                ideq.push_back(num);
            else
                ideq.push_front(num);
        }
        else
        {
            if(num >= ideq[1] )
            {
                if(median_index == 1)
                {
                    ideq.push_back(num);
                    ideq.pop_front();

                    if(streamLen%2==1)
                        median_index = 1;
                }
                else
                    median_index = 1;

            }
            else if(num <= ideq[0])
            {
                if(median_index==0)
                {
                    ideq.push_front(num);
                    ideq.pop_back();

                    if(streamLen%2==1)
                        median_index = 0;
                }
                else
                    median_index = 0;


            }
            else
            {
                if(streamLen%2==0){
                    if(median_index == 0)
                    {
                        ideq.pop_back();
                        ideq.push_back(num);
                    }
                    else
                    {
                        ideq.pop_front();
                        ideq.push_front(num);
                    }

                }
                else
                {
                    ideq.pop_front();
                    ideq.push_front(num);
                    median_index = 0;
                }

            }

        }
    }

    double findMedian() {
        if(streamLen%2==0)
            return ((double)ideq[0]+(double)ideq[1])/2;
        else
            return (double)ideq[median_index];

    }
private:
    deque<int> ideq;
    int streamLen = 0;
    int median_index;
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