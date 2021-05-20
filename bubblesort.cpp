#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {
    int flag = v.size() - 1;                                 // Var to check if no swaps were made during a particular pass
    while (flag) {                                           // Flag increases efficiency by stopping if no swaps during a pass
        for (int j = 0; j < v.size() - 1; j++) {             // Max no. of elements during a particular pass is v.size() - 1
            if (v[j] > v[j + 1]) {                           // Compare current elem and next elem and swap if current is bigger
                iter_swap(v.begin() + j, v.begin() + j + 1); // If a swap is made, flag remains same
            }
            else {                                           // Reduce flag if a swap is not made for a particular element
                flag--;
            }                                                // In general case, with each pass 1 element goes to correct pos
        }                                                    // But flag helps reduce time if array already semi-sorted
                                                             // Total no. of passes in general case is v.size() - 1
        if (flag)
            flag = v.size() - 1;                             // If flag not falsey, reset it to original value for the next pass
    }                                                        // Flag might turn falsey if no elem gets swapped due to flag--
}
                                                             // We can optimize further by running inner j loop (pass) only to
int main() {                                                 // v.size() - K - 1 where K = previous no. of passes
    vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};                // This is because in every pass, one elem bubbles to correct posn
    // vector<int> v = {17, 21, 29, 35, 4, 9, 25, 32};

    bubbleSort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
