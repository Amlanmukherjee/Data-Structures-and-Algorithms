// Step 1 − Make any element as pivot
// Step 2 − Partition the array on the basis of pivot
// Step 3 − Apply quick sort on left partition recursively
// Step 4 − Apply quick sort on right partition recursively

#include <iostream>
#include <vector>

using namespace std;
/**
* The function selects the last element as pivot element, places that pivot element correctly in the array in such a way
* that all the elements to the left of the pivot are lesser than the pivot and
* all the elements to the right of pivot are greater than it.
* @Parameters: array, starting index and ending index
* @Returns: index of pivot element after placing it correctly in sorted array
*/

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &A, int start, int end) {
    int pivot = end;
    int index = start;
    int temp;
    for(int j=start; j<end; j++) {
        if(A[j] < A[pivot]) {
            swap(&A[index], &A[j]);
            index++;
        }
    }
    swap(&A[index], &A[pivot]);
    return index;
}

int quickSort(vector<int> &A, int start, int end) {
    int pivot_index;
    if(start < end) {
        pivot_index = partition(A, start, end);
        /***you will encounter SEGMENTATION FAULT if you miss the (-1) or (+1) here (in the recursive statements)***/
        quickSort(A, start, pivot_index-1);
        quickSort(A, pivot_index+1, end);
    }
    return 0; 
}

int main() {
    vector<int> A;
    int n, a;
    cout << "Enter N:";
    cin >> n;
    cout << "Enter array:";
    for(int i=0; i<n; i++) {
        cin >> a;
        A.push_back(a);
    }
    quickSort(A, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}