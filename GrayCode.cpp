#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res {0};

        while(n-- > 0) {
            int sz = res.size();

            for (int i = 0; i < sz; ++i) {
                res[i] = res[i] << 1;
                cout << res[i] << ' ';
            }

            for (int i = sz - 1; i >= 0; --i) {
                res.push_back(res[i] | 1);
                cout << res.back() << ' ';
            }

            cout << '\n';
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> res = s.grayCode(3);

    return 0;
}