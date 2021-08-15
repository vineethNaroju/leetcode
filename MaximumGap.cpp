#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int mi = INT_MAX;
        int mx = INT_MIN;
        int n = nums.size();

        for (int i = 0; i<n; ++i) {
            if(nums[i] < mi) {
                mi = nums[i];
            }

            if(nums[i] > mx) {
                mx = nums[i];
            }
        }

        
    }
};

int main() {
    return 0;
}