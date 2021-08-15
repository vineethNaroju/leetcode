#include <bits/stdc++.h>
using namespace std;


vector<int> zeros, ones;
int dp[601][101][101];

// 600 * 100 * 100 => 6 * 10^6

int getSubsetSize(int idx, int m, int n) {
    
    //cout << idx << ' ' << m << ' ' << n << '\n';

    if(dp[idx][m][n] != -1) {
        return dp[idx][m][n];
    }

    int temp = -1;

    if(idx == 0) {
        if(zeros[0] <= m && ones[0] <= n) {
            temp = 1;
        } else {
            temp = 0;
        }
    } else if(zeros[idx] <= m && ones[idx] <= n) {
        temp = max( 
            1 + getSubsetSize(idx-1, m - zeros[idx], n - ones[idx]) ,
            getSubsetSize(idx-1, m, n)
        );
    } else {
        temp = getSubsetSize(idx-1, m, n);
    }

    dp[idx][m][n] = temp;

    return temp;
}


int solve(vector<string> & strs, int m, int n) {

    int N = strs.size();

    zeros.assign(N, 0);
    ones.assign(N, 0);

    for(int i=0; i<N; ++i) {
        for(int j=0, slen = strs[i].length(); j < slen; ++j) {
            if(strs[i][j] == '0') ++zeros[i];
            else ++ones[i];
        }
    }

    memset(dp, -1, sizeof(dp));

    return getSubsetSize(N-1, m, n);
}


int main () {
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    vector<string> strs { "10", "0001", "111001", "1", "0"};
    int m = 5, n = 3;

    cout << solve(strs, m, n) << '\n';

    return 0;
}


