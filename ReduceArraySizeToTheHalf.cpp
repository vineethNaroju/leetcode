#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int> & arr) {
        int n = arr.size();
        vector<int> uniq, cnt(100001, 0);

        for (int i = 0; i < n; ++i) {
            if(cnt[arr[i]] == 0) {
                uniq.push_back(arr[i]);
            }

            cnt[arr[i]]++;
        }

        int m = uniq.size();

        vector<int> pref;

        for (int i = 0; i<m; ++i) {
            pref.push_back(cnt[uniq[i]]);
        }

        sort(pref.begin(), pref.end(), greater<int>());

        int curr = 0;

        for (int i = 0; i < m; ++i) {
            if(curr <= n/2) {
                return i;
            }

            curr += pref[i];
        }

        return -1;
    }
};

int main() {
    Solution s;

    vector<int> a{3, 3, 3, 3, 5, 5, 5, 2, 2, 7};

    cout << s.minSetSize(a);

    return 0;
}