#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& v, int start, int end) {
    int piv = v[end];                                     // Defining the pivot to be the last of the subarray
    int i = start, pIndex = start;                        // Defining a partition index to keep track of the swap
    while (i < end) {                                     // The last element is the one being swapped with pIndex
        if (v[i] < piv) {
            iter_swap(v.begin() + i, v.begin() + pIndex); // Swap doesnt work for swapping values, iter swap does
            i++;
            pIndex++;
        }
        else {
            i++;
        }
    }
    iter_swap(v.begin() + end, v.begin() + pIndex);
    return pIndex;
}

void quickSort(vector<int>& v, int start, int end) {
    if (start >= end) { // Base case if size == 0 or size == 1
        return;
    }
    else {
        int idx = partition(v, start, end); // Index of the pivot
            quickSort(v, idx + 1, end);
        // if (idx > 0 && idx < (v.size() - 1))
            quickSort(v, start, idx - 1); // Recursive calls to sort the left side of the pivot

        // if(idx < (v.size() - 1))
             // Recursive calls to sort the right side of the pivot
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
//     if (v.size() < 2) { // Base case if size == 0 or size == 1
//         return;
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

//         quickSort(left); // Recursive calls to sort left and right vectors
//         quickSort(right);

//         left.push_back(piv); // Creating a merged sorted array
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
//     while (num--) { // Insert-Erase logic can't work due to C++ insert limitation (only uses iterators to insert at end)
//         if (v[i] >= piv) { // Does not work for start, end as start != 0 at times and then the index gets shifted
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
