#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <list>
using namespace std;

vector<int> bucketSort(vector<int>& v) {             // Using Linked Lists as buckets and STL quicksort for sorting the buckets
    int numBuckets = v.size();                       // We can use any number of buckets
    vector<list<int> > B(numBuckets);                // Creating a vector of lists to keep track of buckets
    double max = *max_element(v.begin(), v.end());   // Using a double as using ceil on division of ints has no effect
    double min = *min_element(v.begin(), v.end());   // Using min and max to estimate the range for the buckets/bins for bucket size
    int bucketSize = ceil((max - min)/numBuckets);   // The distance between max and min divided by num of buckets gives bucket size
    // int divider = ceil((max+1)/numBuckets);       // We can also use a divider based approach to calculate j-index

    for (int i = 0; i < v.size(); i++) {             // Iterating over the array to be sorted for sending elems to buckets
        int j = floor((v[i] - min)/bucketSize);      // Normalize v[i] to get j-index ie. the specific bucket to which elem is sent
        // int j = floor(v[i]/divider);              // Divider based approach calculates bucket num directly by dividing
        if (j < v.size())                            // IF is required in divider based approach or if max and min are ints
            B[j].push_back(v[i]);                    // Usually pushing element to bucket(list) at j-index in the vector of lists works
        else                                         // But j-index for max elems can go out of bounds (> numBuckets) if int is used
            B[numBuckets - 1].push_back(v[i]);       // So for max elem/out of bound elems, put it in the last bucket only
    }

    list<int> outList;                               // Create an output list without specifying size (else zeroes initialised)
    for (int j = 0; j < B.size(); j++) {             // Sort all buckets internally stored in the vector B
        B[j].sort();                                 // std::list::sort() is a Qsort based approach for sorting lists
        outList.insert(outList.end(), B[j].begin(), B[j].end());
    }                                                // Use list::insert() to add the sorted list to the end of outList

    vector<int> vc(outList.begin(), outList.end());  // Create a sorted vector from the sorted list - outList
    return vc;
}

int main() {
    // vector<int> x = {1, 1, 1, 1, 2, 2, 2, 2};
    vector<int> x = {17, 21, 29, 35, 4, 9, 25, 32};

    vector<int> v = bucketSort(x);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
