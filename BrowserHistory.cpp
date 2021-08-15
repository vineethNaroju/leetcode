#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
private:
    vector<string> history, future;

public:
    BrowserHistory(string _homepage) {
        history.push_back(_homepage);
    }

    void visit(string url) {
        history.push_back(url);
        future.clear();
    }

    string back(int steps) {
        while(steps > 0 && history.size() > 1) {
            future.push_back(history.back());
            history.pop_back();
            --steps;
        }
        return history.back();
    }

    string forward(int steps) {
        while(steps > 0 && future.size() > 0) {
            history.push_back(future.back());
            future.pop_back();
            --steps;
        }
        return history.back();
    }
};

int main() {
    return 0;
}