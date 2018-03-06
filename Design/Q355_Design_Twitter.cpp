//
// Created by wu061 on 6/03/18.
//

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

class Twitter {
public:
    struct tweet {
        int time;
        int tweet_id;
    };

    struct tweet_compare {
        bool operator()(tweet a, tweet b) {
            return a.time < b.time;
        }
    };


    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow_table[userId][userId] = 1;

        if (tweets_for_users.count(userId) == 0) tweets_for_users[userId] = vector<tweet>();
        tweet tmp = {global_time++, tweetId};
        tweets_for_users[userId].push_back(tmp);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<tweet, vector<tweet>, tweet_compare> tmpQ;
        for (auto e: follow_table[userId]) {
            //cout<<"user:"<<user<<endl;
            int user = e.first;
            int tweet_size = tweets_for_users[user].size();
            //cout<<tweet_size<<endl;
            for (int i = 0; i < min(10, tweet_size); i++) {
                //cout<<"tweets:"<<tweets_for_users[user][tweets_for_users[user].size() - i - 1].tweet_id<<endl;
                tmpQ.push(tweets_for_users[user][tweets_for_users[user].size() - i - 1]);
            }
        }
        //cout<<"tmpQ size:"<< min(10, (int)tmpQ.size())<<endl;
        vector<int> ret;

        int qsize = (int) tmpQ.size();
        for (int j = 0; j < min(10, qsize); j++) {
            //cout<<"j="<<j<<endl;
            //cout<<"ret"<<tmpQ.top().tweet_id<<endl;
            ret.push_back(tmpQ.top().tweet_id);
            tmpQ.pop();
        }
        //cout<<"ret size:"<<ret.size()<<endl;
        return ret;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followeeId != followerId) follow_table[followerId][followeeId] = 1;
        //cout<<"follow_table["<<followerId<<"]:"<<endl;
        //for(auto e:follow_table[followerId]) cout<<e<<endl;
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followeeId == followerId) return;
        follow_table[followerId].erase(followeeId);

    }

private:
    unordered_map<int, vector<tweet>> tweets_for_users;
    unordered_map<int, unordered_map<int, int>> follow_table;
    int global_time = 0;
};

int main() {
    Twitter t = Twitter();
    vector<int> tmp_ret;
    t.postTweet(1, 5);
    t.postTweet(1, 3);
    tmp_ret = t.getNewsFeed(1);
    for (auto e:tmp_ret) cout << e << endl;
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */