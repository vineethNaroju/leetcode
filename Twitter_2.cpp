#include <bits/stdc++.h>
using namespace std;

// storing my followers
// publishing my tweets -> O(tweets * followers)
// old tweets are not removed

class Twitter {
private:
    map<int, list<pair<int, int>>> userTweetsDLL;
    map<int, set<int>> usersFollowed;
    int time = 0, maxRecentTweets = 10;

public:
    Twitter() {

    }

    struct myCompare {
        bool operator() (list<pair<int,int>> :: iterator itrA, list<pair<int,int>> :: iterator itrB) {
            return (*itrA).first - (*itrB).first;
        }
    };

    void postTweet(int userId, int tweetId) {

        ++time;

        auto itr = userTweetsDLL.find(userId);

        if(itr == userTweetsDLL.end()) {
            follow(userId, userId);
            userTweetsDLL.insert({userId, list<pair<int, int>>{{time, tweetId}}});
        } else {
            itr->second.push_front({time, tweetId});
        }
    }

    // top 10 recent tweets posted by user / users followed by user
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        auto itr = usersFollowed.find(userId);

        if(itr == usersFollowed.end()) {
            return ans;
        }

        int recentTweetCount = 0;

        priority_queue<list<pair<int, int>> :: iterator, vector<list<pair<int,int>> :: iterator>,  myCompare> pq;

        for(auto x : itr->second) {
            auto itr2 = userTweetsDLL.find(x);

            if(itr2 != userTweetsDLL.end() && itr2->second.size() > 0) {
                pq.push(itr2->second.begin());
            }
        }

        while(!pq.empty() && recentTweetCount < maxRecentTweets) {
            auto topItr = pq.top();
            pq.pop();

            ans.push_back((*topItr).second);

            ++topItr;

            
        }

    }

    // userId follows followUserId
    void follow(int userId, int followUserId) {
        auto itr = usersFollowed.find(userId);

        if(itr == usersFollowed.end()) {
            usersFollowed.insert({userId, set<int>{userId}});
        } else if (userId != followUserId) {
            itr->second.insert(followUserId);
        }
    }

    // userId should unfollow unfollowUserId
    void unfollow(int userId, int unfollowUserId) {
        if(userId == unfollowUserId) {
            return;
        }

        auto itr = usersFollowed.find(userId);

        if(itr != usersFollowed.end()) {
            itr->second.erase(unfollowUserId);
        }
    }
};

void printVec(vector<int>  & vec) {
    for(auto x : vec) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    Twitter tw;
    vector<int> vec;

    tw.postTweet(1, 5);
    vec = tw.getNewsFeed(1);
    printVec(vec);
    tw.follow(1, 2);
    tw.postTweet(2, 6);
    vec = tw.getNewsFeed(1);
    tw.unfollow(1, 2);
    vec = tw.getNewsFeed(1);

    return 0;
}