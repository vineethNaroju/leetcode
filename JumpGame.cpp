#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxIdx = 0, n = nums.size();

        for (int i = 0; i<n; ++i) {
            if(i <= mxIdx) {
                mxIdx = max(mxIdx, i + nums[i]);
                if(i==n-1) {
                    return true;
                }
            } else {
                return false;
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums{2, 3, 1, 1, 4};

    Solution s;

    cout << s.canJump(nums) << '\n';

    return 0;
}