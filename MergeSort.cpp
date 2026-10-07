#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &A, int p, int q, int r) {
    vector<int> temp;
    
    int i = p; 
    int j = q + 1;  
    
    while (i <= q && j <= r) { 
        if (A[i] <= A[j]) { 
            temp.push_back(A[i]);
            i++;
        } else {
            temp.push_back(A[j]);
            j++;
        }
    }

    
    while (i <= q) {
        temp.push_back(A[i]);
        i++;
    }

    while (j <= r) {
        temp.push_back(A[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        A[idx + p] = temp[idx]; // 'st' -> 'p'
    }
}

void mergeSort(vector<int> &A, int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2; // q = mid इंडेक्स

        mergeSort(A, p, q);
        
        mergeSort(A, q + 1, r);

        Merge(A, p, q, r);
    }
}

int main() {
    vector<int> A = {18, 6, 25, 3, 2, 1, 62, 50};

    cout << "Original Array: ";
    for (int val : A) {
        cout << val << " ";
    }
    cout << endl;

    mergeSort(A, 0, A.size() - 1);

    cout << "Sorted Array:   ";
    for (int val : A) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
