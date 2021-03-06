#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& v) {                            // Makes passes on array and swaps elements if one smaller than other
    int flag = v.size() - 1;                                 // Var to check if no swaps were made during a particular pass
    while (flag) {                                           // Flag increases efficiency by stopping if no swaps during a pass
        for (int j = 0; j < v.size() - 1; j++) {             // Max no. of elements during a particular pass is v.size() - 1
            if (v[j] > v[j + 1]) {                           // Compare current elem and next elem and swap if current is bigger
                iter_swap(v.begin() + j, v.begin() + j + 1); // If a swap is made, flag remains same and is not reduced
            }
            else {                                           // Reduce flag if a swap is not made for a particular element
                flag--;                                      // In general case, with each pass 1 element goes to correct position
            }                                                // But flag helps reduce time if array already semi-sorted
        }                                                    // Total no. of passes in general case is v.size() - 1

        if (flag)                                            // If flag not falsey, reset it to original value for the next pass
            flag = v.size() - 1;                             // Flag might turn falsey if no elem gets swapped in a pass due to flag--
    }
}                                                            // We can optimize further by running inner j loop (pass) only to
                                                             // v.size() - K - 1 where K = previous no. of passes
int main() {                                                 // This is because in every pass, one elem bubbles to correct position
    vector<int> v = {1, 1, 1, 1, 2, 2, 2, 2};
    // vector<int> v = {17, 21, 29, 35, 4, 9, 25, 32};

    bubbleSort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
