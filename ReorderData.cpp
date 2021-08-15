#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    static bool isOK(string & a, string & b) {
        string aid, bid;
        string arem, brem;

        int ap = a.find(' '), bp = b.find(' ');

        aid = a.substr(0, ap);
        bid = b.substr(0, bp);
        arem = a.substr(ap + 1);
        brem = b.substr(bp + 1);

        if(arem < brem) {
            return true;
        } else if (arem == brem) {
            if (aid <= bid) {
                return true;
            }
            return false;
        } else {
            return false;
        }
    }

    vector<string> reorderLogFiles(vector<string> & logs) {
        vector<string> digit_logs, letter_logs;

        for(auto x : logs) {
            bool space = false, alldigits = true;
            for (int i = 0, len = x.length(); i < len; ++i) {
                if(!alldigits) {
                    break;
                }

                if(!space) {
                    if(x[i] == ' ') {
                        space = true;
                    }
                } else if(x[i] == ' ') {
                    continue;
                } else if(x[i] >= 'a' && x[i] <= 'z') {
                    alldigits = false;
                    break;
                }
            }

            if(alldigits) {
                digit_logs.push_back(x);
            } else {
                letter_logs.push_back(x);
            }
        }

        sort(letter_logs.begin(), letter_logs.end(), isOK);

        for(auto x : digit_logs) {
            letter_logs.push_back(x);
        }

        return letter_logs;
    }
};

int main () {
    vector<string> logs{
        "a1 9 2 3 1",
        "g1 act car",
        "zo4 4 7",
        "ab1 off key dog",
        "a8 act zoo"
    };

    Solution s;

    vector<string> ans = s.reorderLogFiles(logs);

    for(auto x : ans) {
        cout << x << '\n';
    }

    return 0;
}