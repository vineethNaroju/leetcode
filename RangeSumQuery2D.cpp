#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> presum;
    int n, m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        presum.assign(n + 1, vector<int>(m + 1, 0));
        
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                presum[i+1][j+1] = matrix[i][j] + presum[i][j+1] + presum[i+1][j] - presum[i][j];
                cout << i << ' ' << j << ' ' << presum[i + 1][j + 1];
            }
        }

        cout << "----------------\n";
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return presum[row2+1][col2+1] - presum[row1][col2+1] - presum[row2+1][col1] + presum[row1][col1];
    }
};

int main() {
    vector<vector<int>> mat{
        {-4, -5}
    };

    int n = 1, m = 2;

    NumMatrix nm(mat);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int p = i; p < n; ++p) {
                for (int q = j; q < m; ++q) {
                    cout << i << ' ' << j << "|" << p << ' ' << q << " = " << nm.sumRegion(i, j, p, q) << '\n';
                }
            }
        }
    }
}