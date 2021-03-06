#include <iostream>
#include <vector>
using namespace std;

int knuthSeq(int num) {                                     // Function to return highest no. in Knuth Sequence for an array
    int h = 0;                                              // Takes array length as the input and gives the required K value
    while ((3*h + 1) < num)
        h = 3*h + 1;
    return h;
}

void shellSort(vector<int>& v) {                             // Makes passes from right to left, sorting spare subarrays with gap = K
    int K = knuthSeq(v.size() - 1);                          // K is the current gap. For K = 1, it is the same as insertion sort
    while (K > 0) {                                          // Gap must be positive - this loop iterates over Knuth Sequence
        for (int i = K; i < v.size(); i++) {                 // Start outer iteration from the index equal to gap and go forwards
                int j = i;                                   // Start the inner loop from the first index (i) and go backwards
                while (v[j-K] > v[j] && j > K-1) {           // While the current elem is smaller than the elem K units behind (pair)
                    iter_swap(v.begin()+j, v.begin()+j-K);   // Swap the two elems which are at a distance of K units, sorting them
                    j -= K;                                  // Reduce j-index by K units so that we can now check the prev. pair
                }                                            // Finish the required swaps for one sparse subarray with K unit gap
            }                                                // Finish the required swaps for all sparse subarrays with K-unit gap
        K = (K-1)/3;                                         // Reduce K to become the prev. no. in Knuth Sequence and sort subarrays
    }                                                        // Finish shell sort for all nos. in the Knuth Sequence
}

// Note - The back to back swapping of a small element towards the end covers the sorting of an entire subarray
// This happens only when a small element is found in the end, otherwise there is no need to identify and check subarrays
// Since we are starting from j = i = K and going backwards, the first few subarrays will have fewer elements than max
// As j approaches (len - K), the sorting passes will start covering entire subarrays instead of doing it at the start
// You can imagine the shell sort to be taking place from the right end covering all the subarrays in such a way that
// when it approaches the left end, the subarrays have fewer elements than the larger subarrays created in the right

int main() {
    // vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> v = {17, 21, 29, 35, 4, 9, 25, 32};

    shellSort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

// Insertion sort algorithm - For comparing with Shell Sort with K = 1

void insertionSort(vector<int>& v) {
    for (int i = 1; i < v.size(); i++) {             // Iterate over N - 1 elements since first is already sorted
        int j = i;                                   // Go backwards starting from the current index i using j iterator
        while (v[j-1] > v[j] && j > 0) {             // While the previous elem is larger than the current elem
            iter_swap(v.begin()+j, v.begin()+j-1);   // Keep swapping the previous elem with the current elem
            j--;                                     // Reduce j by 1 to go back 1 index
        }                                            // Finish the required swaps for one particular elem (i) in the array
    }
}
