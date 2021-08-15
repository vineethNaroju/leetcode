#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    vector<bool> visit;

    unordered_map<int, vector<vector<int>>> mp;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & adj) {
        n = adj.size();
        ans.clear();
        visit.assign(n, false);
        mp.clear();

        dfs(adj, 0);

        return mp[0];
    }


    void dfs(vector<vector<int>> & adj, int i) {
        
    }
};



int main () {
    vector<vector<int>> adj{
        {1, 2},
        {2, 3},
        {3},
        {}
    };

    Solution s;

    vector<vector<int>> ans = s.allPathsSourceTarget(adj);

    for(auto x : ans) {
        for(auto y : x) {
            cout << y << ' ';
        }
        cout << '\n';
    }

    return 0;
}