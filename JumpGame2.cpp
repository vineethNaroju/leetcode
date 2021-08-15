#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int mxIdx = 0, cnt = 0, nxtIdx = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if(i > mxIdx) {
                return -1;
            }
            
            if(n-1 <= mxIdx) {
                break;
            }

            if(i + nums[i] > nxtIdx) {
                nxtIdx = i + nums[i];
            }

            if(i == mxIdx) {
                ++cnt;
                mxIdx = nxtIdx;
            }

        }

        return cnt;
    }
};

int main() {

    Solution s;

    vector<int> a{2, 3, 1, 1, 4};
    vector<int> b{2, 3, 0, 1, 4};

    cout << s.jump(a) << '\n';
    cout << s.jump(b) << '\n';

    return 0;
}