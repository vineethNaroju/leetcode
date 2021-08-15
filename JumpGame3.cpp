#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visit(n, false);

        queue<int> q;

        q.push(start);

        while(q.size() > 0) {
            int idx = q.front();
            q.pop();

            visit[idx] = true;

            if(arr[idx] == 0) {
                return true;
            }

            if(idx + arr[idx] < n && !visit[idx + arr[idx]]) {
                q.push(idx + arr[idx]);
            }

            if(idx - arr[idx] >= 0 && !visit[idx - arr[idx]]) {
                q.push(idx - arr[idx]);
            }

        }

        return false;
    }
};

int main() {
    return 0;
}