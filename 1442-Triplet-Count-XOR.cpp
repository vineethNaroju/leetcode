#include <bits/stdc++.h>
using namespace std;

// 0..i...j....k......
// b = xor(j,k)
// xor(0, j-1) ^ b => x and i < j
// if x is present in map, then x is one of xor(0, i)
class Solution {
public:
    vector<int> pxor;

    int countTriplets(vector<int> & arr) {
        int n = arr.size();

        pxor.assign(n, 0);

        pxor[0] = arr[0];

        for (int i = 1; i<n; ++i) {
            pxor[i] = pxor[i - 1] ^ arr[i];
        }

        int cnt = 0;
        map<int, vector<int>> mp;
        map<int, vector<int>>::iterator itr;

        for (int j = 0; j < n; ++j) {

            for (int k = j + 1; k < n && j > 0; ++k) {
                int b = getXor(j, k);
                int p = getXor(0, j - 1) ^ b; // ......p
                itr = mp.find(p);

                cout << "j:" << j << " k:" << k << " j2k-xor:" << b << '\n';

                if(itr != mp.end()) {
                    cout << "found possible i-values:\n";
                    cnt += itr->second.size();
                    for(auto x : itr->second) {
                        cout << "i:" << x << " i2(j-1)-xor:" << getXor(x, j) << '\n';
                    }                    
                }
            }

            int pj = getXor(0, j);

            itr = mp.find(pj);

            if(itr == mp.end()) {
                mp.insert({pj, vector<int>{j}});
            } else {
                itr->second.push_back(j);
            }
        }

        return cnt;
    }

    int getXor(int a, int b) {
        int temp = pxor[b];

        if(a-1 >= 0) {
            temp = temp ^ pxor[a - 1];
        }

        return temp;
    }
};

int main() {
    Solution s;
    vector<int> a{2, 3, 1, 6, 7};
    cout << s.countTriplets(a) << '\n';
    return 0;
}