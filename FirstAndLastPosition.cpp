#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        int mid;
        vector<int> ans{-1, -1};
        int left = -1, right = -1;

        // left most
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                left = mid;
                hi = mid - 1;
            } else if(nums[mid] < target) {
                lo = mid + 1;
            } else if(target < nums[mid]) {
                hi = mid - 1;
            }
        }

        if(left == -1) {
            return ans;
        }

        ans[0] = left;

        lo = 0, hi = nums.size() - 1;

        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(nums[mid] == target) {
                right = mid;
                lo = mid + 1;
            } else if(nums[mid] < target) {
                lo = mid + 1;
            } else if(target < nums[mid]) {
                hi = mid - 1;
            }
        }

        ans[1] = right;

        return ans;
    }
};

int main() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 7;

    Solution s;

    vector<int> ans = s.searchRange(nums, target);

    cout << ans[0] << ' ' << ans[1] << '\n';

    return 0;
}