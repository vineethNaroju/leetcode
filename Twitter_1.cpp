#include <bits/stdc++.h>
using namespace std;

// storing my followers
// publishing my tweets -> O(tweets * followers)
// old tweets are not removed

class Twitter {
private:
    map<int, deque<int>> feedQueueMap;
    map<int, set<int>> myFollowerSetMap;

public:
    Twitter() {

    }

    void postTweet(int userId, int tweetId) {

        auto itr0 = feedQueueMap.find(userId);

        if(itr0 == feedQueueMap.end()) {
            feedQueueMap.insert({userId, deque<int>{tweetId}});
        } else {
            itr0->second.push_front(tweetId);
        }

        auto itr1 = myFollowerSetMap.find(userId);

        if(itr1 != myFollowerSetMap.end()) {
            for(auto fs : itr1->second) {
                feedQueueMap[fs].push_front(tweetId);
            }
        }
    }

    // top 10 recent tweets posted by user / users followed by user
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        auto itr = feedQueueMap.find(userId);

        if(itr == feedQueueMap.end()) {
            return ans;
        }

        if(itr->second.size() > 100) {
            itr->second.resize(10);
        }

        int minLen = min(10, (int)itr->second.size());

        for(int i=0; i<minLen; ++i) {
            ans.push_back(itr->second[i]);
        }

        return ans;
    }

    // userId follows followUserId
    void follow(int userId, int followUserId) {
        auto itr = myFollowerSetMap.find(followUserId);

        if(itr == myFollowerSetMap.end()) {
            myFollowerSetMap.insert({followUserId, set<int>{userId}});
        } else {
            itr->second.insert(userId);
        }
    }

    // userId should unfollow unfollowUserId
    void unfollow(int userId, int unfollowUserId) {
        auto itr = myFollowerSetMap.find(unfollowUserId);

        if(itr != myFollowerSetMap.end()) {
            itr->second.erase(userId);
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