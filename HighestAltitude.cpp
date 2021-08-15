#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int> & gain) {
        int res = 0, curr = 0;
        int n = gain.size();

        for (int i = 0; i < n; ++i) {
            curr += gain[i];

            res = max(res, curr);
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> a{0, -10, 10, 100};

    cout << s.largestAltitude(a) << '\n';

    return 0;
}