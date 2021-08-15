#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
private:
    map<pair<string, string>, pair<int, double>> avgMap;
    map<int, pair<string, int>> custMap;

    void insertIntoAvgMap(string startStatioName, string endStatioName, int duration) {
        pair<string, string> stationPair = {startStatioName, endStatioName};

        auto itr = avgMap.find(stationPair);

        if(itr == avgMap.end()) {
            avgMap.insert({stationPair, {1, duration}});
        } else {
            double oldAvg = itr->second.second;
            double oldFreq = itr->second.first;
            double newFreq = oldFreq + 1;
            double newAvg = oldAvg * (oldFreq / newFreq) + (duration / newFreq);

            itr->second.first = newFreq;
            itr->second.second = newAvg;
        }
    }

public:
    UndergroundSystem() {
        
    }

    void checkIn(int customerId, string stationName, int time) {
        custMap[customerId] = {stationName, time};
    }

    void checkOut(int customerId, string stationName, int time) {
        auto itr = custMap.find(customerId);

        insertIntoAvgMap(itr->second.first, stationName, time - itr->second.second);

        custMap.erase(itr);
    }

    double getAverageTime(string startStationName, string endStationName) {
        pair<string, string> stationPair = {startStationName, endStationName};

        auto itr = avgMap.find(stationPair);

        if(itr == avgMap.end()) {
            return 0;
        }

        return itr->second.second;
    }
};

int main() {
    UndergroundSystem us;


}