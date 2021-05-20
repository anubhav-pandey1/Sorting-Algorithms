#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2) { // Find a simpler merging algorithm code - found! mycodeschool
    int l1 = v1.size(), l2 = v2.size(); // Vector class destructor destroys it after it goes out of scope
    vector<int> r((l1 + l2), -1);
    int i = 0, j = 0, k = 0;

    while (i < l1 && j < l2) { // Can't use || here as it will remain true even if one evaluates to false
        if (v1[i] >= v2[j]) { // This is either O(l1) or O(l2). The corresponding while loop below would be O(l2) or O(l1) respectively
            r[k] = v2[j];    // Merge operation = O(l1 + l2) = O(N) for the merge sort array of size N (N = l1 + l2)
            j++;
        }
        else {
            r[k] = v1[i];
            i++;
        }
        k++;
    }

    while (j < l2) { // Can't use i == l1 here as its a while loop where i is not incremented -> infinite loop
        r[k] = v2[j]; // This is O(l2)
        j++;
        k++;
    }

    while (i < l1) { // This is O(l1)
        r[k] = v1[i];
        i++;
        k++;
    }

    return r;
}

vector<int> mergeSort(vector<int> v) {
    int len = v.size();
    if (len == 1) {
        return v;
    }
    else {
        vector<int> v1(len/2);
        vector<int> v2(len - (len/2));

        for (int i = 0; i < len; i++) { // Assigning subarrays in O(n)
            if (i < len/2) {
                v1[i] = v[i];
            }
            else {
                v2[i - (len/2)] = v[i];
            }
        }

        vector<int> ar1 = mergeSort(v1); // T(n/2)
        vector<int> ar2 = mergeSort(v2); // T(n/2)
        vector<int> r = merge(ar1, ar2); // O(n) or lets say C*n
        return r; // T(n) = 2T(n/2) + C*n => Merge sort is O(N*logN)
    }
}


int main() {
    vector<int> x = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> v = {17, 21, 29, 38, 4, 9, 25, 32};

    vector<int> merged = mergeSort(x);

    for (int i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    return 0;
}

// My initial merge algorithm - Instead of using a single while loop, it can be broken into 3 separate while loops for the 3 conditions

// vector<int> merge(vector<int> v1, vector<int> v2) {
//     int l1 = v1.size(), l2 = v2.size();
//     vector<int> r((l1 + l2), -1);
//     int i = 0, j = 0, k = 0;

//     while ((k < (l1 + l2))) { // Merge operation is O(n)
//         if (i < l1 && j < l2) {
//             if (v1[i] >= v2[j]) {
//                 r[k] = v2[j];
//                 j++;
//             }
//             else {
//                 r[k] = v1[i];
//                 i++;
//             }
//         }
//         else {
//             if (i == l1) {
//                 r[k] = v2[j];
//                 j++;
//             }
//             else if (j == l2) {
//                 r[k] = v1[i];
//                 i++;
//             }
//         }
//         k++;
//     }
//     return r;
// }
