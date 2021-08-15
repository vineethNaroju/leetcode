#include <bits/stdc++.h>
using namespace std;

struct Node {
    int start, end;
    Node *left;
    Node *right;

    Node() {
        left = nullptr;
        right = nullptr;
    }
};

class MyCalendar {
public:
    Node *root;
    MyCalendar() {
        root = nullptr;
    }

    bool book(int start, int end) {

        if(root == nullptr) {
            root = new Node();
            root->start = start;
            root->end = end;
            return true;
        }

        Node *curr = root;

        while(true) {
            
        }
    }
};

int main() {
    return 0;
}
