#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> adj{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    vector<vector<int>> maxDist;

    int n, m;

    int longestIncreasingPath(vector<vector<int>> &matrix){
        int res = 1;

        n = matrix.size();
        m = matrix[0].size();

        maxDist.assign(n, vector<int>(m, -1));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = max(res, dfs(matrix, i, j));
            }
        }

        return res;
    }

    bool isValid(int i, int j) {
        if(i >= 0 && i < n && j >=0 && j < m) {
            return true;
        }
        return false;
    }

    int dfs(vector<vector<int>> & matrix, int i, int j) {
        if(maxDist[i][j] >= 0) {
            return maxDist[i][j];
        }

        int temp = 0, ni, nj;

        for(auto x : adj) {
            ni = i + x.first;
            nj = j + x.second;

            if(!isValid(ni, nj)) {
                continue;
            }

            if(matrix[ni][nj] > matrix[i][j]) {
                temp = max(temp, dfs(matrix, ni, nj));
            }
        }

        maxDist[i][j] = 1 + temp;

        return maxDist[i][j];
    }
};

int main() {
    vector<vector<int>> m{
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    Solution s;

    cout << s.longestIncreasingPath(m) << '\n';

    return 0;
}
