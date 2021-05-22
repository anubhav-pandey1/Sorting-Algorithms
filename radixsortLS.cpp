#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

                                                           // Counting sort is implemented with place to sort based on a particular digit
void countingSort(vector<int>& v, int place) {             // Counting sort is used to sort the digits of nos. in Radix Sort
    const int K = 9;                                       // Since max digit is 9, K = 9 for such counting sort
    vector<int> occurence(K+1, 0);                         // Creating an empty array with indices 0 to 9, initialised with zeroes

    for (int i = 0; i < v.size(); i++) {                   // Counting the no. of occurences of the digits in the input vector v
        int digit = (v[i]/place) % 10;                     // (v[i]/place) % 10 gives the digit at the particular place
        occurence[digit]++;                                // We then increase the value of occurence of that digit by 1
    }

    for (int i = 1; i < occurence.size(); i++)             // Creating a cumulative running sum array with sum of previous occurences
        occurence[i] += occurence[i-1];                    // occurence[i-1] contains cumulative sums till index i-1
                                                           // So adding occurence[i-1] to occurence[i] gives cumulative sum till i

    vector<int> output(v.size(), 0);                       // Creating an output array of size equal to the input array size
    for (int i = v.size()-1; i>=0; i--) {                  // Iterating backwards over initial array for stable implementation
        int digit = (v[i]/place) % 10;                     // Store v[i] at index given by occurence[digit] for the particular digit
        output[occurence[digit]-1] = v[i];                 // Reduce 1 from occurence value to get 0-based index and set equal to v[i]
        occurence[digit]--;                                // Reduce occurence value stored in occurence array by 1 for the digit so that
    }                                                      // so that the next duplicate is stored one index before in the output
    v = output;                                            // Linkage problem of transferring sorting changes from digits arr->original arr
}                                                          // solved by using occurences to find final index of the no. in the output array
                                                           // Counting Sort is stable so duplicate digits are also managed as they have same
                                                           // order of position as in the original array so they can be distinguished
                                                           // The prefix sum along with starting from the last provides stability as well as
                                                           // solves the linkage problem by maintaining order and indices

void radixSortLS(vector<int>& v) {                         // Radix Sort implemented with least significant digit
    int max = *max_element(v.begin(), v.end());            // Finding the max element in the vector for the max no. of digits

    for (int place = 1; max/place > 0; place *= 10)        // Counting Sort on numbers at 1's place then 10's place then 100's ...
        countingSort(v, place);                            // while no. of places doesnt exceed max value
}                                                          // The max no. of digits is the no. of iterations with counting sort


int main() {
    // vector<int> x = {1, 1, 1, 1, 2, 2, 2, 2};
    // vector<int> x = {17, 21, 29, 35, 4, 9, 25, 32};
    vector<int> x = {173, 218, 296, 351, 42, 97, 256, 324};

    radixSortLS(x);

    for (int i = 0; i < x.size(); i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}

// My initial inefficient implementation of the Radix Sort - O(n^2)

// vector<int> radixSort(vector<int>& v) {
//     int max = *max_element(v.begin(), v.end());
//     int d = (int)(log10(max) + 1);
//     vector<int> r(v.begin(), v.end());                      // Use the above counting sort but without the places and digits
//     vector<int> temp(v.size()), sortD(v.size()), indices(v.size());

//     for (int i = 1; i <= d; i++) {                          // Inefficient O(n^2) book-keeping using indices but can be used elsewhere
//         for (int j = 0; j < r.size(); j++)
//             temp[j] = (r[j] % myPow(10,i))/myPow(10, i-1);  // Finding the least significant digits for the input vector and storing them in a temp vector

//         sortD = countingSort(temp);                         // Sorting the temp vector with the LSD and storing them in a new vector
//                                                             // Temp shares indices with the r vector but sortD does not
//         for (int j = 0; j < temp.size(); j++) {             // Finding and storing the indices shifted after sorting in the sortD of the original digits in temp vector
//             indices[j] = find(temp.begin(), temp.end(), sortD[j]) - temp.begin(); // This is O(n) and the loop makes it O(n^2)
//             temp[indices[j]] = INT_MAX-1;                   // Setting the value of the once-found digit to be INT_MAX so that the next duplicate has a unique occurence
//         }
//         vector<int> copied(r.begin(), r.end());             // Creating a copy of the input R vector so that it can be transformed in the upcoming loop
//         for (int j = 0; j < indices.size(); j++) {          // Transforming R with the original number at the sorted index
//             r[j] = copied[indices[j]];                      // R will then again be used for i = 2, i = 3 with the next set of significant digits
//         }
//     }
//     return r;
// }

// int myPow(int x, unsigned int p)                // C++ pow() doesnt work well for integers, only for doubles
// {                                               // myPow() is a recursive exponentiation function for integers
//     if (p == 0)                                 // This will be used with 10^i to find the least significant digits
//         return 1;
//     if (p == 1)
//         return x;

//     int tmp = myPow(x, p/2);
//     if (p%2 == 0)
//         return tmp * tmp;
//     else
//         return x * tmp * tmp;
// }
