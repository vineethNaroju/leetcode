#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int> & nums) {
        int n = nums.size();
        vector<int> pos, ans;

        while(nums.size() > 0) {
            if(nums.back() >= 0) {
                pos.push_back(nums.back() * nums.back());
                nums.pop_back();
            } else {
                break;
            }
        }

        for (int i = 0, n = nums.size(); i < n; ++i) {
            nums[i] *= nums[i];
        }

        while(nums.size() > 0 || pos.size() > 0) {
            if(nums.size() == 0) {
                while(pos.size() > 0) {
                    ans.push_back(pos.back());
                    pos.pop_back();
                }
                break;
            }

            if(pos.size() == 0) {
                while(nums.size() > 0) {
                    ans.push_back(nums.back());
                    nums.pop_back();
                }
                break;
            }

            if(pos.back() <= nums.back()) {
                ans.push_back(pos.back());
                pos.pop_back();
            } else {
                ans.push_back(nums.back());
                nums.pop_back();
            }
        }

        return ans;
    }
};

int main() {
    vector<int> arr{-1};
    Solution s;
    vector<int> ans = s.sortedSquares(arr);

    for(auto x : ans) {
        cout << x << ' ';
    }

    cout << '\n';
}