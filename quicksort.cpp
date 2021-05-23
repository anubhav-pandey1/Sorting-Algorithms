#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& v, int start, int end) {   // Semi-sorts the subarray around the pivot value such that elements to the
                                                      // left of pivot after partition are smaller and rightward elements are greater
    int piv = v[end];                                 // Defining the pivot to be the last of the subarray, can also be random
    int i = start, pIndex = start;                    // Defining a partition index to keep track of the place to finally swap with pivot
    while (i < end) {                                 // The last element (pivot) is the one being swapped with pIndex after loop ends
        if (v[i] < piv) {                             // Swap() doesnt work for swapping values, iter_swap() does
            iter_swap(v.begin()+i, v.begin()+pIndex); // Swap element at pIndex and i if v[i] is smaller than the pivot
            i++;                                      // Increase i to mark the next element being considered for comparison
            pIndex++;                                 // Increase pIndex to mark the next element being considered for swap
        }
        else {                                        // Otherwise if element at i is not less than the pivot value, i++
            i++;                                      // But pIndex remains same to mark that a "swap-worthy" element is not found
        }                                             // pIndex only changes when v[i] < piv value so pIndex <= i at any time
    }                                                 // Iterate till before the pivot, increase pIndex if v[i] < piv

    iter_swap(v.begin()+end, v.begin()+pIndex);       // After the loop ends, swap the pivot with the value at pIndex to get
    return pIndex;                                    // the pivot to its ideal place in the semi-sorted array
}                                                     // Now elements left of pIndex are smaller than piv and others are greater

void quickSort(vector<int>& v, int start, int end) {
    if (start >= end) {                               // Base case if size == 0 or size == 1
        return;                                       // No need to sort anything in base case
    }
    else {                                            // Otherwise, partition with the end as pivot and then sort left and right sides
        int idx = partition(v, start, end);           // Partition() returns the index of the pivot after partitioning is complete

        quickSort(v, start, idx - 1);                 // Recursive calls to sort the left side of the pivot from start to idx-1
        quickSort(v, idx + 1, end);                   // Recursive calls to sort the right side of the pivot from idx+1 to end
    }
}

int main() {
    vector<int> v = {29, 12, 12, 29, 12, 12, 29, 12};
    vector<int> x = {29, 17, 9, 4, 35, 35, 12, 21};

    quickSort(v, 0, v.size()-1);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

}

// My inplace implementation of quick sort - second implementation after initial faulty implementation

// void quickSort(vector<int>& v) {
//     if (v.size() < 2) {                            // Base case if size == 0 or size == 1
//         return;
//     }
//     else {
//         int piv = v[v.size() - 1];                 // Creating pivot
//         vector<int> left;
//         vector<int> right;

//         for (int i = 0; i < (v.size() - 1); i++) { // Creating left and right vectors
//             if (v[i] < piv)
//                 left.push_back(v[i]);
//             else
//                 right.push_back(v[i]);
//         }

//         quickSort(left);                           // Recursive calls to sort left and right vectors
//         quickSort(right);

//         left.push_back(piv);                       // Creating a merged sorted array
//         if (!right.empty()) {
//             for (int i = 0; i < right.size(); ++i) {
//                 left.push_back(right[i]);
//             }
//         }
//         v = left;
//     }
// }

// My initial implementation of quicksort - was not an inplace implementation

// vector<int> quickSort(vector<int> v) {
//     if (v.size() < 2) { // Base case if size == 0 or size == 1
//         return v;
//     }
//     else {
//         int piv = v[v.size() - 1]; // Creating pivot
//         vector<int> left;
//         vector<int> right;

//         for (int i = 0; i < (v.size() - 1); i++) { // Creating left and right vectors
//             if (v[i] < piv)
//                 left.push_back(v[i]);
//             else
//                 right.push_back(v[i]);
//         }

//         vector<int> sortedLeft = quickSort(left); // Recursive calls to sort left and right vectors
//         vector<int> sortedRight = quickSort(right);

//         sortedLeft.push_back(piv); // Creating a merged sorted array
//         if (!sortedRight.empty()) {
//             for (int i = 0; i < sortedRight.size(); ++i) {
//                 sortedLeft.push_back(sortedRight[i]);
//             }
//         }
//         return sortedLeft;
//     }
// }

// My initial (faulty) implementation of the partition function - works for start = 0, end = 7

// int partitionEnd(vector<int>& v, int start, int end) { // Partitions into left and right based on pivot and returns pivot index
//     int piv = v[end];
//     int num = end - start;
//     int i = 0, count = 0;
//     while (num--) {          // Insert-Erase logic can't work due to C++ insert limitation (only uses iterators to insert at end)
//         if (v[i] >= piv) {   // Does not work generally for (start, end) as at times start != 0 and then the index gets shifted
//             int temp = v[i];
//             v.erase(v.begin() + start + i);
//             if (end == v.size() - 1)
//                 v.push_back(temp);
//             else
//                 v.insert(v.begin() + end - 1, temp);
//             count++;
//         }
//         else {
//             i++;
//         }
//     }
//     // for (int i = 0; i < v.size(); i++) {
//     //     cout << v[i] << " ";
//     // }
//     // cout << endl;

//     return (end - count);
// }
