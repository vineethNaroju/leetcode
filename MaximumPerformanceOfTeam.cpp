#include <bits/stdc++.h>
using namespace std;

bool isok(pair<int,int> &a, pair<int,int> &b) {
    if(a.first > b.first) {
        return true;
    } else if (a.first == b.first) {
        if(a.second >= b.second) {
            return true;
        }
        return false;
    }
    return false;
}

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> a;

        for (int i = 0; i < n; ++i) {
            a.push_back({efficiency[i], speed[i]});
        }

        sort(a.begin(), a.end(), isok);

        for(auto &x : a) {
            cout << x.first << ' ' << x.second << '\n';
        }

        int minEff, speedSum = 0, res = INT_MIN;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < n; ++i) {
            minEff = a[i].first;

            speedSum += a[i].second;

            minHeap.push(a[i].second);

            while(minHeap.size() > k) {
                speedSum -= minHeap.top();
                minHeap.pop();
            }

            res = max(res, minEff * speedSum);
        }

        return res;
    }
};

int main() {
    Solution s;

    int n = 6, k = 3;
    vector<int> spe{2, 10, 3, 1, 5, 8};
    vector<int> eff{5, 4, 3, 9, 7, 2};

    cout << s.maxPerformance(n, spe, eff, k) << '\n';

    return 0;
}