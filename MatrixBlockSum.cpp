#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> psum, mt;
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        mt = mat;
        
        makeSum();

        // return psum;

        int m = mt.size();
        int n = mt[0].size();

        
        vector<vector<int>> res (m, vector<int>(n, 0));
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int a = max(0, i - k);
                int b = max(0, j - k);
                int x = min(m - 1, i + k);
                int y = min(n - 1, j + k);

                //cout << i << " " << j << " = ";
                //cout << "[" << a << ":" << b << "]->[" << x << ":" << y << "]\n";

                res[i][j] = getSum(a, b, x, y);
            }
        }
        
        return res;
        
    }
    
    void makeSum() {
        int m = mt.size(), n = mt[0].size();
        
        psum.assign(m, vector<int>(n, 0));
        
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int temp = mt[i][j];
                
                if(i-1 >= 0 ) {
                    temp += psum[i-1][j];
                }
                if(j-1 >= 0) {
                    temp += psum[i][j-1];
                }
                if(i-1 >= 0 && j-1 >= 0) {
                    temp -= psum[i-1][j-1];
                }
                
                psum[i][j] = temp;
            }
        }
    }
    
    
    int getSum(int a, int b, int x, int y) {
        int temp = psum[x][y];

        if(b-1 >= 0) {
            temp -= psum[x][b - 1];
        }

        if(a-1 >= 0) {
            temp -= psum[a - 1][y];
        }

        if(a-1 >= 0 && b-1 >= 0) {
            temp += psum[a - 1][b - 1];
        }

        return temp;
    }
};

int main() {
    vector<vector<int>> a{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution s;

    vector<vector<int>> res = s.matrixBlockSum(a, 1);

    for(auto x : res) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}