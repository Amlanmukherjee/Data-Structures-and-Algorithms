// create a temp array
// crawlers for both intervals and for temp
// traverse both arrays and in each iteration add smaller of both elements in temp 
// add elements left in the first interval 
// add elements left in the second interval 
// copy temp to original interval
// Arr is an array of integer type
// start and end are the starting and ending index of current interval of Arr

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &A, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid+1, k=0;
    while(i <= mid && j <= end) {
        if(A[i] < A[j]) {
            temp.push_back(A[i]);
            k++; i++;
        }
        else {
            temp.push_back(A[j]);
            k++; j++;
        }
    }

    while (i <= mid) {
        temp.push_back(A[i]);
        k++; i++;
    }

    while (j <= end) {
        temp.push_back(A[j]);
        k++; j++;
    }

    for(int i = start; i <= end; i++) {
        A[i] = temp[i - start];
    }
}

void mergeSort(vector<int> &A, int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
        mergeSort(A, start, mid);
        mergeSort(A, mid+1, end);
        merge(A, start, mid, end);
    }

}

int main() {
    vector<int> A;
    int n, a;
    cout << "Enter N: ";
    cin >> n;
    cout <<"Enter Array: ";
    for(int i=0; i<n; i++) {
        cin >> a;
        A.push_back(a);
    }

    mergeSort(A, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}