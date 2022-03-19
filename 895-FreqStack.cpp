#include <bits/stdc++.h>
using namespace std;

class FreqStack {
    map<int,int> valMap; // val -> freq
    map<int,vector<int>> freqMap; // freq -> vector of val
    int maxFreq = 0;

public:
    FreqStack() {}

    void push(int val) {
        auto a = valMap.find(val);
        int freq = -1;

        if(a == valMap.end()) {
            valMap.insert({val, 1});
            freq = 1;
        } else {
            a->second++;
            freq = a->second;
        }

        maxFreq = max(freq, maxFreq);

        freqMap[freq].push_back(val);
    }

    int pop() {
        int res = freqMap[maxFreq].back();
        freqMap[maxFreq].pop_back();

        if(freqMap[maxFreq].empty()) {
            maxFreq--;
        }

        valMap[res]--;

        if(valMap[res] == 0) {
            valMap.erase(res);
        }

        return res;
    }
};



int main() {

}