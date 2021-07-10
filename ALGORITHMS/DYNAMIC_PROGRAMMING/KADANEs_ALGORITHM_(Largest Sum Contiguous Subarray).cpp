#include <iostream>
#include <climits>
using namespace std;

int main() {
    int number_of_elements;
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    int temporary_start = 0, start = 0, end = 0;

    cout << "ENTER NO. OF ELEMENTS: ";
    cin >> number_of_elements;

    int array[number_of_elements];
    
    cout << "ENTER ELEMENTS OF ARRAY: ";
    for(int i=0; i<number_of_elements; i++) {
        cin >> array[i];
    }

    for(int i=0; i<number_of_elements; i++) {
        max_ending_here += array[i];
        if(max_so_far < max_ending_here) {
            max_so_far = max_ending_here;
            start = temporary_start;
            end = i;
        }
        //
        if(max_ending_here < 0) {
            max_ending_here = 0;
            temporary_start = i+1;
        }
    }

    cout << "LARGEST POSSIBLE SUM IS: " << max_so_far << endl;
    cout << "STARTING INDEX OF SUB-ARRAY: "<< start << endl;
    cout << "ENDING INDEX OF SUB-ARRAY: "<< end << endl;
    cout << "THE SUB-ARRAY: ";
    for(int i=start; i<=end; i++) {
        cout << array[i] << " ";
    }
    

    return 0;
}