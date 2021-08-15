#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    int maxKeyCount;
    list<int> recentlyUsedkeyDLL;
    unordered_map<int, int> lruMap;
    unordered_map<int, list<int>::iterator> keyPosDLLMap;

    void updateRecentlyUsedkey(int key) {
        auto itr = keyPosDLLMap.find(key);

        if(itr != keyPosDLLMap.end()) {
            recentlyUsedkeyDLL.erase(itr->second);
        }

        recentlyUsedkeyDLL.push_front(key);

        keyPosDLLMap[key] = recentlyUsedkeyDLL.begin();
    }

    void removeLeastRecentlyUsedKey() {
        int oldKey = recentlyUsedkeyDLL.back();
        recentlyUsedkeyDLL.pop_back();
        lruMap.erase(oldKey);
        keyPosDLLMap.erase(oldKey);
    }

    bool isFull() {
        return lruMap.size() == maxKeyCount;
    }

public:
    LRUCache(int _maxKeyCount) {
        maxKeyCount = _maxKeyCount;
        lruMap.clear();
        keyPosDLLMap.clear();
    }

    int get(int key) {
        // cout << "get " << key << " :\n";
        unordered_map<int, int>::iterator itr;

        itr = lruMap.find(key);

        if(itr == lruMap.end()) {
            return -1;
        }

        updateRecentlyUsedkey(key);

        return itr->second;
    }

    void put(int key, int value) {
        // cout << "put " << key << " : " << value << '\n';
        unordered_map<int, int>::iterator itr;

        itr = lruMap.find(key);

        if(isFull() && itr == lruMap.end()) {
            cout << "full\n";
            removeLeastRecentlyUsedKey();
        }

        updateRecentlyUsedkey(key);

        lruMap[key] = value;

        // cout << "lruMap " << key << " : " << value << '\n';
    }
};

int main() {
    LRUCache mp(2);

    cout << mp.get(2) << '\n';
    mp.put(2, 6);
    cout << mp.get(1) << '\n';
    mp.put(1, 5);
    mp.put(1, 2);
    cout << mp.get(1) << '\n';
    cout << mp.get(2) << '\n';

    return 0;
}