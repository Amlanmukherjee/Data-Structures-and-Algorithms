#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int> &A, int n) {

    for(int i=1; i<n; i++) {
        int key = A[i];
        int j = i-1;
        while(j>=0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    return A;
}


int main() {
    vector<int> A;
    int n, a;
    cout <<"Enter N: ";
    cin >> n;
    cout << "Enter Array: ";
    for(int i=0; i<n; i++) {
        cin >> a;
        A.push_back(a);
    }
    InsertionSort(A, n);
    for(int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}