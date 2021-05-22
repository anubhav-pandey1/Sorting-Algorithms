#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapSort(vector<int>& v) {
    priority_queue <int, vector<int>, greater<int> > pq(v.begin(), v.end()); // Create a minheap using STL priority_queue
    for (int i = 0; i < v.size(); i++) {                                     // Replace elements in original vector
        v[i] = pq.top();                                                     // Set v[i] = smallest element at top of min heap
        pq.pop();                                                            // Remove the smallest element, min heap rearranges
    }
}

int main() {
    // vector<int> x = {1, 1, 1, 1, 2, 2, 2, 2};
    // vector<int> x = {17, 21, 29, 35, 4, 9, 25, 32};
    vector<int> x = {173, 218, 296, 351, 42, 97, 256, 324};

    heapSort(x);

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}
