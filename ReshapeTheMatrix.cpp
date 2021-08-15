#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> matrixReshape(vector<vector<int>> & mat, int r, int c) {
        int m = mat[0].size();
        int n = mat.size();
        // n x m => r x c

        if(n * m != r*c) {
            return mat;
        }

        vector<vector<int>> res(r, vector<int>(c, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int ri = (m * i + j) / c;
                int cj = (m * i + j) % c;

                res[ri][cj] = mat[i][j];
            }
        }

        return res;
    }
};

int main() {
    return 0;
}