#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelPermutation(int n) {
        const int md = 1e9 + 7;
        vector<char> ls{'a', 'e', 'i', 'o', 'u'};
//                       0    1    2    3    4
        vector<vector<int>> prevs{
            {1, 2, 4},
            {0, 2},
            {1, 3},
            {2},
            {2, 3}
        };

        vector<vector<int>> cnt(5, vector<int>(n, 0));

        for (int i = 0; i < 5; ++i) {
            cnt[i][0] = 1;
        }

        int res = 0;

        for (int j = 1; j < n; ++j) {
            // cout << "column:" << j << '\n';
            for (int i = 0; i < 5; ++i) {
                for(int prevId : prevs[i]) {
                    cnt[i][j] = (cnt[i][j] + cnt[prevId][j - 1]) % md ;
                }

                // cout << "row:" << i << " value:" << cnt[i][j] << '\n';
            }
        }

        for (int i = 0; i < 5; ++i) {
            res = (res + cnt[i][n - 1]) % md;
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.countVowelPermutation(2);
    return 0;
}