#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int solve(string & s, int idx) {
    
    if(idx == 0) {
        return 0;
    }

    if(s[idx] == '(') {
        return 0;
    }

    if(s[idx-1] == '(') {
        // return 2 + solve(s, idx - 2);
        return 2 + dp[idx-2];
    }

    int vlen = dp[idx-1]; // solve(s, idx - 1);
    int vstart = idx - vlen; 
    
    if(vlen > 0 && vstart - 1 >= 0) {
        if(s[vstart-1] == '(') {
            if(vstart - 2 >= 0) {
                return vlen + 2 + dp[vstart-2]; //solve(s, vstart - 2);
            } else {
                return vlen + 2;
            }
        } else {
            return 0;
        }
    }

    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cout.precision(10);

    string s  = "((()))(()(())";

    int N = s.length(), mx = 0;

    dp.assign(N, 0);

    for(int i=0; i<s.length(); ++i) {
        dp[i] = solve(s, i);
        mx = max(mx, dp[i]);
        // cout << dp[i] << '\n';
    }

    return 0;
}