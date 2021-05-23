#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v) {                 // Using swaps to insert smallest element at the correct position
    for (int i = 1; i < v.size(); i++) {             // Iterate over N - 1 elements since first is already sorted
        int j = i;                                   // Go backwards starting from the current index i using j iterator
        while (v[j-1] > v[j] && j > 0) {             // While the previous elem is larger than the current elem..
            iter_swap(v.begin()+j, v.begin()+j-1);   // Keep swapping the previous elem with the current elem
            j--;                                     // Reduce j by 1 to go back 1 index and check again for the previous pair
        }                                            // Finish the required swaps for one particular elem (i) in the array
    }
}                                                    // Using binary search instead of linear search to find the correct place
                                                     // to insert the next element in the sorted subarray is even more optimal
int main() {                                         // This works on the sorted subarray as binary search needs sorting
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> v = {17, 21, 29, 35, 4, 9, 25, 32};

    insertionSort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
