#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, 0);
        res[0] = nums[0];
        deque<int> idx;

        idx.push_back(0);

        for (int i = 1; i < n; ++i) {
            while(!idx.empty() && idx.front() < i - k) {
                idx.pop_front();
            }

            if(idx.empty()) {
                res[i] = INT_MIN;
                continue;
            }

            res[i] = nums[i] + res[idx.front()];

            while(!idx.empty() && res[idx.back()] <= res[i]) {
                idx.pop_back();
            }

            idx.push_back(i);
        }

        return res[n - 1];
    }
};

int main() {
    return 0;
}