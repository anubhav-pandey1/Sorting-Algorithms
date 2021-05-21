#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countingSort(vector<int>& v) {
    int K = *max_element(v.begin(), v.end());   // Alternatively, we can iterate over the array to find the max
    vector<int> index(K+1, 0);                  // Creating an empty array with indices 0 to K, initialised with zeroes

    for (int i = 0; i < v.size(); i++)          // Counting the no. of occurences of elements in input vector v
        index[v[i]]++;

    for (int i = 1; i < index.size(); i++)      // Creating a cumulative running sum array with sum of previous
        index[i] += index[i-1];                 // index[i-1] contains cumulative sum still index i-1
                                                // So adding index[i-1] to index[i] gives cumulative sum till i

    vector<int> output(v.size(), 0);            // Creating an output array of size equal to the input array size
    for (int i = v.size()-1; i>=0; i--) {       // Iterating backwards over initial array for stable implementation
        output[index[v[i]]-1] = v[i];           // Reduce 1 from index value to get 0-based index and set equal to v[i]
        index[v[i]]--;                          // Reduce index value stored in index array by 1 for the next duplicate
    }                                           // so that the next duplicate is stored one element before
    return output;
}

// Note - Index array stores the highest value of the index for the particular element by taking a sum of no. of occurences
// of all the smaller elements. Reducing the index by 1 after populating the output array guarantees that a duplicate will
// get placed at an index just before the previous element (which was placed at the highest possible value of the index)

// Counting sort works by getting a sorted array of the number of occurences of all the elements. This sorted array is then
// used to obtain the indices of the values in the final output array by calculating cumulative running sums. Cumulative
// running sums tell us how many elements of a smaller value can occur before this particular element in the output array.

int main() {
    // vector<int> x = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> x = {17, 21, 29, 35, 4, 9, 25, 32};

    vector<int> v = countingSort(x);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
