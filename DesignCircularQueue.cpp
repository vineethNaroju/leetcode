#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    private:
        int* circularQueue;
        int maxSize, currSize;
        int qstart = 0, qend = 0;
    public:
        CircularQueue(int _maxSize) {
            maxSize = _maxSize;
            circularQueue = new int[maxSize];
            currSize = 0;
        }

        bool enQueue(int val) {
            if(currSize == maxSize) return false;
            *(circularQueue + qend) =  val;
            ++currSize;
            qend = (qend + 1) % maxSize;
            return true;
        }

        bool deQueue() {
            if(currSize == 0) return false;
            qstart = (qstart + 1) % maxSize;
            --currSize;
            return true;
        }

        int Front() {
            if(currSize == 0) return -1;
            return *(circularQueue + qstart);
        }

        int Rear() {
            if(currSize == 0) return -1;
            return *(circularQueue + qend);
        }

        bool isEmpty() {
            if(currSize == 0) return true;
            return false;
        }

        bool isFull () {
            if(currSize == maxSize) return true;
            return false;
        }
};



int main() {
    return 0;
}