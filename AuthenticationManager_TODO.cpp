#include <bits/stdc++.h>
using namespace std;

class AuthenticationManager {
private:
    int timeToLive;
    unordered_map<string, int> tokenExpiryTimeMap;
    multiset<int> expiryTimeSet;

public:
    AuthenticationManager(int _timeToLive) {
        timeToLive = _timeToLive;
    }

    void generate(string tokenId, int currentTime) {
        auto itr = tokenExpiryTimeMap.find(tokenId);

        if(itr != tokenExpiryTimeMap.end()) {
            expiryTimeSet.erase(itr->second);
        }

        tokenExpiryTimeMap[tokenId] = currentTime + timeToLive;
    }

    void renew(string tokenId, int currentTime) {
        auto itr = tokenExpiryTimeMap.find(tokenId);

        if(itr != tokenExpiryTimeMap.end() && itr->second > currentTime) {
            expiryTimeSet.erase(itr->second);
            tokenExpiryTimeMap[tokenId] = currentTime + timeToLive;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        
    }
};

int main() {
    AuthenticationManager am(5);

    return 0;
}