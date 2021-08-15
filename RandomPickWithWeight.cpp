#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, mi = INT_MAX, mx = INT_MIN;
    vector<pair<int,int>> csum;

    Solution(vector<int> & w) {
        srand(0);
        csum.clear();
        csum.push_back({w[0], w[0]});
        n = w.size();
        for (int i = 1; i < n; ++i) {
            csum.push_back({w[i], csum.back().second + w[i]});
        }
    }

    int pickIndex() {
        int idx = rand() % csum.back().second;

        mi = min(mi, idx);
        mx = max(mx, idx);

        return bs(idx);
    }

    int bs(int val) {
        int lo = 0, hi = n - 1;
        int mid, res = -1;

        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;

            if(val < csum[mid].second) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if(res != -1) {
            return csum[res].first;
        }

        return res;
    }
};

int main() {
    map<int, int> mp;
    vector<int> w{1, 3, 5};
    Solution s(w);

    for (int i = 0; i < 10000; ++i) {
        mp[s.pickIndex()]++;
    }

    for(auto x : mp) {
        cout << x.first << " freq: "<< x.second << '\n';
    }

    cout << s.mi << ' ' << s.mx << '\n';

    return 0;
}