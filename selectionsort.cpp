#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& v) {                // Sends the min element in unsorted subarray to end of sorted subarray
    for (int i = 0; i < v.size() - 1; i++) {        // Iterate over the array (v.size() - 1) times (last index already sorted)
        int minIndex = i;                           // Set min index equal to the first index in the new unsorted subarray
        for (int j = i; j < v.size(); j++) {        // Start with the first elem in the unsorted subarray and go to the end
            if (v[j] < v[minIndex])                 // If any element is less than the current min elem in the unsorted subarray
                minIndex = j;                       // Update the min index to point to the new min element in the unsorted
        }                                           // Iteration over the unsorted subarray to find min element gets over
        iter_swap(v.begin()+minIndex, v.begin()+i); // Swap the current min element with the first element in unsorted subarray
    }                                               // Repeat this process (1 pass) once for all v.size() - 1 elements
}                                                   // One element gets sorted to correct position in each pass

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> v = {17, 21, 29, 35, 4, 9, 25, 32};

    selectionSort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
